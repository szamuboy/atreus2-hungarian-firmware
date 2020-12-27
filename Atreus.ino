/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"
#include "Kaleidoscope-Leader.h"
#include "Kaleidoscope-MagicCombo.h"

#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_Plus LSHIFT(Key_Equals)

#define Key_Semicolon_Hun RALT(Key_Comma)
#define Key_Slash_Hun LSHIFT(Key_6)
#define Key_Minus_Hun Key_Slash
#define Key_Quote_Hun LSHIFT(Key_1)
#define Key_Exclamation_Hun LSHIFT(Key_4)
#define Key_At_Hun RALT(Key_V)
#define Key_Dollar_Hun RALT(Key_Semicolon)
#define Key_LeftParen_Hun Key_Star
#define Key_RightParen_Hun Key_LeftParen
#define Key_LeftBracket_Hun RALT(Key_F)
#define Key_RightBracket_Hun RALT(Key_G)
#define Key_LeftCurlyBracket_Hun RALT(Key_B)
#define Key_RightCurlyBracket_Hun RALT(Key_N)
#define Key_Caret_Hun RALT(Key_3)
#define Key_And_Hun RALT(Key_C)
#define Key_Star_Hun RALT(Key_Slash)
#define Key_Plus_Hun LSHIFT(Key_3)
#define Key_0_Hun Key_Backtick
#define Key_Equals_Hun LSHIFT(Key_7) 
#define Key_Backtick_Hun RALT(Key_7)
#define Key_Tilde_Hun RALT(Key_1)
#define Key_Backslash_Hun RALT(Key_Q)
#define Key_Pipe_Hun RALT(Key_W)
#define Key_I_Acute_Hun Key_NonUsBackslashAndPipe  // í
#define Key_E_Acute_Hun Key_Semicolon // é
#define Key_A_Acute_Hun Key_Quote // á
#define Key_O_Acute_Hun Key_Equals // ó
#define Key_U_Acute_Hun Key_RightBracket // ú
#define Key_O_Umlaut_Hun Key_0 // ö
#define Key_U_Umlaut_Hun Key_Minus // ü
#define Key_O_DoubleAcute_Hun Key_LeftBracket // ő
#define Key_U_DoubleAcute_Hun Key_Backslash // ű

enum {
  QWERTY,
  FUN,
  UPPER,
  QWERTY_HUN,
  QWERTY_SHIFT_HUN,
  FUN_HUN,
  UPPER_HUN
};


