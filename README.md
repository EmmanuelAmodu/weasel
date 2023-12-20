# weasle
C++ Web development Library and Utilities.

## Setup conan for package management
https://docs.conan.io/1/installation.html

## Install CMake
https://cmake.org/download/

## Install Project dependencies
`conan install . -of ./dependencies`

## To run the project
* Run `cmake build . -DCMAKE_TOOLCHAIN_FILE=./dependencies/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release` to setup cmake project
* Run `cmake --build .` to build
* Run `./WeaselTestApp` to start sample server
