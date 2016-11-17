CFLAGS=-std=gnu99 -Iinc -ffreestanding -nostdlib
LDFLAGS=--melf_i386
ASMFLAGS=-felf
OBJECTS=obj/loader.o obj/kernel.o

compile: src/linker.ld $(OBJECTS)
	@ld $(LDFLAGS) -T $@ -o bin/kernel.bin $(OBJECTS)

clean_all: clean_o clean_bin

clean_o:
	@rm -rf obj/
	@mkdir obj/

clean_bin:
	@rm -rf bin/
	@mkdir bin/

obj/%.o: src/%.asm
	@nasm $(ASMFLAGS) -o $@ $<

obj/%.o: src/%.c
	@gcc $(CFLAGS) -o $@ -c $<
