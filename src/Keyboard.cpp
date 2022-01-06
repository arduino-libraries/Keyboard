/*
    Syonara - Arduino SS Micro (Leonardo) firmware for Razer Cynosa Lite and similar 
              single zone RGB keybaords

    Copyright 2022 Peter John 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    
*/

#include "Keyboard.h"
#include <Adafruit_NeoPixel.h>

#define MAX_COLUMNS              20
#define MAX_ROWS                  8

#define DEBUG                     1

#define SHIFT_OR_LOAD_PIN         2
#define CLOCK_PIN                 3
#define SERIAL_PIN                6
#define RED_PIN                   9
#define GREEN_PIN                10
#define BLUE_PIN                 11
#define COUNTER_2_RESET_PIN      15
#define COUNTER_2_CLOCK_PIN      16

#define NEOPIXEL_PIN             A0
#define COUNTER_1_RESET_PIN      A1
#define COUNTER_1_CLOCK_PIN      A2

// Neopixels 
#define CAPS_LOCK_LED             0
#define NUM_LOCK_LED              2
#define SCROLL_LOCK_LED           4
#define APPLICATION_LED           6
#define POWER_LED                 8

#define NUM_LEDS                  9
Adafruit_NeoPixel keyboard_status_leds(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
enum NeoPixelColors {
    Red    = 0xff0000,
    Orange = 0xffa500,
    Yellow = 0xffff00,
    Green  = 0x00ff00,
    Blue   = 0x0000ff,
    Indigo = 0x4b0082,
    Violet = 0x8a2be2,
    Purple = 0xff00ff,
    White  = 0xffffff,
    Black  = 0x000000
};

#if DEBUG
const char* keyboard_map_string[MAX_COLUMNS][MAX_ROWS] =
{
   //      0              1                 2                 3              4                 5                 6               7
   [0] = { " ",           "KEY_SCROLL_LOCK",0,                0,             0,                0,                0,              "KEY_PRINT_SCREEN"},
   [1] = { "4",           0,                0,                "KEY_KP_7",    "KEY_KP_8",       "KEY_KP_9",       "KEY_KP_PLUS",  "KEY_F5"          },
   [2] = { 0,             0,                0,                0,             "KEY_RIGHT_CTRL", 0,                "KEY_LEFT_CTRL",0                 },
   [3] = { 0  ,           0,                "KEY_MENU",       "KEY_LEFT_ALT",0,                "KEY_RIGHT_ALT",  0,              0                 },
   [4] = { "x",           "KEY_BACKSPACE",  0,                "KEY_F11",     "KEY_RETURN",     "KEY_F12",        "KEY_F9",       "KEY_F10"         },
   [5] = { "c",           "KEY_KP_4",       "KEY_KP_1",       0,             "KEY_NUM_LOCK",   "KEY_DOWN_ARROW", "KEY_DELETE",   0                 },
   [6] = { "3",           0,                0,                0,             0,                0,                0,              0                 },
   [7] = { "KEY_LEFT_GUI",0,                0,                0,             0,                0,                0,              0                 },
   [8] = { 0,             "KEY_LEFT_SHIFT", "KEY_RIGHT_SHIFT",0,             0,                0,                0,              0                 },
   [9] = { "2",           0,                "KEY_KP_ENTER",   "KEY_UP_ARROW",0,                "KEY_LEFT_ARROW", "KEY_HOME",     "KEY_END"         },
  [10] = { "1",           "KEY_KP_6",       "KEY_KP_3",       "KEY_KP_DOT",  "KEY_KP_ASTERISK","KEY_KP_MINUS",   "KEY_PAGE_UP",  "KEY_PAGE_DOWN"   },
  [11] = { "5",           "KEY_KP_5",       "KEY_KP_2",       "KEY_KP_0",    "KEY_KP_SLASH",   "KEY_RIGHT_ARROW","KEY_INSERT",   0                 },
  [12] = { "z",           "[",              ";",              "\'",          "\\",             "/",              "-",            "0"               },
  [13] = { "d",           "KEY_F7",         "l",              0,             ".",              "KEY_MENU",       "KEY_F8",       "9"               },
  [14] = { "s",           "]",              "k",              "KEY_F6",      ",",              0,                "=",            "8"               },
  [15] = { "a",           "y",              "j",              "h",           "m",              "n",              "6",            "7"               },
  [16] = { "KEY_TAB",     "t",              "f",              "g",           "v",              "b",              "p",            "o"               },
  [17] = { "e",           "KEY_F3",         0,                "KEY_F4",      0,                0,                "KEY_F2",       "i"               },
  [18] = { "w",           "KEY_CAPS_LOCK",  0,                "KEY_ISO",     0,                0,                "KEY_F1",       "u"               },
  [19] = { "q",           "KEY_PAUSE",      0,                "KEY_ESC",     0,                0,                "`",            "r"               }
};
#endif

#define KEY_ISO    0xEC
#define KEY_BSLASH 0xB9
const char keyboard_map_char[MAX_COLUMNS][MAX_ROWS] =
{
   //      0             1              2               3             4               5               6             7
   [0] = { ' ',         KEY_SCROLL_LOCK,0,              0,            0,              0,              0,            KEY_PRINT_SCREEN},
   [1] = { '4',         0,              0,              KEY_KP_7,     KEY_KP_8,       KEY_KP_9,       KEY_KP_PLUS,  KEY_F5          },
   [2] = { 0,           0,              0,              0,            KEY_RIGHT_CTRL, 0,              KEY_LEFT_CTRL,0               },
   [3] = { 0  ,         0,              KEY_MENU,       KEY_LEFT_ALT, 0,              KEY_RIGHT_ALT,  0,            0               },
   [4] = { 'x',         KEY_BACKSPACE,  0,              KEY_F11,      KEY_RETURN,     KEY_F12,        KEY_F9,       KEY_F10         },
   [5] = { 'c',         KEY_KP_4,       KEY_KP_1,       0,            KEY_NUM_LOCK,   KEY_DOWN_ARROW, KEY_DELETE,   0               },
   [6] = { '3',         0,              0,              0,            0,              0,              0,            0               },
   [7] = { KEY_LEFT_GUI,0,              0,              0,            0,              0,              0,            0               },
   [8] = { 0,           KEY_LEFT_SHIFT, KEY_RIGHT_SHIFT,0,            0,              0,              0,            0               },
   [9] = { '2',         0,              KEY_KP_ENTER,   KEY_UP_ARROW, 0,              KEY_LEFT_ARROW, KEY_HOME,     KEY_END         },
  [10] = { '1',         KEY_KP_6,       KEY_KP_3,       KEY_KP_DOT,   KEY_KP_ASTERISK,KEY_KP_MINUS,   KEY_PAGE_UP,  KEY_PAGE_DOWN   },
  [11] = { '5',         KEY_KP_5,       KEY_KP_2,       KEY_KP_0,     KEY_KP_SLASH,   KEY_RIGHT_ARROW,KEY_INSERT,   0               },
  [12] = { 'z',         '[',            ';',            '\'',         '\\',           '/',            '-',          '0'             },
  [13] = { 'd',         KEY_F7,         'l',            0,            '.',            KEY_MENU,       KEY_F8,       '9'             },
  [14] = { 's',         ']',            'k',            KEY_F6,       ',',            0,              '=',          '8'             },
  [15] = { 'a',         'y',            'j',            'h',          'm',            'n',            '6',          '7'             },
  [16] = { KEY_TAB,     't',            'f',            'g',          'v',            'b',            'p',          'o'             },
  [17] = { 'e',         KEY_F3,         0,              KEY_F4,       0,              0,              KEY_F2,       'i'             },
  [18] = { 'w',         KEY_CAPS_LOCK,  0,              KEY_ISO,      0,              0,              KEY_F1,       'u'             },
  [19] = { 'q',         KEY_PAUSE,      0,              KEY_ESC,      0,              0,              '`',          'r'             }
};

uint8_t last_incoming_bytes[MAX_COLUMNS];
uint8_t last_shift_register_byte;

int effect                      = 1;
bool key_down                   = false;
volatile bool led_status_update = true;
bool caps_lock_on               = false;
bool scroll_lock_on             = false;
bool num_lock_on                = false;
bool application_led_on         = false;
bool power_led_on               = true;

void setup() {
#if DEBUG
Serial.begin(250000);
while(!Serial);
Serial.println("Running");
#endif  

  // Timer0 is already used for millis() - we'll just interrupt somewhere
  // in the middle and call the "Compare A" function below
  OCR0A  =  0xAF;
  TIMSK0 |= _BV(OCIE0A);

  
  pinMode(      SHIFT_OR_LOAD_PIN,   OUTPUT);
  digitalWrite( SHIFT_OR_LOAD_PIN,   LOW);
  pinMode(      CLOCK_PIN,           OUTPUT);
  digitalWrite( CLOCK_PIN,           LOW);
  pinMode(      SERIAL_PIN,          INPUT);

  pinMode(      SHIFT_OR_LOAD_PIN,   OUTPUT);
  digitalWrite( SHIFT_OR_LOAD_PIN,   LOW);
  
  pinMode(      COUNTER_1_RESET_PIN, OUTPUT);
  digitalWrite( COUNTER_1_RESET_PIN, LOW);
  pinMode(      COUNTER_1_CLOCK_PIN, OUTPUT);
  digitalWrite( COUNTER_1_CLOCK_PIN, LOW);
  pinMode(      COUNTER_2_RESET_PIN, OUTPUT);
  digitalWrite( COUNTER_2_RESET_PIN, LOW);
  pinMode(      COUNTER_2_CLOCK_PIN, OUTPUT);
  digitalWrite( COUNTER_2_CLOCK_PIN, LOW);

  pinMode(      RED_PIN,             OUTPUT);
  digitalWrite( RED_PIN,             LOW);
  pinMode(      GREEN_PIN,           OUTPUT);
  digitalWrite( GREEN_PIN,           HIGH);
  pinMode(      BLUE_PIN,            OUTPUT);
  digitalWrite( BLUE_PIN,            LOW);

  memset(last_incoming_bytes, 0, sizeof(last_incoming_bytes));

  reset_decade_counters();
  
  keyboard_status_leds.begin();
  keyboard_status_leds.setBrightness(100); // (max = 255)

  Keyboard.begin();

  HID().setKeyboardLedsStatusReportCallback(keyboardLedsStatusReportCallback);

}

#if DEBUG
long cycles = 0;
long start  = millis();
long key_timer = micros();
#endif
void loop() {
  // static variables for better performance
  static bool    key_press_detected;
  static uint8_t incoming;
  static uint8_t incoming1;
  static uint8_t incoming2;
  static uint8_t column;
#if DEBUG
cycles++;
#endif
  key_press_detected = false;

  for (column = 0; column < (MAX_COLUMNS/2); column++)
  {
    incoming = read_shift_register_low_level();

    // if there is any keyboard activity... scan the keys
    if (incoming | last_incoming_bytes[column] | last_incoming_bytes[column+MAX_COLUMNS/2] )
    {
      key_timer=micros();
      incoming1 = read_shift_register( increment_decade_counter2 );
      decode( column,                 incoming1 );
      incoming2 = read_shift_register( increment_decade_counter1 );
      decode( column+(MAX_COLUMNS/2), incoming2 );
  
      key_press_detected = incoming1||incoming2||key_press_detected;
    }
        
    increment_decade_counters();
  }
  
  // Was any keypress detected?
  if (key_press_detected)
  {
    key_down=  true;
  }
  else // do idle stuff while no key pressed
  {
    // if a reset has been enabled because a key has been pressed
    if (key_down)
    {
      Keyboard.releaseAll();
      reset_decade_counters();
      key_down = false;
    }
  }
}

void reset_decade_counters()
{
//  digitalWrite(COUNTER_1_RESET_PIN , HIGH);
  PORTF |= (1<<PF6);// pinA1
//  digitalWrite(COUNTER_2_RESET_PIN , HIGH);
  PORTB |= (1<<PB1);// pin15
  __asm__("nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" ); // 375.0ns
//  digitalWrite(COUNTER_1_RESET_PIN , LOW);
  PORTF &= ~(1<<PF6);// pinA1
//  digitalWrite(COUNTER_2_RESET_PIN , LOW);
  PORTB &= ~(1<<PB1);// pin15
 
}

void increment_decade_counters( )
{
//  digitalWrite(COUNTER_1_CLOCK_PIN , HIGH);
  PORTF |= (1<<PF5);// pinA2
//  digitalWrite(COUNTER_2_CLOCK_PIN , HIGH);
  PORTB |= (1<<PB2);// pin16
  __asm__("nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" ); // 250.0ns: min clock pulse width is <200ns
//  digitalWrite(COUNTER_1_CLOCK_PIN , LOW);
  PORTF &= ~(1<<PF5);// pinA2
//  digitalWrite(COUNTER_2_CLOCK_PIN , LOW);
  PORTB &= ~(1<<PB2);// pin16

}

void increment_decade_counter1()
{
//  digitalWrite(COUNTER_1_CLOCK_PIN, HIGH);
  PORTF |= (1<<PF5);// pinA2
  __asm__("nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" ); // 250.0ns: min clock pulse width is <200ns
//  digitalWrite(COUNTER_1_CLOCK_PIN, LOW);
  PORTF &= ~(1<<PF5);// pinA2

}

void increment_decade_counter2()
{
//  digitalWrite(COUNTER_2_CLOCK_PIN, HIGH);
  PORTB |= (1<<PB2);// pin16
  __asm__("nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" ); // 250.0ns: min clock pulse width is <200ns
//  digitalWrite(COUNTER_2_CLOCK_PIN, LOW);
  PORTB &= ~(1<<PB2);// pin16

}
uint8_t read_shift_register( void (*increment_other_decade_counter)(void) )
{
  // static variables for better performance
  // Get data from 74HC165
  static uint8_t incoming;
  static uint8_t initial;
  static uint8_t result;
  static uint8_t other_column_increments;

  // read the value from the rows, 
  incoming = last_shift_register_byte;
  
  do
  {
    // if zero return (no further processing necessary: its zero)
    if (!incoming) return 0;
   
    initial   = incoming;

    // =========================================
    // now scan across the other 9 columns of the other decade counter
    // to eliminate false key presses

    (*increment_other_decade_counter)();

    for( other_column_increments=1; incoming && other_column_increments<((MAX_COLUMNS/2)) ; other_column_increments++)
    {
      incoming = incoming & read_shift_register_low_level();
      (*increment_other_decade_counter)();
    }
    // at this point incoming is still true and a loop of the other counter is complete, OR incoming is false, so resync counters
    for( ; other_column_increments<((MAX_COLUMNS/2)) ; other_column_increments++)
    {
      (*increment_other_decade_counter)();  
    }

    result = incoming;
    // We're back in sync. Has the shift register changed value while we've been away? if so, try again
  } while(initial != (incoming=read_shift_register_low_level()) );

  return result;
}

void decode( uint8_t column, uint8_t incoming_byte)
{
  // static variables for better performance
  static char key;
  static uint8_t row;
  static uint8_t row_bit_selector;
  static uint8_t last_incoming_byte;
  static uint8_t all_changed_bits;
  static uint8_t all_pressed_bits;
   
  last_incoming_byte = last_incoming_bytes[column];

  if (incoming_byte==last_incoming_byte) return; // nothing to do, nothing pressed or released

  // we're only interested in changed bits
  all_changed_bits = incoming_byte ^ last_incoming_byte; 
  all_pressed_bits = all_changed_bits & incoming_byte;
  
  // ignore those rows where changed bit is not set
  for(row=0,row_bit_selector = 1; !(row_bit_selector & all_changed_bits); row++, row_bit_selector<<=1 );

  // decode changed rows from first to last bit set, stops when row_bit_selector is shifted to zero
  for(; row_bit_selector && (row_bit_selector<=all_changed_bits); row++, row_bit_selector<<=1 )
  {
    key = keyboard_map_char[column][row];
    // is a key pressed that wasn't previously pressed? note the deliberate assignment to application_led_on
    if ((application_led_on = (all_pressed_bits & row_bit_selector)))
    {
#if DEBUG
      debugReportPressedKey(column, row, incoming_byte, last_incoming_byte);
#endif
Serial.println(((float)(micros()-key_timer))/1000000.0,9);
      Keyboard.press(key);
Serial.println(((float)(micros()-key_timer))/1000000.0,9);
      delay(5); // debounce
    }
    // a key released that was previously pressed has been released
    else 
    {
#if DEBUG
      debugReportReleasedKey(column, row, incoming_byte, last_incoming_byte);
#endif
      Keyboard.release(key);
    }
  }
  last_incoming_bytes[column]=incoming_byte;
}

uint8_t read_shift_register_low_level()
{
  static uint8_t incoming;

  // Loading time
  //  __asm__("nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" ); // 500ns delay; min input transition rise/fall time @ 4.5V is <500ns
  
  // Enable shifting
  //digitalWrite(CLOCK_PIN, HIGH);
  PORTD |= (1<<PD0);// pin3
  __asm__("nop\n\t"); // 62.5ns delay
  //digitalWrite(SHIFT_OR_LOAD_PIN, HIGH);
  PORTD |= (1<<PD1);// pin2
  __asm__("nop\n\t"); // 62.5ns delay

  // Get data from 74HC165
  incoming = shiftIn(SERIAL_PIN, CLOCK_PIN, MSBFIRST);
  last_shift_register_byte = incoming;
  
  // Enable loading
  //digitalWrite(SHIFT_OR_LOAD_PIN, LOW);
  PORTD &= ~(1<<PD1);// pin2

  return incoming;
}

// Interrupt is called once a millisecond, to update the LEDs
// Be careful in this function, it is easy to crash the MCU (requiring a reset to recover)

SIGNAL(TIMER0_COMPA_vect) 
{
  static int16_t  r,g,b; // 16 bit ints, by design
  static uint8_t  leds;
  static uint32_t backlight_color;
  
  // spread led update workload over 64x1ms timeslots to avoid spikes every millisecond
  switch( (millis() & 0b00111111) )
  {
    case 0b00000000:  // process red pwm output
      switch(effect)
      {
        case 1:
        case 2:     
          r = map((millis() & 0b0011111111000000),0,0b0011111111000000,-200,200);
          r = 50+abs(r);
          r = keyboard_status_leds.gamma8(r);
          break;
      }
      if (key_down||caps_lock_on)
      {
        analogWrite(RED_PIN, 254 );
      }
      else if (scroll_lock_on||num_lock_on)
      {
        analogWrite(RED_PIN,0 );
      }
      else
      {
        analogWrite(RED_PIN, r );
      }
      break;
    case 0b00010000: // process green pwm output
      switch(effect)
      {
        case 1:
          g = map((millis() & 0b0001111111000000),0,0b0001111111000000,-200,200);
          g = 50+abs(g);
          g = keyboard_status_leds.gamma8(g);
          break;
        case 2:
          g = 0;
          break;
      }
      if (key_down||scroll_lock_on)
      {
        analogWrite(GREEN_PIN, 254 );
      }
      else if (caps_lock_on||num_lock_on)
      {
        analogWrite(GREEN_PIN  ,0 );
      }
      else
      {
        analogWrite(GREEN_PIN, g );
      }
      break;
    case 0b00100000:  // process blue pwm output
      switch(effect) //blue
      {
        case 1:
          b = map((millis() & 0b0000111111000000),0,0b0000111111000000,-200,200);
          b = 50+abs(b);
          b = keyboard_status_leds.gamma8(b);
          break;
        case 2:
          b = 0;
          break;
      }
      if (key_down||num_lock_on)
      {
        analogWrite(BLUE_PIN, 254 );
      }
      else if (scroll_lock_on||caps_lock_on)
      {
        analogWrite(BLUE_PIN,   0 );
      }
      else
      {
        analogWrite(BLUE_PIN,  b );
      }
      break;
    case 0b00110000:  // process keyboard status LED Neopixel output
      if (led_status_update)
      {
        caps_lock_on   = Keyboard.getLedStatus(LED_CAPS_LOCK);
        scroll_lock_on = Keyboard.getLedStatus(LED_SCROLL_LOCK);
        num_lock_on    = Keyboard.getLedStatus(LED_NUM_LOCK);
        led_status_update = false;
      }
      backlight_color = keyboard_status_leds.Color(r,g,b);
      if (key_down)
      {
        for(leds=0; leds<NUM_LEDS; leds+=2)
          keyboard_status_leds.setPixelColor(leds, White);
      }
      else
      {
        for(leds=0; leds<NUM_LEDS; leds+=2)
          keyboard_status_leds.setPixelColor(leds, backlight_color);
      }

      if (caps_lock_on)       keyboard_status_leds.setPixelColor(CAPS_LOCK_LED,   Red);
      if (scroll_lock_on)     keyboard_status_leds.setPixelColor(SCROLL_LOCK_LED, Green);
      if (num_lock_on)        keyboard_status_leds.setPixelColor(NUM_LOCK_LED,    Blue);
      if (application_led_on) keyboard_status_leds.setPixelColor(APPLICATION_LED, Yellow);
      if (power_led_on)       keyboard_status_leds.setPixelColor(POWER_LED,       backlight_color);

      keyboard_status_leds.show();
      break;
  }
} 

void keyboardLedsStatusReportCallback()
{
  led_status_update = true;
}

#if DEBUG
void debugReportPressedKey(uint8_t column, uint8_t row, uint8_t incoming_byte, uint8_t last_incoming_byte)
{
  Serial.println("-----------------------------------");
  Serial.print("Row/Column [");
  Serial.print(row);
  Serial.print("/");
  Serial.print(column);
  Serial.println("]");
  Serial.println("Last Incoming/Incoming bits [");
  printByteAsBinary(last_incoming_byte,8);
  Serial.println("/");
  printByteAsBinary(incoming_byte,8);
  Serial.println("]");
  Serial.print("  Pressing [");
  Serial.print(keyboard_map_string[column][row]);
  Serial.println("]");
  Serial.print("Estimated scan rate [");
  Serial.println((((float)cycles)*1000.0)/((float)(millis()-start)));
  Serial.println("hz]");
cycles = 0;
start  = millis();
}

void debugReportReleasedKey(uint8_t column, uint8_t row, uint8_t incoming_byte, uint8_t last_incoming_byte)
{
  Serial.println("-----------------------------------");
  Serial.print("Row/Column [");
  Serial.print(row);
  Serial.print("/");
  Serial.print(column);
  Serial.println("]");
  Serial.println("Last Incoming/Incoming bits [");
  printByteAsBinary(last_incoming_byte,8);
  Serial.println("/");
  printByteAsBinary(incoming_byte,8);
  Serial.println("]"); 
  Serial.print("  Releasing [");
  Serial.print(keyboard_map_string[column][row]);
  Serial.println("]");
  Serial.print("Estimated scan rate [");
  Serial.println((((float)cycles)*1000.0)/((float)(millis()-start)));
  Serial.println("hz]");
cycles = 0;
start  = millis();
}

void printByteAsBinary(uint8_t number, uint8_t bits)
{
  uint8_t bit_index;

  bits = (bits>8)?8:bits;

  if (bits == 0)
  {
    return;
  }
  
  if (bits == 8)
  {
    Serial.println("  76543210");
    Serial.print("0b");
  }

  bit_index=1<<(bits-1);
  Serial.print((number & bit_index) ? '1' : '0');
  printByteAsBinary(number,bits-1);
}
#endif
