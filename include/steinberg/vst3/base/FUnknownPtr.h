/*
 * Copyright 2023, Steinberg Media Technologies GmbH, All Rights Reserved
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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_FUNKNOWNPTR_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_FUNKNOWNPTR_H_

#include <steinberg/vst3/base/IPtr.h>
#include <steinberg/vst3/base/FUnknown.h>

namespace Steinberg
{
    /**
     * FUnknownPtr - automatic interface conversion and smart pointer in one.
     * This template class can be used for interface conversion like this:
     *   IPtr<IPath> path = owned (FHostCreate (IPath, hostClasses));
     *   FUnknownPtr<IPath2> path2 (path); // does a query interface for IPath2
     *   if (path2)
     *       ...
     */
    template <class I>
    class FUnknownPtr : public IPtr<I>
    {
        public:
            inline FUnknownPtr (FUnknown* unknown); // query interface
            inline FUnknownPtr (const FUnknownPtr& p) : IPtr<I> (p) {}
            inline FUnknownPtr () {}

            inline FUnknownPtr& operator= (const FUnknownPtr& p)
            {
                IPtr<I>::operator= (p);
                return *this;
            }
            inline I* operator= (FUnknown* unknown);
            inline I* getInterface () { return this->ptr; }

        #if SMTG_CPP11_STDLIBSUPPORT
            inline FUnknownPtr (FUnknownPtr&& p) SMTG_NOEXCEPT : IPtr<I> (std::move (p)) {}
            inline FUnknownPtr& operator= (FUnknownPtr&& p) SMTG_NOEXCEPT
            {
                IPtr<I>::operator= (std::move (p));
                return *this;
            }
        #endif /* SMTG_CPP11_STDLIBSUPPORT */
    };

    template <class I>
    inline FUnknownPtr<I>::FUnknownPtr (FUnknown* unknown)
    {
        if (unknown && unknown->queryInterface (getTUID<I> (), (void**)&this->ptr) != kResultOk)
            this->ptr = 0;
    }

    template <class I>
    inline I* FUnknownPtr<I>::operator= (FUnknown* unknown)
    {
        I* newPtr = 0;
        if (unknown && unknown->queryInterface (getTUID<I> (), (void**)&newPtr) == kResultOk)
        {
            OPtr<I> rel (newPtr);
            return IPtr<I>::operator= (newPtr);
        }

        return IPtr<I>::operator= (0);
    }

} /* namespace Steinberg */


#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_FUNKNOWNPTR_H_ */
