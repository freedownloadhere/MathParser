CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
SET(CMAKE_CXX_STANDARD 20)
FILE(GLOB SOURCES "src/*cpp")

PROJECT(MathInteractive)
ADD_EXECUTABLE(MathInteractive ${SOURCES} "interactive/Interactive.cpp")
TARGET_INCLUDE_DIRECTORIES(MathInteractive PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

PROJECT(MathTests)
ADD_EXECUTABLE(MathTests ${SOURCES} "tests/Tests.cpp")
TARGET_INCLUDE_DIRECTORIES(MathTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
