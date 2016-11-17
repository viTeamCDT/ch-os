void kmain()
{
	char* vidmem = (char*) 0xB8000;
	char* str = "Hello, World!";
	int x = 0;
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		vidmem[x++] = str[i];
		vidmem[x++] = 0x07;
	}
	
	while (true) ;
}