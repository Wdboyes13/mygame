#!/bin/sh
emcc --preload-file res src/Game.c src/Setup.c src/StartMusic.c \
    src/views/DeadView.c src/views/MainView.c src/views/MainHelpers/UpdatePos.c \
    -o index.html -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_MIXER=2 -s WASM=1 \
    -s EXIT_RUNTIME=1  -s FORCE_FILESYSTEM=1 -s ALLOW_MEMORY_GROWTH=1 \
    -s INITIAL_MEMORY=134217728 -s EXPORTED_RUNTIME_METHODS='["requestFullscreen"]' \
    -s SDL2_IMAGE_FORMATS='["png"]'