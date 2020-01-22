# Wolfram R184
Minimal implementation of [Wolfram's R184](https://en.wikipedia.org/wiki/Rule_184) with colored terminal output.

![screenshot](https://raw.githubusercontent.com/MaxMutantMayer/wolfram_r184/master/res/screenshot.png)

## Requirements
* CMake
* Terminal with color support

## Build
### Unix & Unix-Like
```
git clone https://github.com/MaxMutantMayer/wolfram_r184.git
cd wolfram_r184
mkdir build && cd build
cmake ..
make
```
### Windows
#### CMake GUI and Visual Studio
1. Run CMake GUI and specify paths to source and build directory, e.g. `C:/PathToProgram/wolfram_r184` and `C:/PathToProgram/wolfram_r184/build`.
2. Click `Configure` and choose wished toolchain
3. Click `Generate` to create VS solution
4. Open solution and build `wolfram_r184` project

#### Visual Studio only
VS 17 introduced built-in support for CMake. Simply open the project via `File -> Open -> CMake..` to build and run it.

## Usage
```
usage: wolfram_r184 <NumberOfTransitions>
```
