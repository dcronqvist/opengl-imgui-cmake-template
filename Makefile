ifeq ($(OS),Windows_NT)
	SHELL := pwsh
	SHELL_FLAGS := -NoProfile -Command
	PLATFORM := win
	EXECUTABLE_SUFFIX := .exe
	RM := Remove-Item -Recurse -Force
else
	ifeq ($(shell uname -s),Darwin)
		PLATFORM := mac
	else
		PLATFORM := linux
	endif

	GENERATOR := Unix Makefiles
	EXECUTABLE_SUFFIX :=
	RM := rm -rf
endif

DEBUG_PRESET := debug-$(PLATFORM)
RELEASE_PRESET := release-$(PLATFORM)

.PHONY: build
build: build/release/CMakeCache.txt
	cmake --build --preset $(RELEASE_PRESET)

build/release/CMakeCache.txt:
	cmake --preset $(RELEASE_PRESET)

.PHONY: build-debug
build-debug: build/debug/CMakeCache.txt
	cmake --build --preset $(DEBUG_PRESET)

build/debug/CMakeCache.txt:
	cmake --preset $(DEBUG_PRESET)

.PHONY: run
run: build
	./build/release/opengl-imgui-cmake-template$(EXECUTABLE_SUFFIX)

.PHONY: debug
debug: build-debug
	cmake --build ./build --target vscode_debug_opengl-imgui-cmake-template

.PHONY: clean
clean:
	$(RM) build