/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
       Key_Q   ,Key_W   ,Key_E       ,Key_R         ,Key_T
      ,Key_A   ,Key_S   ,Key_D       ,Key_F         ,Key_G
      ,Key_Z   ,Key_X   ,Key_C       ,Key_V         ,Key_B, Key_Backtick
      ,Key_Esc ,Key_Tab ,Key_LeftGui ,Key_LeftShift ,Key_Backspace ,Key_LeftControl

                     ,Key_Y     ,Key_U      ,Key_I     ,Key_O      ,Key_P
                     ,Key_H     ,Key_J      ,Key_K     ,Key_L      ,Key_Semicolon
       ,Key_Backslash,Key_N     ,Key_M      ,Key_Comma ,Key_Period ,Key_Slash
       ,Key_LeftAlt  ,Key_Space ,MO(FUN)    ,Key_Minus ,Key_Quote  ,Key_Enter
  ),

  [FUN] = KEYMAP_STACKED
  (
       Key_Exclamation ,Key_At           ,Key_UpArrow   ,Key_Dollar           ,Key_Percent
      ,Key_LeftParen   ,Key_LeftArrow    ,Key_DownArrow ,Key_RightArrow       ,Key_RightParen
      ,Key_LeftBracket ,Key_RightBracket ,Key_Hash      ,Key_LeftCurlyBracket ,Key_RightCurlyBracket ,Key_Caret
      ,TG(UPPER)       ,Key_Insert       ,Key_LeftGui   ,Key_LeftShift        ,Key_Delete         ,Key_LeftControl

                   ,Key_PageUp   ,Key_7 ,Key_8      ,Key_9 ,Key_Backspace
                   ,Key_PageDown ,Key_4 ,Key_5      ,Key_6 ,MoveToLayer(QWERTY_HUN)
      ,Key_And     ,Key_Star     ,Key_1 ,Key_2      ,Key_3 ,Key_Plus
      ,Key_LeftAlt ,Key_Space    ,___   ,Key_Period ,Key_0 ,Key_Equals
   ),

  [UPPER] = KEYMAP_STACKED
  (
       Key_Insert            ,Key_Home                 ,Key_UpArrow   ,Key_End        ,Key_PageUp
      ,Key_Delete            ,Key_LeftArrow            ,Key_DownArrow ,Key_RightArrow ,Key_PageDown
      ,M(MACRO_VERSION_INFO) ,Consumer_VolumeIncrement ,XXX           ,XXX            ,___ ,___
      ,MoveToLayer(QWERTY)   ,Consumer_VolumeDecrement ,___           ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7              ,Key_F8          ,Key_F9         ,Key_F10
                ,Key_DownArrow ,Key_F4              ,Key_F5          ,Key_F6         ,Key_F11
      ,___      ,XXX           ,Key_F1              ,Key_F2          ,Key_F3         ,Key_F12
      ,___      ,___           ,MoveToLayer(QWERTY) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   ),

  [QWERTY_HUN] = KEYMAP_STACKED
  (
       Key_Q   ,Key_W   ,Key_E       ,Key_R                ,Key_T
      ,Key_A   ,Key_S   ,Key_D       ,Key_F                ,Key_G
      ,Key_Y   ,Key_X   ,Key_C       ,Key_V                ,Key_B, LEAD(0)
      ,Key_Esc ,Key_Tab ,Key_LeftGui ,MO(QWERTY_SHIFT_HUN) ,Key_Backspace ,Key_LeftControl

                    ,Key_Z     ,Key_U       ,Key_I         ,Key_O         ,Key_P
                    ,Key_H     ,Key_J       ,Key_K         ,Key_L         ,Key_Semicolon_Hun
       ,LEAD(2)     ,Key_N     ,Key_M       ,Key_Comma     ,Key_Period    ,Key_Slash_Hun
       ,Key_LeftAlt ,Key_Space ,MO(FUN_HUN) ,Key_Minus_Hun ,Key_Quote_Hun ,Key_Enter
  ),

  [QWERTY_SHIFT_HUN] = KEYMAP_STACKED
  (
       LSHIFT(Key_Q)   ,LSHIFT(Key_W)   ,LSHIFT(Key_E)       ,LSHIFT(Key_R)         ,LSHIFT(Key_T)
      ,LSHIFT(Key_A)   ,LSHIFT(Key_S)   ,LSHIFT(Key_D)       ,LSHIFT(Key_F)         ,LSHIFT(Key_G)
      ,LSHIFT(Key_Y)   ,LSHIFT(Key_X)   ,LSHIFT(Key_C)       ,LSHIFT(Key_V)         ,LSHIFT(Key_B), LEAD(1)
      ,___             ,___             ,___                 ,___                   ,___          , ___

                ,LSHIFT(Key_Z)     ,LSHIFT(Key_U) ,LSHIFT(Key_I)                   ,LSHIFT(Key_O) ,LSHIFT(Key_P)
                ,LSHIFT(Key_H)     ,LSHIFT(Key_J) ,LSHIFT(Key_K)                   ,LSHIFT(Key_L) ,LSHIFT(Key_Semicolon_Hun)
       ,LEAD(3) ,LSHIFT(Key_N)     ,LSHIFT(Key_M) ,RALT(Key_NonUsBackslashAndPipe) ,RALT(Key_Z)   ,LSHIFT(Key_Comma)
       ,___     ,___               ,___           ,LSHIFT(Key_Minus_Hun)           ,LSHIFT(Key_2) ,___
  ),

  [FUN_HUN] = KEYMAP_STACKED
  (
       Key_Exclamation_Hun ,Key_At_Hun           ,Key_UpArrow   ,Key_Dollar_Hun           ,Key_Percent
      ,Key_LeftParen_Hun   ,Key_LeftArrow        ,Key_DownArrow ,Key_RightArrow           ,Key_RightParen_Hun
      ,Key_LeftBracket_Hun ,Key_RightBracket_Hun ,Key_Hash      ,Key_LeftCurlyBracket_Hun ,Key_RightCurlyBracket_Hun ,Key_Caret_Hun
      ,TG(UPPER_HUN)       ,Key_Insert           ,Key_LeftGui   ,Key_LeftShift            ,Key_Delete                ,Key_LeftControl

                   ,Key_PageUp   ,Key_7 ,Key_8      ,Key_9     ,Key_Backspace
                   ,Key_PageDown ,Key_4 ,Key_5      ,Key_6     ,MoveToLayer(QWERTY)
      ,Key_And_Hun ,Key_Star_Hun ,Key_1 ,Key_2      ,Key_3     ,Key_Plus_Hun
      ,Key_LeftAlt ,Key_Space    ,___   ,Key_Period ,Key_0_Hun ,Key_Equals_Hun
   ),

  [UPPER_HUN] = KEYMAP_STACKED
  (
       Key_Insert              ,Key_Home                 ,Key_UpArrow   ,Key_End        ,Key_PageUp
      ,Key_Delete              ,Key_LeftArrow            ,Key_DownArrow ,Key_RightArrow ,Key_PageDown
      ,M(MACRO_VERSION_INFO)   ,Consumer_VolumeIncrement ,XXX           ,XXX            ,___ ,___
      ,MoveToLayer(QWERTY_HUN) ,Consumer_VolumeDecrement ,___           ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7                  ,Key_F8          ,Key_F9         ,Key_F10
                ,Key_DownArrow ,Key_F4                  ,Key_F5          ,Key_F6         ,Key_F11
      ,___      ,XXX           ,Key_F1                  ,Key_F2          ,Key_F3         ,Key_F12
      ,___      ,___           ,MoveToLayer(QWERTY_HUN) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   )
)
/* *INDENT-ON* */


