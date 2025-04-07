#!/usr/bin/bash

if g++ -g -o mathparser.out src/Main.cpp src/Lexer.cpp src/Parser.cpp src/Token.cpp src/Expression.cpp src/Exception.cpp; then
    echo 'built math parser'
else
    echo 'failed build xd'
fi
