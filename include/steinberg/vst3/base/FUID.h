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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_FUID_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_FUID_H_

#include <steinberg/vst3/base/IPtr.h>
#include <steinberg/vst3/base/Platform.h>
#include <steinberg/vst3/base/Types.h>
#include <cstring>

#if SMTG_CPP11_STDLIBSUPPORT
    #include <type_traits>
#endif /* SMTG_CPP11_STDLIBSUPPORT */

//------------------------------------------------------------------------
//  Unique Identifier macros
//------------------------------------------------------------------------

#if COM_COMPATIBLE
    #define INLINE_UID(l1, l2, l3, l4) \
    { \
        (::Steinberg::int8)(((::Steinberg::uint32)(l1) & 0x000000FF)      ), (::Steinberg::int8)(((::Steinberg::uint32)(l1) & 0x0000FF00) >>  8), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l1) & 0x00FF0000) >> 16), (::Steinberg::int8)(((::Steinberg::uint32)(l1) & 0xFF000000) >> 24), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l2) & 0x00FF0000) >> 16), (::Steinberg::int8)(((::Steinberg::uint32)(l2) & 0xFF000000) >> 24), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l2) & 0x000000FF)      ), (::Steinberg::int8)(((::Steinberg::uint32)(l2) & 0x0000FF00) >>  8), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l3) & 0xFF000000) >> 24), (::Steinberg::int8)(((::Steinberg::uint32)(l3) & 0x00FF0000) >> 16), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l3) & 0x0000FF00) >>  8), (::Steinberg::int8)(((::Steinberg::uint32)(l3) & 0x000000FF)      ), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l4) & 0xFF000000) >> 24), (::Steinberg::int8)(((::Steinberg::uint32)(l4) & 0x00FF0000) >> 16), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l4) & 0x0000FF00) >>  8), (::Steinberg::int8)(((::Steinberg::uint32)(l4) & 0x000000FF)      )  \
    }
#else
    #define INLINE_UID(l1, l2, l3, l4) \
    { \
        (::Steinberg::int8)(((::Steinberg::uint32)(l1) & 0xFF000000) >> 24), (::Steinberg::int8)(((::Steinberg::uint32)(l1) & 0x00FF0000) >> 16), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l1) & 0x0000FF00) >>  8), (::Steinberg::int8)(((::Steinberg::uint32)(l1) & 0x000000FF)      ), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l2) & 0xFF000000) >> 24), (::Steinberg::int8)(((::Steinberg::uint32)(l2) & 0x00FF0000) >> 16), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l2) & 0x0000FF00) >>  8), (::Steinberg::int8)(((::Steinberg::uint32)(l2) & 0x000000FF)      ), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l3) & 0xFF000000) >> 24), (::Steinberg::int8)(((::Steinberg::uint32)(l3) & 0x00FF0000) >> 16), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l3) & 0x0000FF00) >>  8), (::Steinberg::int8)(((::Steinberg::uint32)(l3) & 0x000000FF)      ), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l4) & 0xFF000000) >> 24), (::Steinberg::int8)(((::Steinberg::uint32)(l4) & 0x00FF0000) >> 16), \
        (::Steinberg::int8)(((::Steinberg::uint32)(l4) & 0x0000FF00) >>  8), (::Steinberg::int8)(((::Steinberg::uint32)(l4) & 0x000000FF)      )  \
    }
#endif

//------------------------------------------------------------------------
#define DECLARE_UID(name, l1, l2, l3, l4) SMTG_CONSTEXPR14 ::Steinberg::TUID name = INLINE_UID (l1, l2, l3, l4);

//------------------------------------------------------------------------
#define EXTERN_UID(name) extern const ::Steinberg::TUID name;

