/*
 * Copyright (C) 2024 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2024 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-plugins-comp-delay
 * Created on: 1 янв. 2024 г.
 *
 * lsp-plugins-comp-delay is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * lsp-plugins-comp-delay is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with lsp-plugins-comp-delay. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_TYPESIZECHECK_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_TYPESIZECHECK_H_

#include <steinberg/vst3/base/Types.h>

#if SMTG_CPP11
    #define SMTG_TYPE_STATIC_CHECK(Operator, Type, Platform64Size, MacOS32Size, Win32Size, Linux32Size)         \
        namespace                                                                                               \
        {                                                                                                       \
            template <typename Type, size_t w, size_t x, size_t y, size_t z>                                    \
            struct Operator##Check##Type                                                                        \
            {                                                                                                   \
                constexpr Operator##Check##Type ()                                                              \
                {                                                                                               \
                    static_assert(                                                                              \
                       Operator(Type) == (SMTG_PLATFORM_64 ? w : SMTG_OS_MACOS ? x : SMTG_OS_POSIX ? z : y),    \
                       "Struct " #Operator " error: " #Type);                                                   \
                }                                                                                               \
            };                                                                                                  \
                                                                                                                \
            static constexpr Operator##Check##Type<Type, Platform64Size, MacOS32Size, Win32Size, Linux32Size>   \
                instance##Operator##Type;                                                                       \
        }

    /**
     * Check the size of a structure depending on compilation platform
     * Used to check that structure sizes don't change between SDK releases.
     */
    #define SMTG_TYPE_SIZE_CHECK(Type, Platform64Size, MacOS32Size, Win32Size, Linux32Size) \
        SMTG_TYPE_STATIC_CHECK (sizeof, Type, Platform64Size, MacOS32Size, Win32Size, Linux32Size)

    /**
     * Check the alignment of a structure depending on compilation platform
     * Used to check that structure alignments don't change between SDK releases.
     */
    #define SMTG_TYPE_ALIGN_CHECK(Type, Platform64Size, MacOS32Size, Win32Size, Linux32Size) \
        SMTG_TYPE_STATIC_CHECK (alignof, Type, Platform64Size, MacOS32Size, Win32Size, Linux32Size)

#else
    #define SMTG_TYPE_SIZE_CHECK(Type, Platform64Size, MacOS32Size, Win32Size, Linux32Size)
#endif /* SMTG_CPP11 */

#endif /* MODULES_LSP_3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_TYPESIZECHECK_H_ */
