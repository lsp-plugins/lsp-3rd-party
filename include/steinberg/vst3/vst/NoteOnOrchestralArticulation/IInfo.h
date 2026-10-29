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

#ifndef _3RD_PARTY_STEINBERG_VST3_VST_NOTEONORCHESTRALARTICULATION_IINFO_H_
#define _3RD_PARTY_STEINBERG_VST3_VST_NOTEONORCHESTRALARTICULATION_IINFO_H_

#include <steinberg/vst3/vst/Types.h>
#include <steinberg/vst3/base/FUnknown.h>
#include <steinberg/vst3/vst/NoteOnOrchestralArticulation/Variations.h>
#include <steinberg/vst3/vst/NoteOnOrchestralArticulation/ClassificationVariations.h>

#include <steinberg/vst3/base/AlignPush.h>

namespace Steinberg
{
    namespace Vst
    {
        namespace NoteOnOrchestralArticulation
        {
            /**
             * Extended host callback interface for an edit controller:
             * Vst::NoteOnOrchestralArticulation::IInfo
             *
             * This interface allows the host to get some information about the plug-in's noteOn
             *  Orchestral Articulation capabilities from the UI Thread
             */
            #include <steinberg/vst3/base/WarningsPush.h>
            class IInfo : public FUnknown
            {
                public:
                    /**
                     * Used as index for the array classification of structure ClassificationVariations.
                     */
                    enum Classification : uint32
                    {
                        kCoreSoundSustainAndStrikes = 0,
                        kStaccatosAndShorts = 1,
                        kSameNoteTrillsRepeats = 2,
                        kIntervallicTrills = 3,
                        kAdditionalColors = 4,
                        kPitchAndDynamicGestures = 5,
                        kScalesRunsAndArpeggios = 6,
                        kEffectsAndNoises = 7,

                        kReserved1 = 8,
                        kReserved2 = 9,

                        kCustomNoteOn1 = 10,
                        kCustomNoteOn2 = 11,
                        kCustomNoteOn3 = 12,
                        kCustomNoteOn4 = 13,
                        kCustomNoteOn5 = 14,
                        kCustomNoteOn6 = 15,

                        kReserved3 = 16
                    };

                    /**
                     * Returns variation information for orchestral classification types supported by the plug-in.
                     *
                     * The 2D Array is organized by classifications (see Classification) and subclass
                     * (according to the index used in MIDI2 Orchestral Profile).
                     * If info.classification[i].variation[j] is 0, subclass j has no variation (subclass not available).
                     * If all entries in info.classification[i] are zero, classification i is not available.
                     *
                     * @param[in] busIndex - index of Input Event Bus
                     * @param[in] channel - channel of the bus
                     * @param info 2D array receiving supported variation information.
                     * @return kResultTrue on success
                     *
                     * \note [UI-thread & Connected]
                     */
                    virtual tresult PLUGIN_API getVariationsInfo (int32 busIndex, int16 channel, ClassificationVariations& info) = 0;

                public:
                    static const FUID iid;
            };
            #include <steinberg/vst3/base/WarningsPop.h>


        } /* namespace NoteOnOrchestralArticulation */
    } /* namespace Vst */
} /* namespace Steinberg */

#include <steinberg/vst3/base/AlignPop.h>


#endif /* _3RD_PARTY_STEINBERG_VST3_VST_NOTEONORCHESTRALARTICULATION_IINFO_H_ */
