/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

// Include guard
#pragma once

// Keyboard Modifiers
enum KeyboardMods : uint16_t {
    MOD_LEFT_CTRL        = (1 <<  8),
    MOD_LEFT_SHIFT       = (1 <<  9),
    MOD_LEFT_ALT         = (1 << 10),
    MOD_LEFT_GUI         = (1 << 11),
    MOD_RIGHT_CTRL       = (1 << 12),
    MOD_RIGHT_SHIFT      = (1 << 13),
    MOD_RIGHT_ALT        = (1 << 14),
    MOD_RIGHT_GUI        = (uint16_t)(1 << 15),
};

// Keyboard Leds
enum KeyboardLeds : uint8_t {
    LED_NUM_LOCK         = (1 << 0),
    LED_CAPS_LOCK        = (1 << 1),
    LED_SCROLL_LOCK      = (1 << 2),
    LED_COMPOSE          = (1 << 3),
    LED_KANA             = (1 << 4),
    LED_POWER            = (1 << 5),
    LED_SHIFT            = (1 << 6),
    LED_DO_NOT_DISTURB   = (1 << 7),
};

#ifndef HID_CUSTOM_LAYOUT
#define HID_CUSTOM_LAYOUT
#define LAYOUT_US_ENGLISH
#endif

#if defined(LAYOUT_US_ENGLISH)
#include "ImprovedKeylayoutsUS.h"
#elif defined(LAYOUT_CANADIAN_FRENCH)
#elif defined(LAYOUT_CANADIAN_MULTILINGUAL)
#elif defined(LAYOUT_DANISH)
#elif defined(LAYOUT_FINNISH)
#elif defined(LAYOUT_FRENCH)
#elif defined(LAYOUT_FRENCH_BELGIAN)
#elif defined(LAYOUT_FRENCH_SWISS)
#elif defined(LAYOUT_GERMAN)
#include "ImprovedKeylayoutsDE.h"
#elif defined(LAYOUT_GERMAN_MAC)
#elif defined(LAYOUT_GERMAN_SWISS)
#elif defined(LAYOUT_ICELANDIC)
#elif defined(LAYOUT_IRISH)
#elif defined(LAYOUT_ITALIAN)
#elif defined(LAYOUT_NORWEGIAN)
#elif defined(LAYOUT_PORTUGUESE)
#elif defined(LAYOUT_PORTUGUESE_BRAZILIAN)
#elif defined(LAYOUT_SPANISH)
#elif defined(LAYOUT_SPANISH_LATIN_AMERICA)
#elif defined(LAYOUT_SWEDISH)
#elif defined(LAYOUT_TURKISH)
#elif defined(LAYOUT_UNITED_KINGDOM)
#elif defined(LAYOUT_US_INTERNATIONAL)
#endif
