/*
 * Copyright 2023 Linux Studio Plugins Project <lsp.plugin@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _3RDPARTY_STEINBERG_VST3_BASE_SMARTPOINTER_H_
#define _3RDPARTY_STEINBERG_VST3_BASE_SMARTPOINTER_H_

#include <steinberg/vst3/base/fplatform.h>

#if SMTG_CPP11_STDLIBSUPPORT
    #include <utility>
#endif

namespace Steinberg
{
    /**
     * Smart pointer template class
     * @tparam I the underlying data type handled by the smart pointer
     *
     * @example
     *   IPtr<IPath> path (sharedPath);
     *   if (path)
     *      path->ascend();
     */
    template <class I>
    class IPtr
    {
        public:
            inline IPtr (I* ptr, bool addRef = true);
            inline IPtr (const IPtr&);

            template <class T>
            inline IPtr (const IPtr<T>& other) : ptr (other.get ())
            {
                if (ptr)
                    ptr->addRef();
            }

            inline IPtr ();
            inline ~IPtr ();

            inline I* operator= (I* ptr);

            inline IPtr& operator= (const IPtr& other);

            template <class T>
            inline IPtr& operator= (const IPtr<T>& other)
            {
                operator= (other.get ());
                return *this;
            }

            inline operator I* () const { return ptr; } // act as I*
            inline I* operator-> () const { return ptr; } // act as I*

            inline I* get() const { return ptr; }

        #if SMTG_CPP11_STDLIBSUPPORT
            inline IPtr(IPtr<I>&& movePtr) SMTG_NOEXCEPT : ptr (movePtr.take ()) { }

            template <typename T>
            inline IPtr(IPtr<T>&& movePtr) SMTG_NOEXCEPT : ptr (movePtr.take ()) {  }

            inline IPtr& operator= (IPtr<I>&& movePtr) SMTG_NOEXCEPT
            {
                if (ptr)
                    ptr->release ();

                ptr = movePtr.take ();
                return *this;
            }

            template <typename T>
            inline IPtr& operator= (IPtr<T>&& movePtr)
            {
                if (ptr)
                    ptr->release ();

                ptr = movePtr.take ();
                return *this;
            }
        #endif

            inline void reset(I* obj = nullptr)
            {
                if (ptr)
                    ptr->release();
                ptr = obj;
            }

            I* take() SMTG_NOEXCEPT
            {
                I* out = ptr;
                ptr = nullptr;
                return out;
            }

            template <typename T>
            static IPtr<T> adopt(T* obj) SMTG_NOEXCEPT { return IPtr<T> (obj, false); }

        protected:
            I* ptr;
    };

    template <class I>
    inline IPtr<I>::IPtr(I* _ptr, bool addRef) : ptr (_ptr)
    {
        if (ptr && addRef)
            ptr->addRef();
    }

    template <class I>
    inline IPtr<I>::IPtr(const IPtr<I>& other) : ptr (other.ptr)
    {
        if (ptr)
            ptr->addRef();
    }

    template <class I>
    inline IPtr<I>::IPtr() : ptr (nullptr)
    {
    }

    template <class I>
    inline IPtr<I>::~IPtr()
    {
        if (ptr)
        {
            ptr->release();
            ptr = nullptr;  //TODO_CORE: how much does this cost? is this something hiding for us?
        }
    }

    template <class I>
    inline I* IPtr<I>::operator= (I* _ptr)
    {
        if (_ptr != ptr)
        {
            if (ptr)
                ptr->release();
            ptr = _ptr;
            if (ptr)
                ptr->addRef();
        }
        return ptr;
    }

    template <class I>
    inline IPtr<I>& IPtr<I>::operator= (const IPtr<I>& _ptr)
    {
        operator= (_ptr.ptr);
        return *this;
    }

    /**
     * "owning" smart pointer used for newly created FObjects.
     * @note FUnknown implementations are supposed to have a refCount of 1 right after creation.
     * So using an IPtr on newly created objects would lead to a leak.
     * Instead the OPtr can be used in this case.
     *
     * @tparam I the underlying data type handled by the smart pointer
     *
     * @example
     *   OPtr<IPath> path = FHostCreate (IPath, hostClasses);
     *   // no release is needed...
     *
     * @example The assignment operator takes ownership of a new object and releases the old.
     * So its safe to write:
     *   OPtr<IPath> path = FHostCreate (IPath, hostClasses);
     *   path = FHostCreate (IPath, hostClasses);
     *   path = nullptr;
     *
     * @example of memory leak (DO NOT DO THIS):
     *   IPtr<IPath> path (FHostCreate (IPath, hostClasses), false);
     *   path = FHostCreate (IPath, hostClasses);
     *   path = nullptr;
     */
    template <class I>
    class OPtr : public IPtr<I>
    {
    public:
        inline OPtr(I* p) : IPtr<I> (p, false) {}
        inline OPtr(const IPtr<I>& p) : IPtr<I> (p) {}
        inline OPtr(const OPtr<I>& p) : IPtr<I> (p) {}
        inline OPtr() {}
        inline I* operator= (I* _ptr)
        {
            if (_ptr != this->ptr)
            {
                if (this->ptr)
                    this->ptr->release ();
                this->ptr = _ptr;
            }
            return this->ptr;
        }
    };

    //------------------------------------------------------------------------
    /** Assigning newly created object to an IPtr.
     Example:
     \code
     IPtr<IPath> path = owned (FHostCreate (IPath, hostClasses));
     \endcode
     which is a slightly shorter form of writing:
     \code
     IPtr<IPath> path = OPtr<IPath> (FHostCreate (IPath, hostClasses));
     \endcode
     */
    template <class I>
    IPtr<I> owned (I* p)
    {
        return IPtr<I> (p, false);
    }

    /** Assigning shared object to an IPtr.
     Example:
     \code
     IPtr<IPath> path = shared (iface.getXY ());
     \endcode
     */
    template <class I>
    IPtr<I> shared (I* p)
    {
        return IPtr<I> (p, true);
    }

