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

char *sockaddrstr(const struct sockaddr *in) {
        union {
                struct f_s *fs;
                const struct sockaddr *s;
                const struct sockaddr_in *sin;
                const struct sockaddr_in6 *sin6;
        } s_u;
        static char nbuf[256], *ret=NULL;
        const void *p=NULL;

        if (in == NULL) {
                return NULL;
        }

        s_u.s=in;

        switch (s_u.fs->family) {
                case AF_INET:
                        p=&s_u.sin->sin_addr;
                        break;

                case AF_INET6:
                        p=&s_u.sin6->sin6_addr;
                        break;

                default:
                        ERR("unknown address family `%d'", s_u.fs->family);
                        return NULL;
        }

        ret=inet_ntop(s_u.fs->family, p, nbuf, sizeof(nbuf) - 1);
        if (ret == NULL) {
                ERR("inet_ntop fails: %s", strerror(errno));
        }

        return ret;
}

