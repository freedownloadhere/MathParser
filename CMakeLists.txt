CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
SET(CMAKE_CXX_STANDARD 20)
FILE(GLOB SOURCES "source/*cpp")
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/headers)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/pch)

PROJECT(MathRepl)
ADD_EXECUTABLE(MathRepl ${SOURCES} "repl/Repl.cpp" )
TARGET_INCLUDE_DIRECTORIES(MathRepl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)
TARGET_PRECOMPILE_HEADERS(MathRepl PRIVATE "pch/Pch.hpp")

PROJECT(MathTests)
ADD_EXECUTABLE(MathTests ${SOURCES} "tests/Tests.cpp" )
TARGET_INCLUDE_DIRECTORIES(MathTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)
