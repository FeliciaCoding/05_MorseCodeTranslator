cmake_minimum_required(VERSION 3.23)
project(05_Titanic)

set(CMAKE_CXX_STANDARD 17)

add_executable(05_Titanic main.cpp
        morseTranslator.cpp morseTranslator.h
        fileOperations.cpp fileOperations.h
        userInputs.cpp userInputs.h)
