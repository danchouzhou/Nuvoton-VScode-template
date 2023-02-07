include ../makefile.conf
NAME=HelloWorld

STARTUP_DEFS=-D__STARTUP_CLEAR_BSS -D__START=main

# Need following option for LTO as LTO will treat retarget functions as
# unused without following option
CFLAGS += -fno-builtin
CFLAGS += -D ARM_MATH_CM$(CORTEX_M)

LDSCRIPTS=-L. -L../$(BASE)/Library/Device/Nuvoton/$(DEVICE)/Source/GCC -T gcc_arm.ld

LFLAGS=$(USE_NANO) $(USE_NOHOST) $(LDSCRIPTS) $(GC) $(MAP)

IPATH =  .
IPATH += $(BASE)/Library/CMSIS/Include
IPATH += $(BASE)/Library/Device/Nuvoton/$(DEVICE)/Include
IPATH += $(BASE)/Library/StdDriver/inc
IPATH += User

BSP =  $(wildcard $(BASE)/Library/CMSIS/DSP_Lib/Source/*/*.c)
BSP += $(wildcard $(BASE)/Library/Device/Nuvoton/$(DEVICE)/Source/*.c)
BSP += $(wildcard $(BASE)/Library/Device/Nuvoton/$(DEVICE)/Source/GCC/*.c)
BSP += $(wildcard $(BASE)/Library/StdDriver/src/*.c)

LIB =  $(wildcard $(BASE)/*.c)

USR =  $(wildcard *.c)
USR += $(wildcard User/*.c)

OBJ_BSP = $(patsubst %.c,./Objects/%.o,$(notdir $(BSP)))
OBJ_LIB = $(patsubst %.c,./Objects/%.o,$(notdir $(LIB)))
OBJ_USR = $(patsubst %.c,./Objects/%.o,$(notdir $(USR)))

$(NAME): $(OBJ_USR) $(OBJ_LIB) $(OBJ_BSP)
	mkdir -p ./Objects
	cd ./Objects && $(CC) *.o $(CFLAGS) $(LFLAGS) $(addprefix ../,$(STARTUP)) -o $@.axf $(addprefix -I ../,$(IPATH))
	$(CP) -O binary ./Objects/$@.axf ./Objects/$@.bin

$(OBJ_USR): $(USR)
	mkdir -p ./Objects
	cd ./Objects && $(CC) $(addprefix ../,$^) $(CFLAGS) -c $(addprefix -I ../,$(IPATH))

$(OBJ_LIB): $(LIB)
	mkdir -p ./Objects
	cd ./Objects && $(CC) $(addprefix ../,$^) $(CFLAGS) -c $(addprefix -I ../,$(IPATH))

$(OBJ_BSP): $(BSP)
	mkdir -p ./Objects
	cd ./Objects && $(CC) $(addprefix ../,$^) $(CFLAGS) -c $(addprefix -I ../,$(IPATH))

clean:
	cd ./Objects && rm -f *.axf *.map *.o *.bin
