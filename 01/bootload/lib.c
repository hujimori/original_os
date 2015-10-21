#include "defines.h"
#include "serial.h"
#include "lib.h"

int putc(unsigned char c) {
  if (c == '\n') 
    serial_send_byte(SERIAL_DEFAULT_DEVICE, '\r');
  return serial_is_send_enable(SERIAL_DEFAULT_DEVICE);
}

int puts(unsigned char *str) {
  while (*str) {
    putc(*(str++));
  }
  return 0;
}
