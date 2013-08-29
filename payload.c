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

#include "config.h"
#include "ext/makepkt.h"
#include "ext/tcphash.h"
#include "ext/packet_slice.h"
#include "ext/xmalloc.h"
#include "ext/packets.h"
#include "ext/xdelay.h"
#include "misc.h"

#include <pcap.h>

#include "attacks.h"
#include "main.h"

static char request[4096];

#define DEF_REQ \
	"GET / HTTP/1.1\r\n" \
	"Host: %s\r\n" \
	"User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.7.10) Gecko/20050726\r\n" \
	"Accept: image/png,*/*;q=0.5\r\n" \
	"Keep-Alive: 2400\r\n" \
	"Connection: keep-alive\r\n" \
	"Referer: http://localhost/bookmarks.html\r\n" \
	"\r\n"

char *get_payload(uint16_t port, uint32_t ip, char *hostname) {
	struct in_addr ia;
	unsigned int hport=0;

	ia.s_addr=ip;

	hport=(unsigned int )htons(port);

	memset(request, 0, sizeof(request));

	switch (hport) {
		case 22:
			snprintf(request, sizeof(request), "SSH-2.0-OpenSSH_5.0\r\n");
			break;
		default:
			snprintf(request, sizeof(request), DEF_REQ, hostname != NULL ? hostname : inet_ntoa(ia));
			break;
	}

	return request;
}
