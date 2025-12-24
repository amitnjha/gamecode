#!/bin/bash


chapter=Chapter03
game=3_SpaceShip


echo "Starting Build of $chapter($game)"
mkdir -p ~/Desktop/Games/$game/Assets

#mkdir -p ~/Desktop/Games/$game/Shaders

#cd ../$chapter

g++ -o ~/Desktop/Games/$game/$game *.cpp `sdl2-config --cflags --libs` -lSOIL  -lSDL2_image

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

#cp -rf Shaders/* ~/Desktop/Games/$game/Shaders
