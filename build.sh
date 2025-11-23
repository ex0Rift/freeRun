#!/bin/bash
echo "Compiling..."
g++ main.cpp player.h player.cpp ground.h ground.cpp -o build -lraylib -lm -ldl -lGL -pthread
if [ $? -ne 0 ]; then
    echo "Compile failed! exiting..."
    exit 1
fi
./build