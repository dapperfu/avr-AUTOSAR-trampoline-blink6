# ENV Variables
TRAMPOLINE_ROOT:=$(realpath $(dir $(firstword ${MAKEFILE_LIST}))../trampoline)
GOIL_ROOT:=$(realpath ${TRAMPOLINE_ROOT}/goil)
GOIL_TEMPLATES:=$(realpath ${GOIL_ROOT}/templates)
GOIL_BIN:=$(realpath $(dir $(firstword ${MAKEFILE_LIST}))../goil)

ARDUINO_BOARD:=uno

CPP=$(wildcard *.cpp)
OIL=$(wildcard *.oil)
ELF=${CPP:.cpp=.elf}
HEX=${CPP:.cpp=.elf.hex}
ARDUINO_SERIAL:=/dev/ttyUSB0

.PHONY: all
all: ${HEX}.size ${ELF}.size

${HEX}: make.py ${CPP}
	python3 ${<} all

${HEX}.size: ${HEX}
	avr-size ${^} > ${@}

${ELF}.size: ${ELF}
	avr-size ${^} > ${@}

make.py: ${OIL}
	${GOIL_BIN} --target=avr/arduino/${ARDUINO_BOARD} --templates=${GOIL_TEMPLATES} ${<}

.PHONY: flash
flash: ${HEX}
	avrdude -carduino -v -V -patmega328p -P ${ARDUINO_SERIAL} -D -Uflash:w:${<}

.PHONY: format
format: ${CPP}
	clang-format-7 -i -style=LLVM ${^}

.PHONY: clean
clean:
	@rm -rf *.py build *.elf *.hex *.size
