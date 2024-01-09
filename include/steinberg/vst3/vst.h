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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_H_

#include <steinberg/vst3/version.h>

// Platform-specific macros and type definitions
#include <steinberg/vst3/vst/Types.h>

// Miscellaneous data structures
#include <steinberg/vst3/vst/PlugType.h>
#include <steinberg/vst3/vst/KeySwitchInfo.h>
#include <steinberg/vst3/vst/NoteExpression.h>
#include <steinberg/vst3/vst/Event.h>
#include <steinberg/vst3/vst/BusInfo.h>
#include <steinberg/vst3/vst/RoutingInfo.h>
#include <steinberg/vst3/vst/Speaker.h>
#include <steinberg/vst3/vst/ProcessContext.h>
#include <steinberg/vst3/vst/ProcessData.h>
#include <steinberg/vst3/vst/ParameterInfo.h>
#include <steinberg/vst3/vst/UnitInfo.h>

// Interfaces
#include <steinberg/vst3/vst/IComponent.h>
#include <steinberg/vst3/vst/IEventList.h>
#include <steinberg/vst3/vst/IMessage.h>
#include <steinberg/vst3/vst/IAttributeList.h>
#include <steinberg/vst3/vst/IStreamAttributes.h>
#include <steinberg/vst3/vst/IConnectionPoint.h>
#include <steinberg/vst3/vst/IParamValueQueue.h>
#include <steinberg/vst3/vst/IParameterChanges.h>
#include <steinberg/vst3/vst/IAudioProcessor.h>
#include <steinberg/vst3/vst/IAudioPresentationLatency.h>
#include <steinberg/vst3/vst/IProcessContextRequirements.h>
#include <steinberg/vst3/vst/IKeySwitchController.h>
#include <steinberg/vst3/vst/INoteExpressionController.h>
#include <steinberg/vst3/vst/IParameterFinder.h>
#include <steinberg/vst3/vst/IComponentHandler.h>
#include <steinberg/vst3/vst/IComponentHandler2.h>
#include <steinberg/vst3/vst/IComponentHandlerBusActivation.h>
#include <steinberg/vst3/vst/IProgress.h>
#include <steinberg/vst3/vst/IEditController.h>
#include <steinberg/vst3/vst/IEditController2.h>
#include <steinberg/vst3/vst/IMidiMapping.h>
#include <steinberg/vst3/vst/IEditControllerHostEditing.h>
#include <steinberg/vst3/vst/IComponentHandlerSystemTime.h>
#include <steinberg/vst3/vst/IUnitHandler.h>
#include <steinberg/vst3/vst/IUnitHandler2.h>
#include <steinberg/vst3/vst/IUnitInfo.h>
#include <steinberg/vst3/vst/IProgramListData.h>
#include <steinberg/vst3/vst/IUnitData.h>
#include <steinberg/vst3/vst/IHostApplication.h>
#include <steinberg/vst3/vst/IVst3ToVst2Wrapper.h>
#include <steinberg/vst3/vst/IVst3ToAUWrapper.h>
#include <steinberg/vst3/vst/IVst3ToAAXWrapper.h>
#include <steinberg/vst3/vst/IVst3WrapperMPESupport.h>

#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_H_ */
