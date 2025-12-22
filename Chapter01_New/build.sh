#!/bin/bash

chapter=Chapter01_New
game=1_Pong_New


echo "Starting Build of $chapter($game)"

cd $chapter

mkdir -p ~/Desktop/Games/$game

g++ -o ~/Desktop/Games/$game/$game  Game.cpp Main.cpp `sdl2-config --cflags --libs`