#ifdef INIT_CLASS_IID
    #define DECLARE_CLASS_IID(ClassName, l1, l2, l3, l4)                                               \
        static SMTG_CONSTEXPR14 const ::Steinberg::TUID ClassName##_iid = INLINE_UID (l1, l2, l3, l4); \
        const ::Steinberg::FUID ClassName::iid (ClassName##_iid);
#else
    #define DECLARE_CLASS_IID(ClassName, l1, l2, l3, l4) \
        static SMTG_CONSTEXPR14 const ::Steinberg::TUID ClassName##_iid = INLINE_UID (l1, l2, l3, l4);
#endif

#define DEF_CLASS_IID(ClassName) const ::Steinberg::FUID ClassName::iid (ClassName##_iid);

#define INLINE_UID_OF(ClassName) ClassName##_iid

#define INLINE_UID_FROM_FUID(x) \
    INLINE_UID (x.getLong1 (), x.getLong2 (), x.getLong3 (), x.getLong4 ())

//------------------------------------------------------------------------
//  Result Codes
//------------------------------------------------------------------------
namespace Steinberg
{

    //------------------------------------------------------------------------
    #if COM_COMPATIBLE
        #if SMTG_OS_WINDOWS
            enum
            {
                kNoInterface        = static_cast<tresult>(0x80004002L),    // E_NOINTERFACE
                kResultOk           = static_cast<tresult>(0x00000000L),    // S_OK
                kResultTrue         = kResultOk,
                kResultFalse        = static_cast<tresult>(0x00000001L),    // S_FALSE
                kInvalidArgument    = static_cast<tresult>(0x80070057L),    // E_INVALIDARG
                kNotImplemented     = static_cast<tresult>(0x80004001L),    // E_NOTIMPL
                kInternalError      = static_cast<tresult>(0x80004005L),    // E_FAIL
                kNotInitialized     = static_cast<tresult>(0x8000FFFFL),    // E_UNEXPECTED
                kOutOfMemory        = static_cast<tresult>(0x8007000EL)     // E_OUTOFMEMORY
            };
        #else
            enum
            {
                kNoInterface        = static_cast<tresult>(0x80000004L),    // E_NOINTERFACE
                kResultOk           = static_cast<tresult>(0x00000000L),    // S_OK
                kResultTrue         = kResultOk,
                kResultFalse        = static_cast<tresult>(0x00000001L),    // S_FALSE
                kInvalidArgument    = static_cast<tresult>(0x80000003L),    // E_INVALIDARG
                kNotImplemented     = static_cast<tresult>(0x80000001L),    // E_NOTIMPL
                kInternalError      = static_cast<tresult>(0x80000008L),    // E_FAIL
                kNotInitialized     = static_cast<tresult>(0x8000FFFFL),    // E_UNEXPECTED
                kOutOfMemory        = static_cast<tresult>(0x80000002L)     // E_OUTOFMEMORY
            };
        #endif /* SMTG_OS_WINDOWS */
    #else
        enum
        {
            kNoInterface = -1,
            kResultOk,
            kResultTrue = kResultOk,
            kResultFalse,
            kInvalidArgument,
            kNotImplemented,
            kInternalError,
            kNotInitialized,
            kOutOfMemory
        };
    #endif

    /**
     * Plain UID type
     */
    typedef char TUID[16];

    #if SMTG_CPP14
        inline SMTG_CONSTEXPR14 void copyTUID (char* dst, const char* src)
        {
            for (auto i = 0; i < 16; ++i)
                dst[i] = src[i];
        }
    #endif

    SMTG_ALWAYS_INLINE bool iidEqual(const void* iid1, const void* iid2)
    {
        const uint64* p1 = reinterpret_cast<const uint64*> (iid1);
        const uint64* p2 = reinterpret_cast<const uint64*> (iid2);
        return p1[0] == p2[0] && p1[1] == p2[1];
    }

    /**
     * Handling 16 Byte Globally Unique Identifiers.
     * Each interface declares its identifier as static member inside the interface
     * namespace (e.g. FUnknown::iid).
     */
    class FUID
    {
        public:
            FUID ();
            FUID (uint32 l1, uint32 l2, uint32 l3, uint32 l4);
            FUID (const FUID&);
            virtual ~FUID () {}

        #if SMTG_CPP11_STDLIBSUPPORT
            FUID (FUID&& other);
            FUID& operator= (FUID&& other);
        #endif

            /** Generates a new Unique Identifier (UID).
                Will return true for success. If the return value is false, either no
                UID is generated or the UID is not guaranteed to be unique worldwide. */
            bool generate ();

            /** Checks if the UID data is valid.
                The default constructor initializes the memory with zeros. */
            bool isValid () const;

            FUID& operator = (const FUID& f);
            bool operator == (const FUID& f) const { return ::Steinberg::iidEqual (data, f.data); }
            bool operator < (const FUID& f) const { return memcmp (data, f.data, sizeof (TUID)) < 0; }
            bool operator != (const FUID& f) const   { return !::Steinberg::iidEqual (data, f.data); }

            uint32 getLong1 () const;
            uint32 getLong2 () const;
            uint32 getLong3 () const;
            uint32 getLong4 () const;

            void from4Int (uint32 d1, uint32 d2, uint32 d3, uint32 d4);
            void to4Int (uint32& d1, uint32& d2, uint32& d3, uint32& d4) const;

            typedef char8 String[33];

            /** Converts UID to a string.
                The string will be 32 characters long, representing the hexadecimal values
                of each data byte (e.g. "9127BE30160E4BB69966670AA6087880").

                Typical use-case is:
                \code{.cpp}
                char8[33] strUID = {0};
                FUID uid;
                if (uid.generate ())
                    uid.toString (strUID);
                \endcode
                */
            void toString (char8* string) const;

            /** Sets the UID data from a string.
                The string has to be 32 characters long, where each character-pair is
                the ASCII-encoded hexadecimal value of the corresponding data byte. */
            bool fromString (const char8* string);

            /** Converts UID to a string in Microsoft(R) OLE format.
            (e.g. "{c200e360-38c5-11ce-ae62-08002b2b79ef}") */
            void toRegistryString (char8* string) const;

            /** Sets the UID data from a string in Microsoft(R) OLE format. */
            bool fromRegistryString (const char8* string);

            enum UIDPrintStyle
            {
                kINLINE_UID,  ///< "INLINE_UID (0x00000000, 0x00000000, 0x00000000, 0x00000000)"
                kDECLARE_UID, ///< "DECLARE_UID (0x00000000, 0x00000000, 0x00000000, 0x00000000)"
                kFUID,        ///< "FUID (0x00000000, 0x00000000, 0x00000000, 0x00000000)"
                kCLASS_UID    ///< "DECLARE_CLASS_IID (Interface, 0x00000000, 0x00000000, 0x00000000, 0x00000000)"
            };

            /** Prints the UID to a string (or debug output if string is NULL).
             * @param style can be chosen from the FUID::UIDPrintStyle enumeration.
             * @param string is the output string if not NULL.
             * @param stringBufferSize is the size of the output string
             */
            void print (int32 style, char8* string = nullptr, size_t stringBufferSize = 0) const;

        #if SMTG_CPP17
            [[deprecated ("Use the print method with the buffer size")]]
        #endif
            void print (char8* string = nullptr, int32 style = kINLINE_UID) const;

            template <size_t N>
            inline explicit FUID (const char (&uid)[N])
            {
        #if SMTG_CPP11_STDLIBSUPPORT
                static_assert (N == sizeof (TUID), "only TUID allowed");
        #endif
                memcpy (data, uid, sizeof (TUID));
            }
            inline void toTUID (TUID result) const { memcpy (result, data, sizeof (TUID)); }
            inline operator const TUID& () const { return data; }
            inline const TUID& toTUID () const { return data; }

            static FUID fromTUID (const TUID uid)
            {
                FUID res;
                if (uid)
                    memcpy (res.data, uid, sizeof (TUID));
                return res;
            }

        protected:
            TUID data;
    };

    #if SMTG_CPP11_STDLIBSUPPORT
        template <typename T>
        inline bool operator== (const FUID& f1, T f2)
        {
            static_assert (
                std::is_same<typename std::remove_cv<T>::type, FUID>::value,
                "Do not compare a FUID with a TUID directly. Either convert the TUID to a FUID and compare them or use iidEqual");
            return f1.operator== (f2);
        }
    #endif

} /* namespace Steinberg */




#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_FUID_H_ */
