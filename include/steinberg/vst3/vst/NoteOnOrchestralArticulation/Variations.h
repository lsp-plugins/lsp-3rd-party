/*
 * Copyright 2026, Steinberg Media Technologies GmbH, All Rights Reserved
 * Copyright 2026 Linux Studio Plugins Project <lsp.plugin@gmail.com>
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

#ifndef _3RD_PARTY_STEINBERG_VST3_VST_NOTEONORCHESTRALARTICULATION_VARIATIONS_H_
#define _3RD_PARTY_STEINBERG_VST3_VST_NOTEONORCHESTRALARTICULATION_VARIATIONS_H_

#include <steinberg/vst3/vst/Types.h>
#include <steinberg/vst3/base/FUnknown.h>

#include <steinberg/vst3/base/AlignPush.h>

namespace Steinberg
{
    namespace Vst
    {
        namespace NoteOnOrchestralArticulation
        {
            struct Variations
            {
                enum
                {
                    kNumSubClasses = 16
                };
                uint8 variation[kNumSubClasses];
            };
        } // namespace NoteOnOrchestralArticulation
    } // namespace Vst
} // namespace Steinberg

#include <steinberg/vst3/base/AlignPop.h>




#endif /* _3RD_PARTY_STEINBERG_VST3_VST_NOTEONORCHESTRALARTICULATION_VARIATIONS_H_ */
