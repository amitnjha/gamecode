#!/bin/bash


chapter=Chapter06
game=6_3DStuff


echo "Starting Build of $chapter($game)"
mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders

#cd ../$chapter

g++ -o ~/Desktop/Games/$game/$game *.cpp `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -lassimp

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders
