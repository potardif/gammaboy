.PHONY: all clean mrproper

EXE = gammaboy

all: $(EXE)

$(EXE): *.cpp Makefile
	clang++ \
		main.cpp \
		-lnettle \
		-o $(EXE) \
		-O3 \
		-std=c++17 \
		-Weverything \
		-Wno-c++98-compat \
		-Wno-c++98-compat-pedantic \
		-Wno-c99-extensions \
		-Wno-global-constructors \
		-Wno-missing-prototypes \
		-Wno-missing-variable-declarations \
		-Wno-padded

clean:

mrproper: clean
	rm -f $(EXE)
