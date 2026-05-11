/* PipeWire */
/* SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans */
/* SPDX-License-Identifier: MIT */

#ifndef PIPEWIRE_H
#define PIPEWIRE_H

#include <pw-headers/spa/support/plugin.h>

// IWYU pragma: begin_exports
#include <pw-headers/pipewire/array.h>
#include <pw-headers/pipewire/client.h>
#include <pw-headers/pipewire/conf.h>
#include <pw-headers/pipewire/context.h>
#include <pw-headers/pipewire/device.h>
#include <pw-headers/pipewire/buffers.h>
#include <pw-headers/pipewire/core.h>
#include <pw-headers/pipewire/factory.h>
#include <pw-headers/pipewire/keys.h>
#include <pw-headers/pipewire/log.h>
#include <pw-headers/pipewire/loop.h>
#include <pw-headers/pipewire/link.h>
#include <pw-headers/pipewire/main-loop.h>
#include <pw-headers/pipewire/map.h>
#include <pw-headers/pipewire/mem.h>
#include <pw-headers/pipewire/module.h>
#include <pw-headers/pipewire/node.h>
#include <pw-headers/pipewire/properties.h>
#include <pw-headers/pipewire/proxy.h>
#include <pw-headers/pipewire/permission.h>
#include <pw-headers/pipewire/protocol.h>
#include <pw-headers/pipewire/port.h>
#include <pw-headers/pipewire/stream.h>
#include <pw-headers/pipewire/filter.h>
#include <pw-headers/pipewire/thread-loop.h>
#include <pw-headers/pipewire/data-loop.h>
#include <pw-headers/pipewire/type.h>
#include <pw-headers/pipewire/utils.h>
#include <pw-headers/pipewire/version.h>
#include <pw-headers/pipewire/timer-queue.h>
// IWYU pragma: end_exports

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup pw_pipewire Initialization
 * Initializing PipeWire and loading SPA modules.
 */

/**
 * \addtogroup pw_pipewire
 * \{
 */
void
pw_init(int *argc, char **argv[]);

void pw_deinit(void);

bool
pw_debug_is_category_enabled(const char *name);

const char *
pw_get_application_name(void);

const char *
pw_get_prgname(void);

const char *
pw_get_user_name(void);

const char *
pw_get_host_name(void);

const char *
pw_get_client_name(void);

bool pw_check_option(const char *option, const char *value);

enum pw_direction
pw_direction_reverse(enum pw_direction direction);

int pw_set_domain(const char *domain);
const char *pw_get_domain(void);

uint32_t pw_get_support(struct spa_support *support, uint32_t max_support);

struct spa_handle *pw_load_spa_handle(const char *lib,
		const char *factory_name,
		const struct spa_dict *info,
		uint32_t n_support,
		const struct spa_support support[]);

int pw_unload_spa_handle(struct spa_handle *handle);

/**
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* PIPEWIRE_H */
