set -eux

compfile(){
  FILE="$1"
  OUT="$2"
  x86_64-w64-mingw32-gcc \
  -c "$FILE" -I/opt/will/include -o "$OUT"

}

compfile src/views/MainView.c MainView.o
compfile src/views/DeadView.c DeadView.o
compfile src/views/MenuView.c MenuView.o
compfile src/views/WinView.c WinView.o
compfile src/views/CredsView.c CredsView.o
x86_64-w64-mingw32-ld -r MainView.o DeadView.o MenuView.o \
   WinView.o CredsView.o -o views.o

compfile src/ScoreRenderer/Init.c Init.o
compfile src/ScoreRenderer/RenderNum.c RenderNum.o
x86_64-w64-mingw32-ld -r Init.o RenderNum.o -o score.o

compfile src/StartMusic.c StartMusic.o
compfile  src/Setup.c Setup.o
compfile src/Game.c Game.o
compfile src/views/MainHelpers/UpdatePos.c UpdatePos.o
x86_64-w64-mingw32-ld -r StartMusic.o Setup.o Game.o UpdatePos.o -o main.o


x86_64-w64-mingw32-gcc \
  -I/opt/will/include \
  -static-libgcc -static-libstdc++ \
  -L../WinSDL \
  -o game.exe \
  views.o score.o main.o \
  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer \
  -lgdi32 -luser32 -lkernel32 -lwinmm -lole32 -luuid \
  -lsetupapi -lcfgmgr32 -limm32 -lversion -loleaut32 \
  -static

rm ./*.o

mkdir mygame
cp -r res game.exe mygame/
zip -9 -r mygame.zip mygame/