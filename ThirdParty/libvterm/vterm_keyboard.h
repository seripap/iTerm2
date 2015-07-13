// This code is based on vterm_keycodes.h but is hacked up to work in iTerm2.

#ifndef __VTERM_KEYCODES_H__
#define __VTERM_KEYCODES_H__

#include <stdint.h>

typedef enum {
  VTERM_MOD_NONE  = 0x00,
  VTERM_MOD_SHIFT = 0x01,
  VTERM_MOD_ALT   = 0x02,
  VTERM_MOD_CTRL  = 0x04,
} VTermModifier;

typedef enum {
  VTERM_KEY_NONE,

  VTERM_KEY_ENTER,
  VTERM_KEY_TAB,
  VTERM_KEY_BACKSPACE,
  VTERM_KEY_ESCAPE,

  VTERM_KEY_UP,
  VTERM_KEY_DOWN,
  VTERM_KEY_LEFT,
  VTERM_KEY_RIGHT,

  VTERM_KEY_INS,
  VTERM_KEY_DEL,
  VTERM_KEY_HOME,
  VTERM_KEY_END,
  VTERM_KEY_PAGEUP,
  VTERM_KEY_PAGEDOWN,

  VTERM_KEY_FUNCTION_0   = 256,
  VTERM_KEY_FUNCTION_MAX = VTERM_KEY_FUNCTION_0 + 255,

  VTERM_KEY_KP_0,
  VTERM_KEY_KP_1,
  VTERM_KEY_KP_2,
  VTERM_KEY_KP_3,
  VTERM_KEY_KP_4,
  VTERM_KEY_KP_5,
  VTERM_KEY_KP_6,
  VTERM_KEY_KP_7,
  VTERM_KEY_KP_8,
  VTERM_KEY_KP_9,
  VTERM_KEY_KP_MULT,
  VTERM_KEY_KP_PLUS,
  VTERM_KEY_KP_COMMA,
  VTERM_KEY_KP_MINUS,
  VTERM_KEY_KP_PERIOD,
  VTERM_KEY_KP_DIVIDE,
  VTERM_KEY_KP_ENTER,
  VTERM_KEY_KP_EQUAL,

  VTERM_KEY_MAX, // Must be last
} VTermKey;

enum {
    C1_SS3 = 0x8f,
    C1_DCS = 0x90,
    C1_CSI = 0x9b,
    C1_ST  = 0x9c,
};

#define VTERM_KEY_FUNCTION(n) (VTERM_KEY_FUNCTION_0+(n))

typedef struct {
    // Automatic Newline (LNM) (SM 20)
    int newline : 1;

    // Application cursor keys (DECSET 1)
    int cursor : 1;

    // Application keypad mode (DECSET 66)
    int keypad : 1;
} VTermOptions;

// Writes output to the master side of the PTY.
typedef void VTermWriteCallback(const char *, size_t);

// Use this for non-function keys. c should ignore all modifiers except shift.
void vterm_keyboard_unichar(uint32_t c, VTermModifier mod, VTermWriteCallback *callback);

// Use this for function keys.
void vterm_keyboard_key(VTermOptions *options, VTermKey key, VTermModifier mod, VTermWriteCallback *callback);

#endif  // __VTERM_KEYCODES_H__
