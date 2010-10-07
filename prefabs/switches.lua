----------------------------------------------------------------
--  SWITCH PREFABS
----------------------------------------------------------------
--
--  Oblige Level Maker
--
--  Copyright (C) 2010 Andrew Apted
--
--  This program is free software; you can redistribute it and/or
--  modify it under the terms of the GNU General Public License
--  as published by the Free Software Foundation; either version 2
--  of the License, or (at your option) any later version.
--
--  This program is distributed in the hope that it will be useful,
--  but WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--  GNU General Public License for more details.
--
----------------------------------------------------------------

PREFAB.SMALL_SWITCH =
{
  brushes =
  {
    -- the base
    {
      { x = -40, y = -40, mat = "?base" },
      { x =  40, y = -40, mat = "?base" },
      { x =  56, y = -24, mat = "?base" },
      { x =  56, y =  24, mat = "?base" },
      { x =  40, y =  40, mat = "?base" },
      { x = -40, y =  40, mat = "?base" },
      { x = -56, y =  24, mat = "?base" },
      { x = -56, y = -24, mat = "?base" },
      { t = 12, light = 0.66, mat = "?base" },
    },

    -- switch itself
    {
      { x = -32, y = -8, mat = "?switch", special="?line_kind", tag="?tag", peg=1, x_offset="?x_offset", y_offset="?y_offset" },
      { x =  32, y = -8, mat = "?side" },
      { x =  32, y =  8, mat = "?side" },
      { x = -32, y =  8, mat = "?side" },
      { t = 76, light = 0.66, mat = "?side" },
    },
  },
}


PREFAB.WALL_SWITCH =
{
  placement = "fitted",

  brushes =
  {
    -- wall behind it
    {
      { x =   0, y =  0, mat = "?wall" },
      { x = 192, y =  0, mat = "?wall" },
      { x = 192, y =  4, mat = "?wall" },
      { x =   0, y =  4, mat = "?wall" },
    },

    -- area in front of it
    {
      { m = "walk" },
      { x =   0, y = 16 },
      { x = 192, y = 16 },
      { x = 192, y = 80 },
      { x =   0, y = 80 },
    },

    -- switch itself
    {
      { x =  64, y =  4 },
      { x = 128, y =  4 },
      { x = 128, y =  8, mat = "?switch", special="?line_kind", tag="?tag", peg=1, x_offset="?x_offset", y_offset="?y_offset" },
      { x =  64, y =  8 },
    },

    -- right side wall
    {
      { x = 0, y =  4, mat = "?wall" },
      { x = 8, y =  4, mat = "?wall" },
      { x = 8, y = 16, mat = "?wall" },
      { x = 0, y = 16, mat = "?wall" },
    },

    {
      { x =  8, y =  4, mat = "?wall" },
      { x = 64, y =  4, mat = "?side" },
      { x = 64, y = 16, mat = "?wall" },
      { x =  8, y = 16, mat = "?side" },
    },

    -- left side wall
    {
      { x = 184, y =  4, mat = "?wall" },
      { x = 192, y =  4, mat = "?wall" },
      { x = 192, y = 16, mat = "?wall" },
      { x = 184, y = 16, mat = "?wall" },
    },

    {
      { x = 128, y =  4, mat = "?wall" },
      { x = 184, y =  4, mat = "?side" },
      { x = 184, y = 16, mat = "?wall" },
      { x = 128, y = 16, mat = "?side" },
    },

    -- frame top
    {
      { x =  64, y =  4, mat = "?wall" },
      { x = 128, y =  4, mat = "?wall" },
      { x = 128, y = 16, mat = "?wall", blocked=1 },
      { x =  64, y = 16, mat = "?wall" },
      { b = 64, mat = "?ceil", light = "?light", special = "?special" },
    },

    -- frame bottom
    --[[
    {
      { x =  64, y =  4, mat = "?wall" },
      { x = 128, y =  4, mat = "?wall" },
      { x = 128, y = 16, mat = "?wall", blocked=1 },
      { x =  64, y = 16, mat = "?wall" },
      { t = 0, mat = "?floor" },
    },
    --]]
  },
}


PREFAB.QUAKE_WALL_SWITCH =
{
  placement = "fitted",

  brushes =
  {
    -- wall behind it
    {
      { x =   0, y =  0, mat = "?wall" },
      { x = 192, y =  0, mat = "?wall" },
      { x = 192, y = 16, mat = "?wall" },
      { x =   0, y = 16, mat = "?wall" },
    },
  },

  models =
  {
    -- button
    {
      x1 = 32, x2 = 96, x_face = { mat="METAL1_2" },
      y1 = 16, y2 = 32, y_face = { mat="BUTTON" },
      z1 = 24, z2 = 88, z_face = { mat="METAL1_2" },

      entity =
      {
        ent = "button", angle = 270, sounds = 2,
        target = "?target", wait ="?wait",
      },
    },
  },
}


