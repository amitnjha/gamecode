#!/bin/bash

chapter=Chapter01
game=1_Pong


echo "Starting Build of $chapter($game)"

cd $chapter

mkdir -p ~/Desktop/Games/$game

g++ -o ~/Desktop/Games/$game/$game  Game.cpp Main.cpp `sdl2-config --cflags --libs`

chapter=Chapter02
game=2_SpaceShip


cd ../$chapter

echo "Starting Build of $chapter($game)"

mkdir -p ~/Desktop/Games/$game/Assets

g++  -o ~/Desktop/Games/$game/$game *.cpp `sdl2-config --cflags --libs` -lSDL2_image
cp -rf Assets/* ~/Desktop/Games/$game/Assets/

chapter=Chapter03
game=3_SpaceShip

cd ../$chapter

echo "Starting Build of $chapter($game)"

mkdir -p ~/Desktop/Games/$game/Assets

g++  -o ~/Desktop/Games/$game/$game *.cpp `sdl2-config --cflags --libs` -lSDL2_image

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

chapter=Chapter04
game=4_AIPlanes

cd ../$chapter

echo "Starting Build of $chapter($game)"

mkdir -p ~/Desktop/Games/$game/Assets

g++  -o ~/Desktop/Games/$game/$game *.cpp `sdl2-config --cflags --libs` -lSDL2_image
cp -rf Assets/* ~/Desktop/Games/$game/Assets/

chapter=Chapter05
game=5_SpaceShip3D

cd ../$chapter

echo "Starting Build of $chapter($game)"
mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders


g++ -o ~/Desktop/Games/$game/$game *.cpp `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

chapter=Chapter06
game=6_3DStuff


echo "Starting Build of $chapter($game)"
mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders

cd ../$chapter

g++ -o ~/Desktop/Games/$game/$game *.cpp `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

chapter=Chapter07
game=7_3DStuff2


echo "Starting build $chapter($game)"

cd ../$chapter

mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders

g++ -o ~/Desktop/Games/$game/$game *.cpp -I ~/Downloads/fmodstudioapi20311linux/api/studio/inc -I ~/Downloads/fmodstudioapi20311linux/api/core/inc `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -L ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/ -L ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/ -lfmod -lfmodstudio

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

cp ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/* ~/Desktop/Games/$game/
cp ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/* ~/Desktop/Games/$game/


###########

chapter=Chapter08
game=8_SpaceShipController

echo "Starting build $chapter($game)"

cd ../$chapter

mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders

g++ -o ~/Desktop/Games/$game/$game *.cpp -I ~/Downloads/fmodstudioapi20311linux/api/studio/inc -I ~/Downloads/fmodstudioapi20311linux/api/core/inc `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -L ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/ -L ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/ -lfmod -lfmodstudio

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

cp ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/* ~/Desktop/Games/$game/
cp ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/* ~/Desktop/Games/$game/

###########

chapter=Chapter09
game=9_CameraWith3DStuff

echo "Starting build $chapter ($game)"

cd ../$chapter

mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders

g++ -o ~/Desktop/Games/$game/$game *.cpp -I ~/Downloads/fmodstudioapi20311linux/api/studio/inc -I ~/Downloads/fmodstudioapi20311linux/api/core/inc `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -L ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/ -L ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/ -lfmod -lfmodstudio

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

cp ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/* ~/Desktop/Games/$game/
cp ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/* ~/Desktop/Games/$game/

chapter=Chapter10
game=10_Collision

echo "Starting build $chapter ($game)"

cd ../$chapter

mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders
g++ -o ~/Desktop/Games/$game/$game *.cpp -I ~/Downloads/fmodstudioapi20311linux/api/studio/inc -I ~/Downloads/fmodstudioapi20311linux/api/core/inc `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -L ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/ -L ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/ -lfmod -lfmodstudio

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

cp ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/* ~/Desktop/Games/$game/
cp ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/* ~/Desktop/Games/$game/

#################

chapter=Chapter11
game=11_3DStuffUI

echo "Starting build $chapter ($game)"

cd ../$chapter

mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders
g++ -o ~/Desktop/Games/$game/$game *.cpp -I ~/Downloads/fmodstudioapi20311linux/api/studio/inc -I ~/Downloads/fmodstudioapi20311linux/api/core/inc `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -L ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/ -L ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/ -lfmod -lfmodstudio -lSDL2_ttf

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

cp ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/* ~/Desktop/Games/$game/
cp ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/* ~/Desktop/Games/$game/

#################

chapter=Chapter12
game=12_Skeleton

echo "Starting build $chapter ($game)"

cd ../$chapter

mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders
g++ -o ~/Desktop/Games/$game/$game *.cpp -I ~/Downloads/fmodstudioapi20311linux/api/studio/inc -I ~/Downloads/fmodstudioapi20311linux/api/core/inc `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -L ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/ -L ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/ -lfmod -lfmodstudio -lSDL2_ttf

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

cp ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/* ~/Desktop/Games/$game/
cp ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/* ~/Desktop/Games/$game/

######


chapter=Chapter13
game=13_IntGraphics

echo "Starting build $chapter ($game)"

cd ../$chapter

mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders
g++ -o ~/Desktop/Games/$game/$game *.cpp -I ~/Downloads/fmodstudioapi20311linux/api/studio/inc -I ~/Downloads/fmodstudioapi20311linux/api/core/inc `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -L ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/ -L ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/ -lfmod -lfmodstudio -lSDL2_ttf

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

cp ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/* ~/Desktop/Games/$game/
cp ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/* ~/Desktop/Games/$game/

######


chapter=Chapter14
game=14_LevelFiles

echo "Starting build $chapter ($game)"

cd ../$chapter

mkdir -p ~/Desktop/Games/$game/Assets

mkdir -p ~/Desktop/Games/$game/Shaders
g++ -o ~/Desktop/Games/$game/$game *.cpp -I ~/Downloads/fmodstudioapi20311linux/api/studio/inc -I ~/Downloads/fmodstudioapi20311linux/api/core/inc `sdl2-config --cflags --libs` -lGLEW -lGL -lSOIL -L ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/ -L ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/ -lfmod -lfmodstudio -lSDL2_ttf

cp -rf Assets/* ~/Desktop/Games/$game/Assets/

cp -rf Shaders/* ~/Desktop/Games/$game/Shaders

cp ~/Downloads/fmodstudioapi20311linux/api/core/lib/arm64/* ~/Desktop/Games/$game/
cp ~/Downloads/fmodstudioapi20311linux/api/studio/lib/arm64/* ~/Desktop/Games/$game/



