#
# Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
#           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
#
# This file is part of lsp-3rd-party
#
# lsp-3rd-party is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# lsp-3rd-party is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with lsp-3rd-party.  If not, see <https://www.gnu.org/licenses/>.
#

# Package version
ARTIFACT_NAME               = lsp-3rd-party
ARTIFACT_DESC               = 3rd party libraries/headers for building audio plugins
ARTIFACT_VARS               = LSP_3RD_PARTY
ARTIFACT_HEADERS            = 3rdparty
ARTIFACT_EXPORT_ALL         = 1
ARTIFACT_VERSION            = 0.5.0

# List of dependencies
DEPENDENCIES = \
  STDLIB \
  LSP_COMMON_LIB

TEST_DEPENDENCIES = \
  TEST_STDLIB \
  LSP_TEST_FW

# All possible dependencies
ALL_DEPENDENCIES = \
  $(DEPENDENCIES) \
  $(TEST_DEPENDENCIES)
