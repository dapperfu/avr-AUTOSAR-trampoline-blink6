trampoline/machines/avr/arduino/cores/arduino/wiring_digital.c:
	git submodule foreach "git submodule update --init --depth 1"

trampoline/goil/makefile-unix/build.py:
	git submodule update --init --depth 1

.PHONY: trampoline_base
trampoline_base: trampoline/machines/avr/arduino/cores/arduino/wiring_digital.c trampoline/goil/makefile-unix/build.py

goil: trampoline/goil/makefile-unix/build.py
	python3 ${^}
	cp $(dir ${^})goil ./
