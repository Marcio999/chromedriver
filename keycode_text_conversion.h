// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_TEST_CHROMEDRIVER_KEYCODE_TEXT_CONVERSION_H_
#define CHROME_TEST_CHROMEDRIVER_KEYCODE_TEXT_CONVERSION_H_

#include <string>

#include "build/build_config.h"
#include "ui/events/keycodes/keyboard_codes.h"

#if defined(USE_OZONE)
#include "ui/ozone/buildflags.h"
#endif

// These functions only support conversion of characters in the BMP
// (Basic Multilingual Plane).

// Coverts a key code and modifiers to the UTF8 text that would be produced
// with the current keyboard layout, or "" if no character would be produced.
// Returns "" if the produced text contains characters outside the BMP. If an
// error occurs |error_msg| will be set to the error message and will return
// false.
bool ConvertKeyCodeToText(ui::KeyboardCode key_code,
                          int modifiers,
                          std::string* text,
                          std::string* error_msg);

// Converts a character to the key code and modifiers that would produce
// the character using the current keyboard layout. Returns true on success.
// If an error occurs |error_msg| will be set to the error message, otherwise
// it will be set to the empty string.
bool ConvertCharToKeyCode(char16_t key,
                          ui::KeyboardCode* key_code,
                          int* necessary_modifiers,
                          std::string* error_msg);

#if BUILDFLAG(IS_WIN)
bool SwitchToUSKeyboardLayout();
#endif

#if defined(USE_OZONE)
#if BUILDFLAG(OZONE_PLATFORM_X11)
// Uses X11 implementation if there is an X display.
// TODO(crbug.com/987939): Support XKB.
bool ConvertKeyCodeToTextOzone(ui::KeyboardCode key_code,
                               int modifiers,
                               std::string* text,
                               std::string* error_msg);
bool ConvertCharToKeyCodeOzone(char16_t key,
                               ui::KeyboardCode* key_code,
                               int* necessary_modifiers,
                               std::string* error_msg);
#endif  // BUILDFLAG(OZONE_PLATFORM_X11)
#endif  // defined(USE_OZONE)

#endif  // CHROME_TEST_CHROMEDRIVER_KEYCODE_TEXT_CONVERSION_H_
