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

#ifndef _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_PCLASSINFO2_H_
#define _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_PCLASSINFO2_H_

#include <steinberg/vst3/base/Platform.h>
#include <steinberg/vst3/base/PClassInfo.h>
#include <steinberg/vst3/base/TUID.h>

namespace Steinberg
{
    /**
     * Basic Information about a class provided by the plug-in (version 2).
     */
    struct PClassInfo2
    {
        /**
         * Class ID 16 Byte class GUID
         */
        TUID cid;

        /**
         * Cardinality of the class, set to kManyInstances
         */
        int32 cardinality;

        /**
         * Class category, host uses this to categorize interfaces
         */
        char8 category[PClassInfo::kCategorySize];

        /**
         * Class name, visible to the user
         */
        char8 name[PClassInfo::kNameSize];

        enum
        {
            kVendorSize         = 64,
            kVersionSize        = 64,
            kSubCategoriesSize  = 128
        };

        /**
         * Flags used for a specific category, must be defined where category is defined
         */
        uint32 classFlags;

        /**
         * Module specific subcategories, can be more than one, logically added by the OR operator
         */
        char8 subCategories[kSubCategoriesSize];

        /**
         * Overwrite vendor information from factory info
         */
        char8 vendor[kVendorSize];

        /**
         * Version string (e.g. "1.0.0.512" with Major.Minor.Subversion.Build)
         */
        char8 version[kVersionSize];

        /**
         * SDK version used to build this class (e.g. "VST 3.0")
         */
        char8 sdkVersion[kVersionSize];
    };

} /* namespace Steinberg */


#endif /* _3RD_PARTY_INCLUDE_STEINBERG_VST3_BASE_PCLASSINFO2_H_ */
