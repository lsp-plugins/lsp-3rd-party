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

#ifndef _3RD_PARTY_STEINBERG_VST3_VST_MIDI2_H_
#define _3RD_PARTY_STEINBERG_VST3_VST_MIDI2_H_

#include <steinberg/vst3/vst/BusInfo.h>
#include <steinberg/vst3/vst/Types.h>

#include <steinberg/vst3/base/AlignPush.h>

namespace Steinberg
{
    namespace Vst
    {

        using MidiGroup = uint8;
        using MidiChannel = uint8;
        using BusIndex = int32;

        /**
         * Midi2Controller
         * describes a MIDI 2.0 Registered or Assignable Controller
         */
        struct Midi2Controller
        {
            /**
             * Bits 0-6 of byte1 specify the bank. Bit 7 (MSB) indicates the controller type:
             * set = registered controller, clear = assignable controller.
             */
            uint8 byte1;

            /**
             * Bits 0-6 of byte2 specify the controller index.
             */
            uint8 byte2;

            /**
             * Returns true if the MIDI2 controller struct is a registered controller and false if it is an
             *  assignable controller.
             */
            static inline bool isRegisteredController(const Midi2Controller& mc)
            {
                return mc.byte1 & 0x80;
            }

            /**
             * Returns the bank number of the MIDI2 controller struct.
             */
            static inline uint8 bank(const Midi2Controller& mc)
            {
                return mc.byte1 & 0x7f;
            }

            /**
             * Returns the index number of the MIDI2 controller struct.
             */
            static inline uint8 index(const Midi2Controller& mc)
            {
                return mc.byte2 & 0x7f;
            }

            /**
             * Sets the flag of the MIDI2 controller struct if it describes a registered or assignable controller.
             */
            static inline void setIsRegisteredController (Midi2Controller& mc, bool registered)
            {
                mc.byte1 = (mc.byte1 & 0x7f) | (registered ? 0x80 : 0x00);
            }

            /**
             * Set the bank number of the MIDI2 controller struct.
             */
            static inline void setBank (Midi2Controller& mc, uint8 bank)
            {
                mc.byte1 = (mc.byte1 & 0x80) | bank;
            }

            /**
             * Set the index number of the MIDI2 controller struct.
             */
            static inline void setIndex (Midi2Controller& mc, uint8 index)
            {
                mc.byte2 = index & 0x7f;
            }

            /**
             * Creates a new MIDI2 controller struct.
             */
            static inline Midi2Controller create(bool registered, uint8 bank, uint8 index)
            {
                Midi2Controller m2c { 0, 0 };
                setIsRegisteredController (m2c, registered);
                setBank (m2c, bank);
                setIndex (m2c, index);
                return m2c;
            }
        };

        struct Midi2ControllerParamIDAssignment
        {
            ParamID pId;
            BusIndex busIndex;
            MidiChannel channel;
            Midi2Controller controller;
        };

        struct Midi2ControllerParamIDAssignmentList
        {
            uint32 count;
            Midi2ControllerParamIDAssignment *map;
        };

        struct Midi1ControllerParamIDAssignment
        {
            ParamID pId;
            BusIndex busIndex;
            MidiChannel channel;
            CtrlNumber controller;
        };

        struct Midi1ControllerParamIDAssignmentList
        {
            uint32 count;
            Midi1ControllerParamIDAssignment *map;
        };

    } /* namespace Vst */
} /* namespace Steinberg */

#include <steinberg/vst3/base/AlignPop.h>


#endif /* _3RD_PARTY_STEINBERG_VST3_VST_MIDI2_H_ */
