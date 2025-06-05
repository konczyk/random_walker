# Random Walker 

Simple project to test SDL3 / C / CMAKE.

## Build

Install `cmake` 3.30 or later from your Linux distribution.

By default, SDL3 shared library is used to build the executable:

    $ cmake -B bin
    $ cmake --build bin

If you don't have SDL3 installed, or you want to use the source package,
download and unpack [SDL3](https://github.com/libsdl-org/SDL/releases/download/release-3.2.12/SDL3-3.2.12.tar.gz) into `vendor/SDL3` and execute:

    $ cmake -DVENDOR=ON -B bin 
    $ cmake --build bin

## Run

    $ ./bin/random_walker

![random walker](walker.gif)
