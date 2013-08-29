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

#ifndef _ATTACKS_H
# define _ATTACKS_H

extern uint16_t mywindow;

void init_attacks(void);

void do_0window_stress(
			uint32_t /* network order remote host	*/,
			uint32_t /* network order local host	*/,
			uint16_t /* network order remote port	*/,
			uint16_t /* network order local port	*/,
			uint32_t /* HOST order remote window	*/,
			uint32_t /* network order local seq #	*/,
			uint32_t /* network order remote seq #	*/,
			uint32_t /* timestamp 1 from remote	*/,
			uint32_t /* timestamp 2 from remote	*/,
			int      /* got timestamps at all	*/
		);

void do_smlwnd_stress(
			uint32_t /* network order remote host	*/,
			uint32_t /* network order local host	*/,
			uint16_t /* network order remote port	*/,
			uint16_t /* network order local port	*/,
			uint32_t /* HOST order remote window	*/,
			uint32_t /* network order local seq #	*/,
			uint32_t /* network order remote seq #	*/,
			uint32_t /* timestamp 1 from remote	*/,
			uint32_t /* timestamp 2 from remote	*/,
			int      /* got timestamps at all	*/
		);

void do_ooseg_stress(
			uint32_t /* network order remote host	*/,
			uint32_t /* network order local host	*/,
			uint16_t /* network order remote port	*/,
			uint16_t /* network order local port	*/,
			uint32_t /* HOST order remote window	*/,
			uint32_t /* network order local seq #	*/,
			uint32_t /* network order remote seq #	*/,
			uint32_t /* timestamp 1 from remote	*/,
			uint32_t /* timestamp 2 from remote	*/,
			int      /* got timestamps at all	*/
		);

void do_sillyface_stress(
			uint32_t /* network order remote host	*/,
			uint32_t /* network order local host	*/,
			uint16_t /* network order remote port	*/,
			uint16_t /* network order local port	*/,
			uint32_t /* HOST order remote window	*/,
			uint32_t /* network order local seq #	*/,
			uint32_t /* network order remote seq #	*/,
			uint32_t /* timestamp 1 from remote	*/,
			uint32_t /* timestamp 2 from remote	*/,
			int      /* got timestamps at all	*/
		);

void do_enablereno_stress(
			uint32_t /* network order remote host	*/,
			uint32_t /* network order local host	*/,
			uint16_t /* network order remote port	*/,
			uint16_t /* network order local port	*/,
			uint32_t /* HOST order remote window	*/,
			uint32_t /* network order local seq #	*/,
			uint32_t /* network order remote seq #	*/,
			uint32_t /* timestamp 1 from remote	*/,
			uint32_t /* timestamp 2 from remote	*/,
			int      /* got timestamps at all	*/
		);

#endif
