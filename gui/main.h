//------------------------------------------------------------------------
//  Main defines
//------------------------------------------------------------------------
//
//  Oblige Level Maker (C) 2006-2008 Andrew Apted
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//------------------------------------------------------------------------

#ifndef __OBLIGE_MAIN_H__
#define __OBLIGE_MAIN_H__

#define OBLIGE_TITLE  "Oblige Level Maker"

#define OBLIGE_VERSION  "1.02"
#define OBLIGE_HEX_VER  0x102

extern const char *install_path;

void Main_FatalError(const char *msg, ...);

void Main_Ticker();

#endif /* __OBLIGE_MAIN_H__ */

//--- editor settings ---
// vi:ts=2:sw=2:expandtab
