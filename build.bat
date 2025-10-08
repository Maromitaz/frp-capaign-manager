@echo off

g++ ./src/main.cpp -L./thirdparty/raylib/lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -luser32 -lkernel32 -lm -I./thirdparty/raylib/include -std=c++23 -D_DEBUG -o ./build/app.exe