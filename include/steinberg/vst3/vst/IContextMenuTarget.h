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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_ICONTEXTMENUTARGET_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_ICONTEXTMENUTARGET_H_

#include <steinberg/vst3/gui/IPlugView.h>

namespace Steinberg
{
    namespace Vst
    {
        /**
         * Context Menu Item Target interface: Vst::IContextMenuTarget
         *
         * A receiver of a menu item should implement this interface, which will be called
         * after the user has selected this menu item.
         *
         * @see IComponentHandler3 for more information.
         */
        #include <steinberg/vst3/base/WarningsPush.h>
        class IContextMenuTarget: public FUnknown
        {
            public:
                /** Called when an menu item was executed. */
                virtual tresult PLUGIN_API executeMenuItem(int32 tag) = 0;

            public:
                static const FUID iid;
        };
        #include <steinberg/vst3/base/WarningsPop.h>

        DECLARE_CLASS_IID (IContextMenuTarget, 0x3CDF2E75, 0x85D34144, 0xBF86D36B, 0xD7C4894D)

    } /* namespace Vst */
} /* namespace Steinberg */


#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_VST_ICONTEXTMENUTARGET_H_ */
