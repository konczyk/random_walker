# Random Walker 

Simple project to test SDL3 / C / CMAKE.

## Build

### cmake

Install `cmake` 3.30 or later from your Linux distribution or use `brew` on osx.

### SDL3

Download and unpack [SDL3](https://github.com/libsdl-org/SDL/releases/download/release-3.2.12/SDL3-3.2.12.tar.gz) into `vendor/SDL3` directory

### Compile

    $ cmake -DCMAKE_BUILD_TYPE=Release -B bin
    $ cmake --build bin

## Run

    $ ./bin/random_walker
