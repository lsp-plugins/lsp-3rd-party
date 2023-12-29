/*
 * Copyright (C) 2023 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2023 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-plugins-comp-delay
 * Created on: 29 дек. 2023 г.
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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_STATIC_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_STATIC_H_

#include <steinberg/vst3/base.h>

namespace Steinberg
{
    // Core IDs
    DEF_CLASS_IID (IPluginBase)
    DEF_CLASS_IID (IPluginFactory)
    DEF_CLASS_IID (IPluginFactory2)
    DEF_CLASS_IID (IPluginFactory3)

    DEF_CLASS_IID (FUnknown)

// TODO
//    DEF_CLASS_IID (ICloneable)
//
//    DEF_CLASS_IID (IDependent)
//    DEF_CLASS_IID (IUpdateHandler)
//
    DEF_CLASS_IID (IBStream)
    DEF_CLASS_IID (ISizeableStream)

} /* namespace Steinberg */



#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_STATIC_H_ */
