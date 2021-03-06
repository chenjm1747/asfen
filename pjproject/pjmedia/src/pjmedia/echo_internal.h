/* $Id: echo_internal.h 1417 2007-08-16 10:11:44Z bennylp $ */
/* 
 * Copyright (C) 2003-2007 Benny Prijono <benny@prijono.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */
#ifndef __PJMEDIA_ECHO_INTERNAL_H__
#define __PJMEDIA_ECHO_INTERNAL_H__

#include <pjmedia/types.h>

PJ_BEGIN_DECL

/*
 * Simple echo suppressor
 */
PJ_DECL(pj_status_t) echo_supp_create(pj_pool_t *pool,
				      unsigned clock_rate,
				      unsigned samples_per_frame,
				      unsigned tail_ms,
				      unsigned latency_ms,
				      unsigned options,
				      void **p_state );
PJ_DECL(pj_status_t) echo_supp_destroy(void *state);
PJ_DECL(pj_status_t) echo_supp_playback(void *state,
					pj_int16_t *play_frm );
PJ_DECL(pj_status_t) echo_supp_capture(void *state,
				       pj_int16_t *rec_frm,
				       unsigned options );
PJ_DECL(pj_status_t) echo_supp_cancel_echo(void *state,
					   pj_int16_t *rec_frm,
					   const pj_int16_t *play_frm,
					   unsigned options,
					   void *reserved );

PJ_DECL(pj_status_t) speex_aec_create(pj_pool_t *pool,
				      unsigned clock_rate,
				      unsigned samples_per_frame,
				      unsigned tail_ms,
				      unsigned latency_ms,
				      unsigned options,
				      void **p_state );
PJ_DECL(pj_status_t) speex_aec_destroy(void *state );
PJ_DECL(pj_status_t) speex_aec_playback(void *state,
				        pj_int16_t *play_frm );
PJ_DECL(pj_status_t) speex_aec_capture(void *state,
				       pj_int16_t *rec_frm,
				       unsigned options );
PJ_DECL(pj_status_t) speex_aec_cancel_echo(void *state,
					   pj_int16_t *rec_frm,
					   const pj_int16_t *play_frm,
					   unsigned options,
					   void *reserved );


PJ_END_DECL

#endif

