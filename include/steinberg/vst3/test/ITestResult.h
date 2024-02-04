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

#ifndef _3RD_PARTY_STEINBERG_VST3_TEST_ITESTRESULT_H_
#define _3RD_PARTY_STEINBERG_VST3_TEST_ITESTRESULT_H_

#include <steinberg/vst3/base/FUnknown.h>

namespace Steinberg
{
    /**
     * Test Result message logger.
     * When a test is called, a pointer to an ITestResult is passed in, so the
     * test class can output error messages
     */
    #include <steinberg/vst3/base/WarningsPush.h>
    class ITestResult: public FUnknown
    {
        public:
            /**
             * Add an error message
             * @param msg error message to add
             */
            virtual void PLUGIN_API addErrorMessage(const char16 *msg) = 0;

            /**
             * Add message
             * @param msg message to add
             */
            virtual void PLUGIN_API addMessage(const char16 *msg) = 0;

        public:
            static const TUID iid;
    };
    #include <steinberg/vst3/base/WarningsPop.h>

} /* namespace Steinberg */

#endif /* _3RD_PARTY_STEINBERG_VST3_TEST_ITESTRESULT_H_ */
