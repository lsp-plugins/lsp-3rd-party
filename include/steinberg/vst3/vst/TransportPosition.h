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

#ifndef _3RD_PARTY_STEINBERG_VST3_VST_TRANSPORTPOSITION_H_
#define _3RD_PARTY_STEINBERG_VST3_VST_TRANSPORTPOSITION_H_

#include <steinberg/vst3/vst/Types.h>
#include <steinberg/vst3/base/PFactoryInfo.h>
#include <steinberg/vst3/vst/TransportPositionType.h>

#include <steinberg/vst3/base/AlignPush.h>

namespace Steinberg
{
    namespace Vst
    {
        /**
         * TransportPosition
         *
         * A tagged union representing a transport position in either:
         *  - absolute samples (TSamples), or
         *  - musical quarter notes (TQuarterNotes, a.k.a. PPQ).
         *
         * Hosts may choose which representation they honor.
         * Plug-ins should use ::Type to indicate which field is valid.
         *
         * @note TransportPosition is only meaningful for actions requiring a position
         *       (Locate, SetCycleStart, SetCycleEnd, etc).
         */
        struct TransportPosition
        {
            TransportPositionType type { TransportPositionType::Samples };

            union
            {
                TSamples samples; ///< Absolute sample position
                TQuarterNotes quarterNotes; ///< PPQ position (musical time)
            };

            /**
             * Create from absolute samples.
             */
            static inline TransportPosition fromSamples(TSamples s)
            {
                TransportPosition p;
                p.type      = TransportPositionType::Samples;
                p.samples   = s;
                return p;
            }

            /**
             * Create from quarter notes (PPQ).
             */
            static inline TransportPosition fromQuarterNotes(TQuarterNotes q)
            {
                TransportPosition p;
                p.type          = TransportPositionType::QuarterNotes;
                p.quarterNotes  = q;
                return p;
            }
        };
    } /* namespace Vst */
} /* namespace Steinberg */

#include <steinberg/vst3/base/AlignPop.h>

#endif /* _3RD_PARTY_STEINBERG_VST3_VST_TRANSPORTPOSITION_H_ */
