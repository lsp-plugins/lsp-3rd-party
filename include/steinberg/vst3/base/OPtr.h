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

#ifndef _3RDPARTY_INCLUDE_STEINBERG_VST3_BASE_OPTR_H_
#define _3RDPARTY_INCLUDE_STEINBERG_VST3_BASE_OPTR_H_

#include <steinberg/vst3/base/IPtr.h>
#include <steinberg/vst3/base/Platform.h>

namespace Steinberg
{

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

} /* namespace Steinberg */

#endif /* _3RDPARTY_INCLUDE_STEINBERG_VST3_BASE_OPTR_H_ */
