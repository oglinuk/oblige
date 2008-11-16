//------------------------------------------------------------------------
//  EXTRA stuff for DOOM
//------------------------------------------------------------------------
//
//  Oblige Level Maker (C) 2008 Andrew Apted
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

#ifndef __OBLIGE_DM_EXTRA_H__
#define __OBLIGE_DM_EXTRA_H__

void BEX_Start();
void BEX_AddString(const char *key, const char *value);
void BEX_Finish();

void DDF_Start();
void DDF_AddString(const char *key, const char *value);
void DDF_Finish();

#endif /* __OBLIGE_DM_EXTRA_H__ */

//--- editor settings ---
// vi:ts=2:sw=2:expandtab
