
install SDL2 and TTF

sudo apt install libsdl2-dev

sudo apt install libsdl2-ttf-dev 

Build

Chapter 1
g++  Game.cpp Main.cpp `sdl2-config --cflags --libs`

sudo apt install libsdl2-image-dev


Chapter 2
g++  *.cpp `sdl2-config --cflags --libs` -lSDL2_image

