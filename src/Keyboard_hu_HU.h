/*
  Keyboard_hu_HU.h

  Copyright (c) 2022, Edgar Bonet

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef KEYBOARD_HU_HU_h
#define KEYBOARD_HU_HU_h

#include "HID.h"

#if !defined(_USING_HID)

#warning "Using legacy HID core (non pluggable)"

#else

//================================================================================
//================================================================================
//  Keyboard

// hu_HU keys
#define KEY_O_SLASH             0x2e
#define KEY_O_TWO_DOTS          0x27
#define KEY_O_DOUBLE_SLASH      0x2f

#define KEY_U_SLASH             0x30
#define KEY_U_TWO_DOTS          0x2d
#define KEY_U_DOUBLE_SLASH      0x31

#define KEY_A_SLASH             0x34

#define KEY_E_SLASH             0x33

#define KEY_I_SLASH             0x32

#endif
#endif