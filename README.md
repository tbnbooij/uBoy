# uBoy

uBoy ("microBoy") is an attempt at creating a small Game Boy emulator in C.

## Compiling from source
To build the project, make sure you have CMake 3.5 or higher installed. Create a build folder and execute the following commands from there.

```
$ cmake ..
```
This will create a makefile that can then be called by executing ```make``` in the same folder.

## Running the program
After compiling, the program can be started by adding a path to a Game Boy compatible ROM in .gb format. Due to legal reasons, these ROMS are not distributed through this repository.

```
$ ./uBoy ../ROM/tetris.gb
```
