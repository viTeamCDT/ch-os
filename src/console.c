#include <console.h>

uint16_t* consoleVidMem = (uint16_t*) 0xB8000;
uint8_t consoleX = 0;
uint8_t consoleY = 0;
uint8_t consoleBG = 0x00;
uint8_t consoleFG = 0x07;

void setConsoleColor(uint8_t bg, uint8_t fg)
{
	consoleBG = bg;
	consoleFG = fg;
}

void moveConsoleCursor()
{
	uint16_t consoleLoc = consoleY * 80 + consoleX;
	outb(0x3D4, 14);
	outb(0x3D5, consoleLoc >> 8);
	outb(0x3D4, 15);
	outb(0x3D5, consoleLoc);
}

void scrollConsole()
{
	uint16_t blank = 0x20 | (((consoleBG << 4) | (consoleFG & 0x0F)) << 8);
	if (consoleY >= 24)
	{
		for (int i = 0 * 80; i < 24 * 80; i++)
			consoleVidMem[i] = consoleVidMem[i + 80];
		for (int i = 24 * 80; i < 25 * 80; i++)
			consoleVidMem[i] = blank;
		consoleY = 0;
	}
}

void clearConsole()
{
	uint16_t blank = 0x20 | (((consoleBG << 4) | (consoleFG & 0x0F)) << 8);
	for (int i = 0; i < 80 * 25; i++)
		consoleVidMem[i] = blank;
	consoleX = consoleY = 0;
	moveConsoleCursor();
}

void putChar(char c)
{
	if (c == '\r')
		consoleX = 0;
	else if (c == '\n')
		consoleY++;
	else if (c >= ' ')
	{
		uint16_t ch = c | (((consoleBG << 4) | (consoleFG & 0x0F)) << 8);
		uint16_t* loc = consoleVidMem + (consoleY * 80 + consoleX);
		*loc = ch;
		consoleX++;
	}
	
	scrollConsole();
	moveConsoleCursor();
}

void putString(char* str)
{
	for (int i = 0; i < strlen(str); i++)
		putChar(str[i]);
}
