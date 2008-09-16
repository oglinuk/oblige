//------------------------------------------------------------------------
//  LEVEL building - DOOM format
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

#ifndef __OBLIGE_DOOM_OUT_H__
#define __OBLIGE_DOOM_OUT_H__


bool DM_Start(const char *filename);
bool DM_End(void);

void DM_BeginLevel(void);
void DM_EndLevel(const char *level_name);


/* ---- API for the CSG code to use ---- */

namespace wad
{
  void add_vertex(int x, int y);

  void add_sector(int f_h, const char * f_tex, 
                  int c_h, const char * c_tex,
                  int light, int special, int tag);

  void add_sidedef(int sector, const char *l_tex,
                   const char *m_tex, const char *u_tex,
                   int x_offset, int y_offset);

  void add_linedef(int vert1, int vert2, int side1, int side2,
                   int type,  int flags, int tag,
                   const byte *args);

  void add_thing(int x, int y, int h, int type, int angle, int options,
                 int tid, byte special, const byte *args);

  int num_vertexes(void);
  int num_sectors(void);
  int num_sidedefs(void);
}


/* ----- Level structures ---------------------- */

typedef struct
{
  s16_t x, y;
}
raw_vertex_t;


typedef struct
{
  u16_t start;     // from this vertex...
  u16_t end;       // ... to this vertex
  u16_t flags;     // linedef flags (impassible, etc)
  u16_t type;      // linedef type (0 for none, 97 for teleporter, etc)
  s16_t tag;       // this linedef activates the sector with same tag
  u16_t sidedef1;  // right sidedef
  u16_t sidedef2;  // left sidedef (only if this line adjoins 2 sectors)
}
raw_linedef_t;

typedef enum
{
  MLF_BlockAll      = 0x0001,
  MLF_BlockMonsters = 0x0002,
  MLF_TwoSided      = 0x0004,
  MLF_UpperUnpeg    = 0x0008,
  MLF_LowerUnpeg    = 0x0010,
  MLF_Secret        = 0x0020,
  MLF_SoundBlock    = 0x0040,
}
doom_lineflag_e;


typedef struct
{
  u16_t start;        // from this vertex...
  u16_t end;          // ... to this vertex
  u16_t flags;        // linedef flags (impassible, etc)
  u8_t  special;      // special type
  u8_t  args[5];      // special arguments
  u16_t sidedef1;     // right sidedef
  u16_t sidedef2;     // left sidedef
}
raw_hexen_linedef_t;


typedef struct
{
  s16_t x_offset;  // X offset for texture
  s16_t y_offset;  // Y offset for texture

  char upper_tex[8];  // texture name for the part above
  char lower_tex[8];  // texture name for the part below
  char mid_tex[8];    // texture name for the regular part

  u16_t sector;    // adjacent sector
}
raw_sidedef_t;


typedef struct
{
  s16_t floor_h;   // floor height
  s16_t ceil_h;    // ceiling height

  char floor_tex[8];  // floor texture
  char ceil_tex[8];   // ceiling texture

  u16_t light;     // light level (0-255)
  u16_t special;   // special behaviour (0 = normal, 9 = secret, ...)
  s16_t tag;       // sector activated by a linedef with same tag
}
raw_sector_t;


typedef struct
{
  s16_t x, y;      // position of thing
  s16_t angle;     // angle thing faces (degrees)
  u16_t type;      // type of thing
  u16_t options;   // when appears, deaf, etc..
}
raw_thing_t;

typedef enum
{
   MTF_Easy    = 1,
   MTF_Normal  = 2,
   MTF_Hard    = 4,
   MTF_Ambush  = 8,

   MTF_NotSP   = 16,
   MTF_NotDM   = 32,
   MTF_NotCOOP = 64,

   MTF_BOOM_Reserved = 256,
}
doom_thingflag_e;

#define MTF_EDGE_EXFLOOR_MASK    0x3C00
#define MTF_EDGE_EXFLOOR_SHIFT   10


typedef struct
{
  s16_t tid;       // thing tag id (for scripts/specials)
  s16_t x, y;      // position
  s16_t height;    // start height above floor
  s16_t angle;     // angle thing faces
  u16_t type;      // type of thing
  u16_t options;   // when appears, deaf, dormant, etc..

  u8_t special;    // special type
  u8_t args[5];    // special arguments
} 
raw_hexen_thing_t;


typedef struct
{
  char marker[4];  // 'ACS' 0

  u32_t offset;

  u32_t func_num;
  u32_t str_num;
}
raw_behavior_header_t;


#endif /* __OBLIGE_DOOM_OUT_H__ */

//--- editor settings ---
// vi:ts=2:sw=2:expandtab
