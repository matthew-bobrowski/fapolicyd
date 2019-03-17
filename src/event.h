/*
 * event.h - Header file for event.c
 * Copyright (c) 2016,2018 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
 *
 * This software may be freely redistributed and/or modified under the
 * terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor
 * Boston, MA 02110-1335, USA.
 *
 * Authors:
 *   Steve Grubb <sgrubb@redhat.com>
 *   Radovan Sroka <rsroka@redhat.com>
 */

#ifndef EVENT_HEADER
#define EVENT_HEADER

#include <stdio.h>
#include <sys/types.h>
#include <sys/fanotify.h>
#include "subject.h"
#include "object.h"
#include "daemon-config.h"

typedef struct ev {
	pid_t pid;
	int fd;
	int type;
	s_array *s;
	o_array *o;
} event_t;

int init_event_system(struct daemon_conf *config);
int flush_cache(struct daemon_conf *config);
void destroy_event_system(void);
int new_event(const struct fanotify_event_metadata *m, event_t *e);
subject_attr_t *get_subj_attr(event_t *e, subject_type_t t);
object_attr_t *get_obj_attr(event_t *e, object_type_t t);
void run_usage_report(struct daemon_conf *config, FILE *f);

#endif
