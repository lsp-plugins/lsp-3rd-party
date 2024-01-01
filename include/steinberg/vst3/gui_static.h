/*
 * Copyright (C) 2023 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2023 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-plugins-comp-delay
 * Created on: 29 дек. 2023 г.
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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_GUI_STATIC_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_GUI_STATIC_H_

#include <steinberg/vst3/gui.h>

namespace Steinberg
{
    DEF_CLASS_IID(IPlugView)
    DEF_CLASS_IID(IPlugFrame)
    DEF_CLASS_IID(IPlugViewContentScaleSupport)

    DEF_CLASS_IID(IEventHandler)
    DEF_CLASS_IID(ITimerHandler)
    DEF_CLASS_IID(IRunLoop)
} /* namespace Steinberg */

#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_GUI_STATIC_H_ */
