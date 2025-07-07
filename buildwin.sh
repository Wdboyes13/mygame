x86_64-w64-mingw32-gcc \
  -I/opt/will/include \
  src/views/MainHelpers/UpdatePos.c src/StartMusic.c src/Setup.c src/views/MainView.c src/Game.c src/views/DeadView.c \
  -static-libgcc -static-libstdc++ \
  -L../WinSDL/ \
  -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lgdi32 -luser32 \
  -lkernel32 -lwinmm -lole32 -luuid -lsetupapi -lcfgmgr32 -limm32 -lversion -loleaut32 \
  -o game.exe
