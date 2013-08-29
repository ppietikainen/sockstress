/*
 * This file is part of the sockstress project.
 *
 * Copyright (C) 2008-2013 Outpost24 AB
 * (Written by Jack C. Louis for Outpost24 AB)
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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */


#ifndef _MAIN_H
# define _MAIN_H

#define MAX_FUNC_LIST_SIZE	128

typedef struct func_list_t {
	const char *name;
	char opt;
	void (*fp)(uint32_t, uint32_t, uint16_t, uint16_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int);
} func_list_t;

extern char pcap_errors[];
extern uint32_t intf_net, intf_mask;
extern uint8_t delay_type;
extern void update_tickcnt(void);

extern uint32_t tickcnt;
extern uint8_t gwmac[6], ea[6];
extern pcap_t *pdev;
extern unsigned int connections, max_conns;

extern func_list_t **fl;
extern unsigned int fl_off;

#endif
