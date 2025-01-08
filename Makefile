.PHONY: all build run clean

PROJECT_NAME := galactimus

all: build

compose:
	cmake -S . -B build

build:
	cmake --build build

run: build
	cd build/$(PROJECT_NAME) && ./$(PROJECT_NAME) && cd ../..

clean:
	rm -rf build
