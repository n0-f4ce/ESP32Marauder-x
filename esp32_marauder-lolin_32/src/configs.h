/**
 * @file configs.h
 * @brief This file contains configuration settings for the ESP32 Marauder-X project.
 *
 * The configurations include board targets, hardware names, board features, button definitions,
 * display definitions, menu definitions, SD definitions, and screen-related settings.
 * These settings can be modified to customize the behavior of the ESP32 Marauder-X project.
 */
#pragma once

#ifndef configs_h

  #define configs_h
  //// BOARD TARGETS
  #define MARAUDER_MINI
  //// END BOARD TARGETS
  #define MARAUDER_VERSION "v0.13.9"
  //// HARDWARE NAMES
  #ifdef MARAUDER_MINI
    #define HARDWARE_NAME "MarauderMini-X"
  #endif

  //// END HARDWARE NAMES

 //// BOARD FEATURES

  #ifdef MARAUDER_MINI
    //#define HAS_BATTERY
    #define HAS_BT
    #define HAS_BUTTONS
    #define HAS_NEOPIXEL_LED
    //#define HAS_PWR_MGMT
    #define HAS_SCREEN
    #define HAS_SD
    #define USE_SD
    #define HAS_TEMP_SENSOR
    #define HAS_GPS
  #endif
  //// END BOARD FEATURES

  //// BUTTON DEFINITIONS
  #ifdef HAS_BUTTONS
    #ifdef MARAUDER_MINI
      #define L_BTN 13
      #define C_BTN 34
      #define U_BTN 36
      #define R_BTN 39
      #define D_BTN 35

      #define HAS_L
      #define HAS_C
      #define HAS_U
      #define HAS_R
      #define HAS_D

      #define L_PULL true
      #define C_PULL true
      #define U_PULL true
      #define R_PULL true
      #define D_PULL true
    #endif
  #endif
  //// END BUTTON DEFINITIONS

  //// DISPLAY DEFINITIONS
  #ifdef HAS_SCREEN
    #ifdef MARAUDER_MINI
      #define SCREEN_CHAR_WIDTH 40
      #define TFT_MISO 19
      #define TFT_MOSI 23
      #define TFT_SCLK 18
      #define TFT_CS 2
      #define TFT_DC 26
      #define TFT_RST 5
      #define TFT_BL 32
      #define TOUCH_CS -1
      #define SD_CS 4
      #define SCREEN_BUFFER
      #define MAX_SCREEN_BUFFER 9
      #define BANNER_TEXT_SIZE 1

      #ifndef TFT_WIDTH
        #define TFT_WIDTH 128
      #endif

      #ifndef TFT_HEIGHT
        #define TFT_HEIGHT 128
      #endif

      #define CHAR_WIDTH 6
      #define SCREEN_WIDTH TFT_WIDTH // Originally 240
      #define SCREEN_HEIGHT TFT_HEIGHT // Originally 320
      #define HEIGHT_1 TFT_WIDTH
      #define WIDTH_1 TFT_WIDTH
      #define STANDARD_FONT_CHAR_LIMIT (TFT_WIDTH/6) // number of characters on a single line with normal font
      #define TEXT_HEIGHT (TFT_HEIGHT/10) // Height of text to be printed and scrolled
      #define BOT_FIXED_AREA 0 // Number of lines in bottom fixed area (lines counted from bottom of screen)
      #define TOP_FIXED_AREA 48 // Number of lines in top fixed area (lines counted from top of screen)
      #define YMAX TFT_HEIGHT // Bottom of screen area
      #define minimum(a,b)     (((a) < (b)) ? (a) : (b))
      //#define MENU_FONT NULL
      #define MENU_FONT &FreeMono9pt7b
      //#define MENU_FONT &FreeMonoBold9pt7b
      //#define MENU_FONT &FreeSans9pt7b
      //#define MENU_FONT &FreeSansBold9pt7b
      #define BUTTON_SCREEN_LIMIT 10
      #define BUTTON_ARRAY_LEN 100
      #define STATUS_BAR_WIDTH (TFT_HEIGHT/16)
      #define LVGL_TICK_PERIOD 6
      #define FRAME_X 100
      #define FRAME_Y 64
      #define FRAME_W 120
      #define FRAME_H 50
      // Red zone size
      #define REDBUTTON_X FRAME_X
      #define REDBUTTON_Y FRAME_Y
      #define REDBUTTON_W (FRAME_W/2)
      #define REDBUTTON_H FRAME_H
      // Green zone size
      #define GREENBUTTON_X (REDBUTTON_X + REDBUTTON_W)
      #define GREENBUTTON_Y FRAME_Y
      #define GREENBUTTON_W (FRAME_W/2)
      #define GREENBUTTON_H FRAME_H
      #define STATUSBAR_COLOR 0x4A49
    #endif
  #endif
  //// END DISPLAY DEFINITIONS

  //// MENU DEFINITIONS

  #ifdef MARAUDER_MINI
    #define BANNER_TIME 50
    #define COMMAND_PREFIX "!"
    // Keypad start position, key sizes and spacing
    #define KEY_X (TFT_WIDTH/2) // Centre of key
    #define KEY_Y (TFT_HEIGHT/4.5)
    #define KEY_W TFT_WIDTH // Width and height
    #define KEY_H (TFT_HEIGHT/12.8)
    #define KEY_SPACING_X 1 // X and Y gap
    #define KEY_SPACING_Y 1
    #define KEY_TEXTSIZE 1   // Font size multiplier
    #define ICON_W 22
    #define ICON_H 22
    #define BUTTON_PADDING 10
  #endif

  //// END MENU DEFINITIONS

  //// SD DEFINITIONS
  #if defined(USE_SD)
    #ifdef MARAUDER_MINI
      #define SD_CS 4
    #endif
  #endif
  //// END SD DEFINITIONS

  //// SCREEN STUFF
  #ifndef HAS_SCREEN
    #define TFT_WHITE 0
    #define TFT_CYAN 0
    #define TFT_BLUE 0
    #define TFT_RED 0
    #define TFT_GREEN 0
    #define TFT_GREY 0
    #define TFT_GRAY 0
    #define TFT_MAGENTA 0
    #define TFT_VIOLET 0
    #define TFT_ORANGE 0
    #define TFT_YELLOW 0
    #define STANDARD_FONT_CHAR_LIMIT 40
    #define FLASH_BUTTON -1

    #include <FS.h>
    #include <functional>
    #include <LinkedList.h>
    #include "SPIFFS.h"
    #include "Assets.h"
  #endif
  //// END SCREEN STUFF

  //// MEMORY LOWER LIMIT STUFF
  // These values are in bytes
  #ifdef MARAUDER_MINI
    #define MEM_LOWER_LIM 20000
  #endif
  //// END MEMORY LOWER LIMIT STUFF

  //// NEOPIXEL STUFF
  #ifdef HAS_NEOPIXEL_LED
      #define PIN 25
  #endif
  //// END NEOPIXEL STUFF

  //// EVIL PORTAL STUFF
  #ifdef MARAUDER_MINI
    #define MAX_HTML_SIZE 11400 //could be 20000?
  #endif
  //// END EVIL PORTAL STUFF

  //// GPS STUFF
  #ifdef HAS_GPS
    #ifdef MARAUDER_MINI
      #define GPS_SERIAL_INDEX 2
      #define GPS_TX 17
      #define GPS_RX 16
      #define mac_history_len 512
    #endif
  #endif
  //// END GPS STUFF

  //// MARAUDER TITLE STUFF
  #ifdef MARAUDER_MINI
    #define MARAUDER_TITLE_BYTES 13578
  #endif
  //// END MARAUDER TITLE STUFF
#endif
