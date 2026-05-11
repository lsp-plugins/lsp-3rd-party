/* PipeWire */
/* SPDX-FileCopyrightText: Copyright © 2019 Wim Taymans */
/* SPDX-License-Identifier: MIT */

#ifndef PIPEWIRE_IMPL_H
#define PIPEWIRE_IMPL_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup api_pw_impl
 */

struct pw_impl_client;
struct pw_impl_module;
struct pw_global;
struct pw_node;
struct pw_impl_port;
struct pw_resource;

#include <pw-headers/pipewire/pipewire.h>
#include <pw-headers/pipewire/control.h>
#include <pw-headers/pipewire/impl-core.h>
#include <pw-headers/pipewire/impl-client.h>
#include <pw-headers/pipewire/impl-device.h>
#include <pw-headers/pipewire/impl-factory.h>
#include <pw-headers/pipewire/global.h>
#include <pw-headers/pipewire/impl-link.h>
#include <pw-headers/pipewire/impl-metadata.h>
#include <pw-headers/pipewire/impl-module.h>
#include <pw-headers/pipewire/impl-node.h>
#include <pw-headers/pipewire/impl-port.h>
#include <pw-headers/pipewire/resource.h>
#include <pw-headers/pipewire/work-queue.h>

#ifdef __cplusplus
}
#endif

#endif /* PIPEWIRE_IMPL_H */
