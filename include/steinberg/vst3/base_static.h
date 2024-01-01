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
    DEF_CLASS_IID (IDependent)
    DEF_CLASS_IID (IUpdateHandler)

    DEF_CLASS_IID (IBStream)
    DEF_CLASS_IID (ISizeableStream)

} /* namespace Steinberg */



#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_STATIC_H_ */
