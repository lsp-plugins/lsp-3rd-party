/* Simple Plugin API */
/* SPDX-FileCopyrightText: Copyright © 2018 Wim Taymans */
/* SPDX-License-Identifier: MIT */

#ifndef SPA_PARAM_AUDIO_FORMAT_H
#define SPA_PARAM_AUDIO_FORMAT_H

#include <pw-headers/spa/param/audio/ac3.h>
#include <pw-headers/spa/param/audio/dts.h>
#include <pw-headers/spa/param/audio/eac3.h>
#include <pw-headers/spa/param/audio/mpegh.h>
#include <pw-headers/spa/param/audio/truehd.h>
#include <pw-headers/spa/param/format.h>
#include <pw-headers/spa/param/audio/raw.h>
#include <pw-headers/spa/param/audio/dsp.h>
#include <pw-headers/spa/param/audio/iec958.h>
#include <pw-headers/spa/param/audio/dsd.h>
#include <pw-headers/spa/param/audio/mp3.h>
#include <pw-headers/spa/param/audio/aac.h>
#include <pw-headers/spa/param/audio/vorbis.h>
#include <pw-headers/spa/param/audio/wma.h>
#include <pw-headers/spa/param/audio/ra.h>
#include <pw-headers/spa/param/audio/amr.h>
#include <pw-headers/spa/param/audio/alac.h>
#include <pw-headers/spa/param/audio/flac.h>
#include <pw-headers/spa/param/audio/ape.h>
#include <pw-headers/spa/param/audio/opus.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup spa_param
 * \{
 */

struct spa_audio_info {
	uint32_t media_type;
	uint32_t media_subtype;
	union {
		struct spa_audio_info_raw raw;
		struct spa_audio_info_dsp dsp;
		struct spa_audio_info_iec958 iec958;
		struct spa_audio_info_dsd dsd;
		struct spa_audio_info_mp3 mp3;
		struct spa_audio_info_aac aac;
		struct spa_audio_info_vorbis vorbis;
		struct spa_audio_info_wma wma;
		struct spa_audio_info_ra ra;
		struct spa_audio_info_amr amr;
		struct spa_audio_info_alac alac;
		struct spa_audio_info_flac flac;
		struct spa_audio_info_ape ape;
		struct spa_audio_info_ape opus;
		struct spa_audio_info_ac3 ac3;
		struct spa_audio_info_eac3 eac3;
		struct spa_audio_info_truehd truehd;
		struct spa_audio_info_dts dts;
		struct spa_audio_info_mpegh mpegh;
	} info;

	/* padding follows here when info has flexible size */
};

/**
 * \}
 */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* SPA_PARAM_AUDIO_FORMAT_H */
