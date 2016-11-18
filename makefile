CFLAGS=-std=gnu99 -Iinc -ffreestanding -nostdlib
LDFLAGS=-melf_i386
ASMFLAGS=-felf
OBJECTS=obj/loader.o obj/string.o obj/port.o obj/console.o obj/kernel.o

compile_and_run: compile_and_geniso run

compile_and_geniso: compile generate_iso clean_o clean_bin

compile_and_clean: compile clean_o

compile: src/linker.ld $(OBJECTS)
	mkdir -p bin/
	@ld $(LDFLAGS) -T $< -o bin/kernel.bin $(OBJECTS)

clean_all: clean_o clean_bin clean_iso

clean_o:
	@rm -rf obj/*.o

clean_bin:
	@rm -rf bin/*.bin

clean_iso:
	@rm -rf isofiles/kernel.bin
	@rm -rf bin/*.iso

generate_iso:
	@cp bin/kernel.bin isofiles/kernel.bin
	@genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o bin/chicago.iso isofiles

run: generate_iso
	@(killall virtualbox && sleep 1) || true
	@virtualbox --startvm "ChicagoOS" &

obj/%.o: src/%.asm
	mkdir -p obj/
	@nasm $(ASMFLAGS) -o $@ $<

obj/%.o: src/%.c
	mkdir -p obj/
	@gcc $(CFLAGS) -o $@ -c $<