const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_QWERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(QWERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void tap(Key key) {
  kaleidoscope::hid::pressKey(key);
  kaleidoscope::hid::sendKeyboardReport();
  kaleidoscope::hid::releaseKey(key);
}

void switchLayout(uint8_t combo_index) {
  tap(LSHIFT(Key_RightShift));
}

USE_MAGIC_COMBOS([0] = {.action = switchLayout, .keys = {R2C5, R2C6}});

void leaderAcute(uint8_t sequence_index) {
  switch(sequence_index){
    case 0:
      tap(Key_Backtick_Hun);
      Leader.reset();
      break;
    case 1:
      tap(Key_I_Acute_Hun);
      Leader.reset();
      break;
    case 2:
      tap(Key_E_Acute_Hun);
      Leader.reset();
      break;
    case 3:
      tap(Key_A_Acute_Hun);
      Leader.reset();
      break;
    case 4:
      tap(Key_O_Acute_Hun);
      Leader.reset();
      break;
    case 5:
      tap(Key_U_Acute_Hun);
      Leader.reset();
      break;
    case 6:
      tap(Key_Tilde_Hun);
      Leader.reset();
      break;
    case 7:
      tap(LSHIFT(Key_I_Acute_Hun));
      Leader.reset();
      break;
    case 8:
      tap(LSHIFT(Key_E_Acute_Hun));
      Leader.reset();
      break;
    case 9:
      tap(LSHIFT(Key_A_Acute_Hun));
      Leader.reset();
      break;
    case 10:
      tap(LSHIFT(Key_O_Acute_Hun));
      Leader.reset();
      break;
    case 11:
      tap(LSHIFT(Key_U_Acute_Hun));
      Leader.reset();
      break;
    case 12:
      tap(Key_O_DoubleAcute_Hun);
      Leader.reset();
      break;
    case 13:
      tap(Key_U_DoubleAcute_Hun);
      Leader.reset();
      break;
    case 14:
      tap(LSHIFT(Key_O_DoubleAcute_Hun));
      Leader.reset();
      break;
    case 15:
      tap(LSHIFT(Key_U_DoubleAcute_Hun));
      Leader.reset();
      break;
    case 16:
      tap(Key_Backslash_Hun);
      Leader.reset();
      break;
    case 17:
      tap(Key_O_Umlaut_Hun);
      Leader.reset();
      break;
    case 18:
      tap(Key_U_Umlaut_Hun);
      Leader.reset();
      break;
    case 19:
      tap(Key_Pipe_Hun);
      Leader.reset();
      break;
    case 20:
      tap(LSHIFT(Key_O_Umlaut_Hun));
      Leader.reset();
      break;
    case 21:
      tap(LSHIFT(Key_U_Umlaut_Hun));
      Leader.reset();
      break;
  }
}

static const kaleidoscope::plugin::Leader::dictionary_t leader_dictionary[] PROGMEM =
  LEADER_DICT({LEADER_SEQ(LEAD(0), LEAD(0), LEAD(0)), leaderAcute},
              {LEADER_SEQ(LEAD(0), Key_I), leaderAcute},
              {LEADER_SEQ(LEAD(0), Key_E), leaderAcute},
              {LEADER_SEQ(LEAD(0), Key_A), leaderAcute},
              {LEADER_SEQ(LEAD(0), Key_O), leaderAcute},
              {LEADER_SEQ(LEAD(0), Key_U), leaderAcute},
              {LEADER_SEQ(LEAD(1), LEAD(1), LEAD(1)), leaderAcute},
              {LEADER_SEQ(LEAD(1), LSHIFT(Key_I)), leaderAcute},
              {LEADER_SEQ(LEAD(1), LSHIFT(Key_E)), leaderAcute},
              {LEADER_SEQ(LEAD(1), LSHIFT(Key_A)), leaderAcute},
              {LEADER_SEQ(LEAD(1), LSHIFT(Key_O)), leaderAcute},
              {LEADER_SEQ(LEAD(1), LSHIFT(Key_U)), leaderAcute},
              {LEADER_SEQ(LEAD(0), LEAD(0), Key_O), leaderAcute},
              {LEADER_SEQ(LEAD(0), LEAD(0), Key_U), leaderAcute},
              {LEADER_SEQ(LEAD(1), LEAD(1), LSHIFT(Key_O)), leaderAcute},
              {LEADER_SEQ(LEAD(1), LEAD(1), LSHIFT(Key_U)), leaderAcute},
              {LEADER_SEQ(LEAD(2), LEAD(2)), leaderAcute},
              {LEADER_SEQ(LEAD(2), Key_O), leaderAcute},
              {LEADER_SEQ(LEAD(2), Key_U), leaderAcute},
              {LEADER_SEQ(LEAD(3), LEAD(3)), leaderAcute},
              {LEADER_SEQ(LEAD(3), LSHIFT(Key_O)), leaderAcute},
              {LEADER_SEQ(LEAD(3), LSHIFT(Key_U)), leaderAcute}
              );

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Qukeys,
  SpaceCadet,
  OneShot,
  Macros,
  MouseKeys,
  Leader,
  MagicCombo
);

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.disable();
  Leader.dictionary = leader_dictionary;
}

void loop() {
  Kaleidoscope.loop();
}
