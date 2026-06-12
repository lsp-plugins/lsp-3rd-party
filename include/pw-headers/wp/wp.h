/* WirePlumber
 *
 * Copyright © 2019 Collabora Ltd.
 *    @author George Kiagiadakis <george.kiagiadakis@collabora.com>
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef __WIREPLUMBER_WP_H__
#define __WIREPLUMBER_WP_H__

#include <pw-headers/wp/base-dirs.h>
#include <pw-headers/wp/client.h>
#include <pw-headers/wp/component-loader.h>
#include <pw-headers/wp/conf.h>
#include <pw-headers/wp/core.h>
#include <pw-headers/wp/device.h>
#include <pw-headers/wp/error.h>
#include <pw-headers/wp/event-dispatcher.h>
#include <pw-headers/wp/event-hook.h>
#include <pw-headers/wp/factory.h>
#include <pw-headers/wp/global-proxy.h>
#include <pw-headers/wp/iterator.h>
#include <pw-headers/wp/json-utils.h>
#include <pw-headers/wp/link.h>
#include <pw-headers/wp/log.h>
#include <pw-headers/wp/metadata.h>
#include <pw-headers/wp/module.h>
#include <pw-headers/wp/node.h>
#include <pw-headers/wp/object.h>
#include <pw-headers/wp/object-interest.h>
#include <pw-headers/wp/object-manager.h>
#include <pw-headers/wp/permission-manager.h>
#include <pw-headers/wp/plugin.h>
#include <pw-headers/wp/port.h>
#include <pw-headers/wp/proc-utils.h>
#include <pw-headers/wp/properties.h>
#include <pw-headers/wp/proxy.h>
#include <pw-headers/wp/proxy-interfaces.h>
#include <pw-headers/wp/session-item.h>
#include <pw-headers/wp/settings.h>
#include <pw-headers/wp/si-factory.h>
#include <pw-headers/wp/si-interfaces.h>
#include <pw-headers/wp/spa-json.h>
#include <pw-headers/wp/spa-pod.h>
#include <pw-headers/wp/spa-type.h>
#include <pw-headers/wp/state.h>
#include <pw-headers/wp/transition.h>
#include <pw-headers/wp/wpenums.h>
#include <pw-headers/wp/wpversion.h>

G_BEGIN_DECLS

/*!
 * \ingroup wp
 * Flags for wp_init()
 */
typedef enum {
  /*! Initialize PipeWire by calling pw_init() */
  WP_INIT_PIPEWIRE = (1<<0),
  /*! Initialize support for dynamic spa types.
   * See wp_spa_dynamic_type_init() */
  WP_INIT_SPA_TYPES = (1<<1),
  /*! Override PipeWire's logging system with WirePlumber's one */
  WP_INIT_SET_PW_LOG = (1<<2),
  /*! Set wp_log_writer_default() as GLib's default log writer function */
  WP_INIT_SET_GLIB_LOG = (1<<3),
  /*! Initialize all of the above */
  WP_INIT_ALL = 0xf,
} WpInitFlags;

WP_API
void wp_init (WpInitFlags flags);

WP_API
const char * wp_get_library_version (void);

WP_API
const char * wp_get_library_api_version (void);

G_END_DECLS

#endif
