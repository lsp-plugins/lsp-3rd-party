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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_STATIC_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_STATIC_H_

#include <steinberg/vst3/vst.h>

namespace Steinberg
{
    namespace Vst
    {
        //----VST 3.0--------------------------------
        DEF_CLASS_IID (IComponent)
        DEF_CLASS_IID (IAudioProcessor)
        DEF_CLASS_IID (IUnitData)
        DEF_CLASS_IID (IProgramListData)

        DEF_CLASS_IID (IEditController)
        DEF_CLASS_IID (IUnitInfo)

        DEF_CLASS_IID (IConnectionPoint)

        DEF_CLASS_IID (IComponentHandler)
        DEF_CLASS_IID (IUnitHandler)

        DEF_CLASS_IID (IParamValueQueue)
        DEF_CLASS_IID (IParameterChanges)

        DEF_CLASS_IID (IEventList)
        DEF_CLASS_IID (IMessage)

        DEF_CLASS_IID (IHostApplication)
        DEF_CLASS_IID (IAttributeList)

        //----VST 3.0.1--------------------------------
        DEF_CLASS_IID (IMidiMapping)

        //----VST 3.0.2--------------------------------
        DEF_CLASS_IID (IParameterFinder)

        //----VST 3.1----------------------------------
        DEF_CLASS_IID (IComponentHandler2)
        DEF_CLASS_IID (IEditController2)
        DEF_CLASS_IID (IAudioPresentationLatency)
        DEF_CLASS_IID (IVst3ToVst2Wrapper)
        DEF_CLASS_IID (IVst3ToAUWrapper)

        //----VST 3.5----------------------------------
        DEF_CLASS_IID (INoteExpressionController)
        DEF_CLASS_IID (IKeyswitchController)
        DEF_CLASS_IID (IContextMenuTarget)
        DEF_CLASS_IID (IContextMenu)
        DEF_CLASS_IID (IComponentHandler3)
        DEF_CLASS_IID (IEditControllerHostEditing)
//        DEF_CLASS_IID (IXmlRepresentationController)

        //----VST 3.6----------------------------------
//        DEF_CLASS_IID (IInterAppAudioHost)
//        DEF_CLASS_IID (IInterAppAudioConnectionNotification)
//        DEF_CLASS_IID (IInterAppAudioPresetManager)
        DEF_CLASS_IID (IStreamAttributes)

        //----VST 3.6.5--------------------------------
//        DEF_CLASS_IID (ChannelContext::IInfoListener)
//        DEF_CLASS_IID (IPrefetchableSupport)
        DEF_CLASS_IID (IUnitHandler2)
//        DEF_CLASS_IID (IAutomationState)

        //----VST 3.6.8--------------------------------
        DEF_CLASS_IID (IComponentHandlerBusActivation)
        DEF_CLASS_IID (IVst3ToAAXWrapper)

        //----VST 3.6.11--------------------------------
//        DEF_CLASS_IID (INoteExpressionPhysicalUIMapping)

        //----VST 3.6.12--------------------------------
//        DEF_CLASS_IID (IMidiLearn)
//        DEF_CLASS_IID (IPlugInterfaceSupport)
        DEF_CLASS_IID (IVst3WrapperMPESupport)

        //----VST 3.6.13--------------------------------
//        DEF_CLASS_IID (ITestPlugProvider)

        //----VST 3.7-----------------------------------
//        DEF_CLASS_IID (IParameterFunctionName)
        DEF_CLASS_IID (IProcessContextRequirements)
        DEF_CLASS_IID (IProgress)
//        DEF_CLASS_IID (ITestPlugProvider2)

        //----VST 3.7.5---------------------------------
//        DEF_CLASS_IID (IPluginCompatibility)

        //----VST 3.7.9---------------------------------
        DEF_CLASS_IID (IComponentHandlerSystemTime)
//        DEF_CLASS_IID (IDataExchangeHandler)
//        DEF_CLASS_IID (IDataExchangeReceiver)

    } /* namespace Vst */
} /* namespace Steinberg */



#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_STATIC_H_ */
