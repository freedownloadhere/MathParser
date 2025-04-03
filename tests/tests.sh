#!/usr/bin/bash

if g++ -o mathtests.out -O2 Tests.cpp; then
    echo 'testing..'
    ./mathtests.out
    rm mathtests.out
    echo 'finished testing'
else
    echo 'failed build xd'
fi