#if SMTG_CPP11_STDLIBSUPPORT

    // Ownership functionality
    namespace SKI
    {
        namespace Detail
        {
            struct Adopt;
        } /* namespace Detail */

        /** Strong typedef for shared reference counted objects.
          *	Use SKI::adopt to unwrap the provided object.
          * @tparam T Referenced counted type.
          */
        template <typename T>
        class Shared
        {
            friend struct Detail::Adopt;
            T* obj = nullptr;
        };

        /** Strong typedef for transferring the ownership of reference counted objects.
          *	Use SKI::adopt to unwrap the provided object.
          * After calling adopt the reference in this object is null.
          * @tparam T Referenced counted type.
          */
        template <typename T>
        class Owned
        {
            friend struct Detail::Adopt;
            T* obj = nullptr;
        };

        /** Strong typedef for using reference counted objects.
          *	Use SKI::adopt to unwrap the provided object.
          * After calling adopt the reference in this object is null.
          * @tparam T Referenced counted type.
          */
        template <typename T>
        class Used
        {
            friend struct Detail::Adopt;
            T* obj = nullptr;
        };

        namespace Detail
        {

            struct Adopt
            {
                template <typename T>
                static IPtr<T> adopt (Shared<T>& ref)
                {
                    using Steinberg::shared;
                    return shared (ref.obj);
                }

                template <typename T>
                static IPtr<T> adopt (Owned<T>& ref)
                {
                    using Steinberg::owned;
                    IPtr<T> out = owned (ref.obj);
                    ref.obj = nullptr;
                    return out;
                }

                template <typename T>
                static T* adopt (Used<T>& ref)
                {
                    return ref.obj;
                }

                template <template <typename> class OwnerType, typename T>
                static OwnerType<T> toOwnerType (T* obj)
                {
                    OwnerType<T> out;
                    out.obj = obj;
                    return out;
                }
            };

        } /* namespace Detail */

        /** Common function to adopt referenced counted object.
          *	@tparam T			Referenced counted type.
          * @param ref			The reference to be adopted in a smart pointer.
          */
        template <typename T>
        IPtr<T> adopt (Shared<T>& ref) { return Detail::Adopt::adopt (ref); }

        template <typename T>
        IPtr<T> adopt (Shared<T>&& ref) { return Detail::Adopt::adopt (ref); }

        /** Common function to adopt referenced counted object.
          *	@tparam T			Referenced counted type.
          * @param ref			The reference to be adopted in a smart pointer.
          */
        template <typename T>
        IPtr<T> adopt (Owned<T>& ref) { return Detail::Adopt::adopt (ref); }

        template <typename T>
        IPtr<T> adopt (Owned<T>&& ref) { return Detail::Adopt::adopt (ref); }

        /** Common function to adopt referenced counted object.
          *	@tparam T			Referenced counted type.
          * @param ref			The reference to be adopted in a smart pointer.
          */
        template <typename T>
        T* adopt (Used<T>& ref) { return Detail::Adopt::adopt (ref); }

        template <typename T>
        T* adopt (Used<T>&& ref) { return Detail::Adopt::adopt (ref); }

        /** Common function to wrap owned instances. */
        template <typename T>
        Owned<T> toOwned (T* obj) { return Detail::Adopt::toOwnerType<Owned> (obj); }

        /** Common function to wrap shared instances. */
        template <typename T>
        Shared<T> toShared (T* obj) { return Detail::Adopt::toOwnerType<Shared> (obj); }

        /** Common function to wrap used instances. */
        template <typename T>
        Used<T> toUsed (T* obj) { return Detail::Adopt::toOwnerType<Used> (obj); }

    } /* namespace SKI */

#endif /* SMTG_CPP11_STDLIBSUPPORT */

} /* namespace Steinberg */

#endif /* _3RDPARTY_STEINBERG_VST3_BASE_SMARTPOINTER_H_ */
