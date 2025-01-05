.PHONY: all build run clean

# Extract project name from CMakeLists.txt
PROJECT_NAME := stellaris-2

all: build

compose:
	cmake -S . -B build

build:
	cmake --build build

run: build
	cd build/$(PROJECT_NAME) && ./$(PROJECT_NAME) && cd ../..

clean:
	rm -rf build
