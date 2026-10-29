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

#ifndef _3RD_PARTY_STEINBERG_VST3_VST_ITRANSPORTCONTROL_H_
#define _3RD_PARTY_STEINBERG_VST3_VST_ITRANSPORTCONTROL_H_

#include <steinberg/vst3/vst/Types.h>
#include <steinberg/vst3/base/PFactoryInfo.h>
#include <steinberg/vst3/vst/TransportPositionType.h>
#include <steinberg/vst3/vst/TransportPosition.h>

#include <steinberg/vst3/base/AlignPush.h>

namespace Steinberg
{
    namespace Vst
    {
        /**
         * Vst::ITransportControl Interface
         * This interface allows a plug-in to request transport-related actions from the host.
         * Typical use cases include:
         * - Jumping (locating) to a position
         * - Starting or stopping playback or recording
         * - Adjusting loop/cycle regions
         * - Enabling or disabling cycle playback
         *
         * All calls must be made from the **UI thread**.
         * Hosts may accept or deny requests depending on their internal policies or the
         * current editing mode (e.g., offline rendering, write-protected state, etc.).
         */
        #include <steinberg/vst3/base/WarningsPush.h>
        class ITransportControl : public FUnknown
        {
            public:
                /**
                 * Transport action requested by the plug-in.
                 */
                enum Action : int32
                {
                    /**
                     * Locate transport to a new position.
                     * Requires a valid TransportPosition.
                     */
                    Locate = 0,

                    /**
                     * Playback control
                     */
                    PlaybackStart,                  ///< Start playback at current position
                    PlaybackStop,                   ///< Stop playback, keep current position
                    LocateAndPlaybackStart,         ///< Locate and start playback (position required)
                    PlaybackStopAndLocate,          ///< Stop and locate (position required)

                    /**
                     * Recording control
                     */
                    RecordOnPlaybackStart,          ///< Start recording and playback at current position
                    LocateAndRecordOnPlaybackStart, ///< Locate and start recording and playback (position required)
                    RecordOff,                      ///< Stop recording and continue playback
                    RecordOffPlaybackStop,          ///< Stop recording and playback, keep current position
                    RecordOffPlaybackStopAndLocate, ///< Stop recording and playback and locate (position required)

                    /**
                     * Cycle / Loop control
                     */
                    SetCycleStart,                  ///< Set start of cycle/loop region (position required)
                    SetCycleEnd,                    ///< Set end of cycle/loop region (position required)
                    CycleOn,                        ///< Enable looping/cycle mode
                    CycleOff                        ///< Disable looping/cycle mode
                };

                /**
                 * Request a transport action from the host.
                 *
                 * The host may accept the request or refuse it based on its current state
                 * (editing mode, user preferences, restricted transport control policies).
                 *
                 * @param action   The action to perform.
                 * @param position Optional pointer to a TransportPosition.
                 *                 Required for locate or cycle-related actions.
                 *
                 * @return kResultOk          The request is accepted (not necessarily completed synchronously).
                 *         kNotImplemented    Host does not implement this function.
                 *         kInvalidArgument   Position missing or invalid for the supplied action.
                 *         kResultFalse       Host refuses the action due to state/policy constraints.
                 *
                 * @note Must be called from the UI/main thread.
                 * @note [UI-thread & (Initialized | Connected)]
                 */
                virtual tresult PLUGIN_API requestAction(int32 action, TransportPosition* position = nullptr) = 0;

                /**
                 * Query whether the host supports the given action.
                 *
                 * This is useful for updating plug-in UI elements (enabling or disabling buttons).
                 *
                 * @param action The action to test.
                 *
                 * @return kResultOk        The action is supported.
                 *         kResultFalse     The action is not supported.
                 *         kNotImplemented  Host does not implement this function.
                 *         kInvalidArgument Unknown action.
                 *
                 * @note Must be called from the UI/main thread.
                 * @note [UI-thread & (Initialized | Connected)] */
                virtual tresult PLUGIN_API isActionSupported(int32 action) = 0;

            public:
                static const FUID iid;
        };
        #include <steinberg/vst3/base/WarningsPop.h>

    } /* namespace Vst */
} /* namespace Steinberg */

#include <steinberg/vst3/base/AlignPop.h>

#endif /* _3RD_PARTY_STEINBERG_VST3_VST_ITRANSPORTCONTROL_H_ */
