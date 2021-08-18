PROJECT=main
ARCH=pic14
MODEL=16f877a
VOLTAGE=3.3

INCLUDES=-I. -I../include -I /usr/local/include
CFLAGS=$(INCLUDES) -Wa -w1 -D_PTC

OBJS=$(PROJECT).o $(patsubst %.asm,%.o,$(EXTRA_ASM)) \
                  $(patsubst %.c,%.o,$(EXTRA_C))

default:
	@echo "make build:     build $(PROJECT).hex"
	@echo "make detect:    check connection to MCU"
	@echo "make flash:     build and flash $(PROJECT).hex to PIC using pk2cmd"
	@echo "make flash:     build and flash $(PROJECT).hex to PIC using pk2cmd"
	@echo "make clean:     remove build files"

build: $(PROJECT).hex

.c.o:
	sdcc --use-non-free -m$(ARCH) -p$(MODEL) \
       $(SDCC_ARGS) $(CFLAGS) -c $<

$(patsubst %.asm,%.o,$(EXTRA_ASM)): %.o: %.asm
	gpasm -p$(MODEL) -c $<

$(PROJECT).hex: $(OBJS)
	sdcc --use-non-free -m$(ARCH) -p$(MODEL) \
       -Wl "-S2 -w -r -m" --out-fmt-ihx -o $(PROJECT).hex $(OBJS)

.PHONY: detect
detect:
	pk2cmd -P -A$(VOLTAGE) -T

.PHONY: flash
flash: $(PROJECT).hex
	pk2cmd -Ppic$(MODEL) -A$(VOLTAGE) -T -X -M -F $(PROJECT).hex

.PHONY: run
run:
	pk2cmd -Ppic$(MODEL) -A$(VOLTAGE) -T -R

clean:
	@rm -f *.o *.cod *.lst *.map *.hex \
        $(PROJECT).asm $(patsubst %.c,%.asm,$(EXTRA_C)) $(EXTRA_CLEAN)


