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

#ifndef _3RDPARTY_INCLUDE_STEINBERG_VST3_BASE_IPTR_H_
#define _3RDPARTY_INCLUDE_STEINBERG_VST3_BASE_IPTR_H_

#include <steinberg/vst3/base/Platform.h>

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
     * Assigning newly created object to an IPtr.
     * @example
     *   IPtr<IPath> path = owned (FHostCreate (IPath, hostClasses));
     *
     * which is a slightly shorter form of writing:
     * @example
     *   IPtr<IPath> path = OPtr<IPath> (FHostCreate (IPath, hostClasses));
     */
    template <class I>
    IPtr<I> owned (I* p)
    {
        return IPtr<I>(p, false);
    }

    /**
     * Assigning shared object to an IPtr.
     * @example
     *   IPtr<IPath> path = shared(iface.getXY());
     */
    template <class I>
    IPtr<I> shared (I* p)
    {
        return IPtr<I> (p, true);
    }

} /* namespace Steinberg */

#endif /* _3RDPARTY_INCLUDE_STEINBERG_VST3_BASE_IPTR_H_ */
