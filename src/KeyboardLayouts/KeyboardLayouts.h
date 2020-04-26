/*
  KeyboardLayouts.h

  Author: MRNIU

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

#ifndef KEYBOARDLAYOUTS_h
#define KEYBOARDLAYOUTS_h

#define KB_BACKSPACE    (0x0E)
#define KB_ENTER        (0x1C)
#define KB_TAB          (0x0F)
#define KB_ESC          (0x01)
#define KB_SHIFT_L      (0x2A)
#define KB_SHIFT_R      (0x36)
#define KB_ALT_L        (0x38)
#define KB_CAPS_LOCK    (0x3A)
#define KB_CTRL_L       (0x1D)
#define KB_NUM_LOCK     (0x45)

// Number of columns in keyma
#define MAP_COLS        (3)
// Number of scan codes (rows in keymap)
#define MAP_LINES       (0x80)

// Press or release
#define RELEASED_MASK   (0x80)

// Normal function keys
#define FLAG_EXT        (0x00)

// Special keys
#define ESC             (0x01 & FLAG_EXT)
#define TAB             (0x02 & FLAG_EXT)
#define ENTER           (0x03 & FLAG_EXT)
#define BACKSPACE       (0x04 & FLAG_EXT)

#define GUI_L           (0x05 & FLAG_EXT)
#define GUI_R           (0x06 & FLAG_EXT)
#define APPS            (0x07 & FLAG_EXT)

// Shift, Ctrl, Alt
#define SHIFT_L         (0x08 & FLAG_EXT)
#define SHIFT_R         (0x09 & FLAG_EXT)
#define CTRL_L          (0x0A & FLAG_EXT)
#define CTRL_R          (0x0B & FLAG_EXT)
#define ALT_L           (0x0C & FLAG_EXT)
#define ALT_R           (0x0D & FLAG_EXT)

// Lock keys
#define CAPS_LOCK       (0x0E & FLAG_EXT)
#define NUM_LOCK        (0x0F & FLAG_EXT)
#define SCROLL_LOCK     (0x10 & FLAG_EXT)

// Function keys
#define F1              (0x11 & FLAG_EXT)
#define F2              (0x12 & FLAG_EXT)
#define F3              (0x13 & FLAG_EXT)
#define F4              (0x14 & FLAG_EXT)
#define F5              (0x15 & FLAG_EXT)
#define F6              (0x16 & FLAG_EXT)
#define F7              (0x17 & FLAG_EXT)
#define F8              (0x18 & FLAG_EXT)
#define F9              (0x19 & FLAG_EXT)
#define F10             (0x1A & FLAG_EXT)
#define F11             (0x1B & FLAG_EXT)
#define F12             (0x1C & FLAG_EXT)

// Control Pad
#define PRINTSCREEN     (0x1D & FLAG_EXT)
#define PAUSEBREAK      (0x1E & FLAG_EXT)
#define INSERT          (0x1F & FLAG_EXT)
#define DELETE          (0x20 & FLAG_EXT)
#define HOME            (0x21 & FLAG_EXT)
#define END             (0x22 & FLAG_EXT)
#define PAGEUP          (0x23 & FLAG_EXT)
#define PAGEDOWN        (0x24 & FLAG_EXT)
#define UP              (0x25 & FLAG_EXT)
#define DOWN            (0x26 & FLAG_EXT)
#define LEFT            (0x27 & FLAG_EXT)
#define RIGHT           (0x28 & FLAG_EXT)

// ACPI keys
#define POWER           (0x29 & FLAG_EXT)
#define SLEEP           (0x2A & FLAG_EXT)
#define WAKE            (0x2B & FLAG_EXT)

// Num Pad
#define PAD_SLASH       (0x2C & FLAG_EXT)
#define PAD_STAR        (0x2D & FLAG_EXT)
#define PAD_MINUS       (0x2E & FLAG_EXT)
#define PAD_PLUS        (0x2F & FLAG_EXT)
#define PAD_ENTER       (0x30 & FLAG_EXT)
#define PAD_DOT         (0x31 & FLAG_EXT)
#define PAD_0           (0x32 & FLAG_EXT)
#define PAD_1           (0x33 & FLAG_EXT)
#define PAD_2           (0x34 & FLAG_EXT)
#define PAD_3           (0x35 & FLAG_EXT)
#define PAD_4           (0x36 & FLAG_EXT)
#define PAD_5           (0x37 & FLAG_EXT)
#define PAD_6           (0x38 & FLAG_EXT)
#define PAD_7           (0x39 & FLAG_EXT)
#define PAD_8           (0x3A & FLAG_EXT)
#define PAD_9           (0x3B & FLAG_EXT)
#define PAD_UP          PAD_8
#define PAD_DOWN        PAD_2
#define PAD_LEFT        PAD_4
#define PAD_RIGHT       PAD_6
#define PAD_HOME        PAD_7
#define PAD_END         PAD_1
#define PAD_PAGEUP      PAD_9
#define PAD_PAGEDOWN    PAD_3
#define PAD_INS         PAD_0
#define PAD_MID         PAD_5
#define PAD_DEL         PAD_DOT

static uint8_t keymap[MAP_LINES * MAP_COLS] = {
    /* scan-code			!Shift		Shift		E0 XX	*/
    /* ==================================================================== */
    /* 0x00 - none	*/0,      0,      0,
    /* 0x01 - ESC		*/ESC,        ESC,        0,
    /* 0x02 - '1'		*/'1',        '!',        0,
    /* 0x03 - '2'		*/'2',        '@',        0,
    /* 0x04 - '3'		*/'3',        '#',        0,
    /* 0x05 - '4'		*/'4',        '$',        0,
    /* 0x06 - '5'		*/'5',        '%',        0,
    /* 0x07 - '6'		*/'6',        '^',        0,
    /* 0x08 - '7'		*/'7',        '&',        0,
    /* 0x09 - '8'		*/'8',        '*',        0,
    /* 0x0A - '9'		*/'9',        '(',        0,
    /* 0x0B - '0'		*/'0',        ')',        0,
    /* 0x0C - '-'		*/'-',        '_',        0,
    /* 0x0D - '='		*/'=',        '+',        0,
    /* 0x0E - BS		*/BACKSPACE,  BACKSPACE,  0,
    /* 0x0F - TAB		*/TAB,        TAB,        0,
    /* 0x10 - 'q'		*/'q',        'Q',        0,
    /* 0x11 - 'w'		*/'w',        'W',        0,
    /* 0x12 - 'e'		*/'e',        'E',        0,
    /* 0x13 - 'r'		*/'r',        'R',        0,
    /* 0x14 - 't'		*/'t',        'T',        0,
    /* 0x15 - 'y'		*/'y',        'Y',        0,
    /* 0x16 - 'u'		*/'u',        'U',        0,
    /* 0x17 - 'i'		*/'i',        'I',        0,
    /* 0x18 - 'o'		*/'o',        'O',        0,
    /* 0x19 - 'p'		*/'p',        'P',        0,
    /* 0x1A - '['		*/'[',        '{',        0,
    /* 0x1B - ']'		*/']',        '}',        0,
    /* 0x1C - CR/LF		*/ENTER,      ENTER,      PAD_ENTER,
    /* 0x1D - l. Ctrl	*/CTRL_L,     CTRL_L,     CTRL_R,
    /* 0x1E - 'a'		*/'a',        'A',        0,
    /* 0x1F - 's'		*/'s',        'S',        0,
    /* 0x20 - 'd'		*/'d',        'D',        0,
    /* 0x21 - 'f'		*/'f',        'F',        0,
    /* 0x22 - 'g'		*/'g',        'G',        0,
    /* 0x23 - 'h'		*/'h',        'H',        0,
    /* 0x24 - 'j'		*/'j',        'J',        0,
    /* 0x25 - 'k'		*/'k',        'K',        0,
    /* 0x26 - 'l'		*/'l',        'L',        0,
    /* 0x27 - ';'		*/';',        ':',        0,
    /* 0x28 - '\''		*/'\'',       '"',        0,
    /* 0x29 - '`'		*/'`',        '~',        0,
    /* 0x2A - l. SHIFT	*/SHIFT_L,    SHIFT_L,    0,
    /* 0x2B - '\'		*/'\\',       '|',        0,
    /* 0x2C - 'z'		*/'z',        'Z',        0,
    /* 0x2D - 'x'		*/'x',        'X',        0,
    /* 0x2E - 'c'		*/'c',        'C',        0,
    /* 0x2F - 'v'		*/'v',        'V',        0,
    /* 0x30 - 'b'		*/'b',        'B',        0,
    /* 0x31 - 'n'		*/'n',        'N',        0,
    /* 0x32 - 'm'		*/'m',        'M',        0,
    /* 0x33 - ','		*/',',        '<',        0,
    /* 0x34 - '.'		*/'.',        '>',        0,
    /* 0x35 - '/'		*/'/',        '?',        PAD_SLASH,
    /* 0x36 - r. SHIFT	*/SHIFT_R,    SHIFT_R,    0,
    /* 0x37 - '*'		*/'*',        '*',        0,
    /* 0x38 - ALT		*/ALT_L,      ALT_L,      ALT_R,
    /* 0x39 - ' '		*/' ',        ' ',        0,
    /* 0x3A - CapsLock	*/CAPS_LOCK,  CAPS_LOCK,  0,
    /* 0x3B - F1		*/F1,     F1,     0,
    /* 0x3C - F2		*/F2,     F2,     0,
    /* 0x3D - F3		*/F3,     F3,     0,
    /* 0x3E - F4		*/F4,     F4,     0,
    /* 0x3F - F5		*/F5,     F5,     0,
    /* 0x40 - F6		*/F6,     F6,     0,
    /* 0x41 - F7		*/F7,     F7,     0,
    /* 0x42 - F8		*/F8,     F8,     0,
    /* 0x43 - F9		*/F9,     F9,     0,
    /* 0x44 - F10		*/F10,        F10,        0,
    /* 0x45 - NumLock	*/NUM_LOCK,   NUM_LOCK,   0,
    /* 0x46 - ScrLock	*/SCROLL_LOCK,    SCROLL_LOCK,    0,
    /* 0x47 - Home		*/PAD_HOME,   '7',        HOME,
    /* 0x48 - CurUp		*/PAD_UP,     '8',        UP,
    /* 0x49 - PgUp		*/PAD_PAGEUP, '9',        PAGEUP,
    /* 0x4A - '-'		*/PAD_MINUS,  '-',        0,
    /* 0x4B - Left		*/PAD_LEFT,   '4',        LEFT,
    /* 0x4C - MID		*/PAD_MID,    '5',        0,
    /* 0x4D - Right		*/PAD_RIGHT,  '6',        RIGHT,
    /* 0x4E - '+'		*/PAD_PLUS,   '+',        0,
    /* 0x4F - End		*/PAD_END,    '1',        END,
    /* 0x50 - Down		*/PAD_DOWN,   '2',        DOWN,
    /* 0x51 - PgDown	*/PAD_PAGEDOWN,   '3',        PAGEDOWN,
    /* 0x52 - Insert	*/PAD_INS,    '0',        INSERT,
    /* 0x53 - Delete	*/PAD_DOT,    '.',        DELETE,
    /* 0x54 - Enter		*/0,      0,      0,
    /* 0x55 - ???		*/0,      0,      0,
    /* 0x56 - ???		*/0,      0,      0,
    /* 0x57 - F11		*/F11,        F11,        0,
    /* 0x58 - F12		*/F12,        F12,        0,
    /* 0x59 - ???		*/0,      0,      0,
    /* 0x5A - ???		*/0,      0,      0,
    /* 0x5B - ???		*/0,      0,      GUI_L,
    /* 0x5C - ???		*/0,      0,      GUI_R,
    /* 0x5D - ???		*/0,      0,      APPS,
    /* 0x5E - ???		*/0,      0,      0,
    /* 0x5F - ???		*/0,      0,      0,
    /* 0x60 - ???		*/0,      0,      0,
    /* 0x61 - ???		*/0,      0,      0,
    /* 0x62 - ???		*/0,      0,      0,
    /* 0x63 - ???		*/0,      0,      0,
    /* 0x64 - ???		*/0,      0,      0,
    /* 0x65 - ???		*/0,      0,      0,
    /* 0x66 - ???		*/0,      0,      0,
    /* 0x67 - ???		*/0,      0,      0,
    /* 0x68 - ???		*/0,      0,      0,
    /* 0x69 - ???		*/0,      0,      0,
    /* 0x6A - ???		*/0,      0,      0,
    /* 0x6B - ???		*/0,      0,      0,
    /* 0x6C - ???		*/0,      0,      0,
    /* 0x6D - ???		*/0,      0,      0,
    /* 0x6E - ???		*/0,      0,      0,
    /* 0x6F - ???		*/0,      0,      0,
    /* 0x70 - ???		*/0,      0,      0,
    /* 0x71 - ???		*/0,      0,      0,
    /* 0x72 - ???		*/0,      0,      0,
    /* 0x73 - ???		*/0,      0,      0,
    /* 0x74 - ???		*/0,      0,      0,
    /* 0x75 - ???		*/0,      0,      0,
    /* 0x76 - ???		*/0,      0,      0,
    /* 0x77 - ???		*/0,      0,      0,
    /* 0x78 - ???		*/0,      0,      0,
    /* 0x78 - ???		*/0,      0,      0,
    /* 0x7A - ???		*/0,      0,      0,
    /* 0x7B - ???		*/0,      0,      0,
    /* 0x7C - ???		*/0,      0,      0,
    /* 0x7D - ???		*/0,      0,      0,
    /* 0x7E - ???		*/0,      0,      0,
    /* 0x7F - ???		*/0,      0,      0
};

#endif  /* KEYBOARDLAYOUTS_h */
