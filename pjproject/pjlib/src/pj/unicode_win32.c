/* $Id: unicode_win32.c 974 2007-02-19 01:13:53Z bennylp $ */
/* 
 * Copyright (C)2003-2007 Benny Prijono <benny@prijono.org>
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
#include <pj/unicode.h>
#include <pj/assert.h>
#include <pj/string.h>
#include <windows.h>


PJ_DEF(wchar_t*) pj_ansi_to_unicode(const char *s, pj_size_t len,
				    wchar_t *buf, pj_size_t buf_count)
{
    PJ_ASSERT_RETURN(s && buf, NULL);

    len = MultiByteToWideChar(CP_ACP, 0, s, len, 
			      buf, buf_count);
    buf[len] = 0;
    return buf;
}


PJ_DEF(char*) pj_unicode_to_ansi( const wchar_t *wstr, pj_size_t len,
				  char *buf, pj_size_t buf_size)
{
    PJ_ASSERT_RETURN(wstr && buf, NULL);

    len = WideCharToMultiByte(CP_ACP, 0, wstr, len, buf, buf_size, NULL, NULL);
    buf[len] = '\0';
    return buf;
}

