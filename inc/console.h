#ifndef CONSOLE_H
#define CONSOLE_H

#include <port.h>
#include <string.h>

void setConsoleColor(uint8_t bg, uint8_t fg);
void clearConsole();
void putChar(char c);
void putString(char* str);

#endif
