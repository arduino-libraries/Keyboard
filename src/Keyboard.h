/*
  Keyboard.h

  Copyright (c) 2015, Arduino LLC
  Original code (pre-library): Copyright (c) 2011, Peter Barrett

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

#ifndef KEYBOARD_h
#define KEYBOARD_h

#include "HID.h"

#if !defined(_USING_HID)

#warning "Using legacy HID core (non pluggable)"

#else

//================================================================================
//================================================================================
//  Keyboard

#define KEY_LEFT_CTRL     0x80		    // 128
#define KEY_LEFT_SHIFT    0x81		    // 129
#define KEY_LEFT_ALT      0x82		    // 130
#define KEY_LEFT_GUI      0x83		    // 131
#define KEY_RIGHT_CTRL    0x84		    // 132
#define KEY_RIGHT_SHIFT   0x85		    // 133
#define KEY_RIGHT_ALT     0x86		    // 134
#define KEY_RIGHT_GUI     0x87		    // 135

#define KEY_UP_ARROW      0xDA		    // 218
#define KEY_DOWN_ARROW    0xD9		    // 217
#define KEY_LEFT_ARROW    0xD8		    // 216
#define KEY_RIGHT_ARROW   0xD7		    // 215
#define KEY_BACKSPACE     0xB2		    // 178
#define KEY_TAB           0xB3		    // 179
#define KEY_RETURN        0xB0		    // 176
#define KEY_ESC           0xB1		    // 177
#define KEY_INSERT        0xD1		    // 209
#define KEY_DELETE        0xD4		    // 212
#define KEY_PAGE_UP       0xD3		    // 211
#define KEY_PAGE_DOWN     0xD6		    // 214
#define KEY_HOME          0xD2		    // 210
#define KEY_END           0xD5	    	// 213
#define KEY_CAPS_LOCK     0xC1		    // 193
#define KEY_F1            0xC2		    // 194
#define KEY_F2            0xC3		    // 195
#define KEY_F3            0xC4		    // 196
#define KEY_F4            0xC5		    // 197
#define KEY_F5            0xC6	    	// 198
#define KEY_F6            0xC7		    // 199
#define KEY_F7            0xC8		    // 200
#define KEY_F8            0xC9		    // 201
#define KEY_F9            0xCA		    // 202
#define KEY_F10           0xCB		    // 203
#define KEY_F11           0xCC		    // 204
#define KEY_F12           0xCD		    // 205
#define KEY_F13           0xF0		    // 240
#define KEY_F14           0xF1		    // 241
#define KEY_F15           0xF2		    // 242
#define KEY_F16           0xF3		    // 243
#define KEY_F17           0xF4		    // 244
#define KEY_F18           0xF5		    // 245
#define KEY_F19           0xF6		    // 246
#define KEY_F20           0xF7	    	// 247
#define KEY_F21           0xF8		    // 248
#define KEY_F22           0xF9		    // 249
#define KEY_F23           0xFA		    // 250
#define KEY_F24           0xFB	    	// 251


// Low level key report: up to 6 keys and shift, ctrl etc at once
typedef struct
{
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[6];
} KeyReport;

class Keyboard_ : public Print
{
private:
  KeyReport _keyReport;
  void sendReport(KeyReport* keys);
public:
  Keyboard_(void);
  void begin(void);
  void end(void);
  size_t write(uint8_t k);
  size_t write(const uint8_t *buffer, size_t size);
  size_t press(uint8_t k);
  size_t release(uint8_t k);
  void releaseAll(void);
};
extern Keyboard_ Keyboard;

#endif
#endif
