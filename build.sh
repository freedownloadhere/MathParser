#!/usr/bin/bash

if g++ -g -o mathparser.out src/main.cpp; then
    echo 'built math parser'
else
    echo 'failed build xd'
fi
