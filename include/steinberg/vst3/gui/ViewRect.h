/*
 * Copyright (C) 2024 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2024 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-plugins-comp-delay
 * Created on: 1 янв. 2024 г.
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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_GUI_VIEWRECT_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_GUI_VIEWRECT_H_

#include <steinberg/vst3/base/TypeSizeCheck.h>
#include <steinberg/vst3/vst/Types.h>

namespace Steinberg
{
    /**
     * Graphical rectangle structure. Used with IPlugView.
     */
    struct ViewRect
    {
        int32 left;
        int32 top;
        int32 right;
        int32 bottom;

        inline int32 getWidth () const  { return right - left; }
        inline int32 getHeight () const { return bottom - top; }
    };

    SMTG_TYPE_SIZE_CHECK(ViewRect, 16, 16, 16, 16)

    /**
     * Platform UI Types
     *
     * List of Platform UI types for IPlugView. This list is used to match the GUI-System between
     * the host and a plug-in in case that an OS provides multiple GUI-APIs.
     */
    /**
     * The parent parameter in IPlugView::attached() is a HWND handle (Microsoft Windows).
     * You should attach a child window to it.
     */
    const FIDString kPlatformTypeHWND = "HWND";

    /**
     * The parent parameter in IPlugView::attached() is a WindowRef (Mac OS X).
     * You should attach a HIViewRef to the content view of the window.
     */
    const FIDString kPlatformTypeHIView = "HIView";

    /**
     * The parent parameter in IPlugView::attached() is a NSView pointer (Mac OS X).
     * You should attach a NSView to it.
     */
    const FIDString kPlatformTypeNSView = "NSView";

    /**
     * The parent parameter in IPlugView::attached() is a UIView pointer (iOS).
     * You should attach an UIView to it.
     */
    const FIDString kPlatformTypeUIView = "UIView";

    /**
     * The parent parameter in IPlugView::attached() is a X11 Window supporting XEmbed (X11).
     * You should attach a Window to it that supports the XEmbed extension.
     * See https://standards.freedesktop.org/xembed-spec/xembed-spec-latest.html
     */
    const FIDString kPlatformTypeX11EmbedWindowID = "X11EmbedWindowID";

} /* namespace Steinberg */

#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_GUI_VIEWRECT_H_ */
