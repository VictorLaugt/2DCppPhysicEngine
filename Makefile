all: build debugbuild

build:
	@echo "Creating build directory"
	mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release ..

debugbuild:
	@echo "Creating debug build directory"
	mkdir -p debugbuild && cd debugbuild && cmake -DCMAKE_BUILD_TYPE=Debug ..

clean:
	rm -rf build debugbuild

.PHONY: all build debugbuild
