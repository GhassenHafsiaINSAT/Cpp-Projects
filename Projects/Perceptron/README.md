# Perceptron Implementation

C++ Implementation of Perceptron.

## Tables of Contents

- [Introduction](#introduction)
- [Dependencies](#dependencies)
- [Project Structure](#project-structure)
- [The Static Library's functionalities](#the-static-librarys-functionalities)
- [Installation](#installation)
  - [Include in Cmake](#cmake)
  - [Build by yourself](#build)
- [What is Perceptron](#what-is-perceptron)
  - [Historical Developement](#historical-development)
  - [Algorithm Definition](#algorithm-definition)
  - [References](#references)
- [Contributing](#contributions)
- [License](./LICENSE)

## Introduction

Perceptron will be my first project in a series of different projects/programs. I am planning on working on implementing research papers, concepts, algorithms, and systems.

Perceptron is a fairly simple and intuitive concept, yet in implementation, it proves to be a bit hard, especially in C++.

For this reason, I decided to start out with Perceptron.

Most of these projects will be written in C++.

## Dependencies

- A C++ Compiler.
- ***Cmake*** version **3.29** or above.
- ***Git*** needed by `FetchContent` to get the contents of repo releases.

## Project Structure

This project will be divided into:

- a ***`static library`*** containing the Perceptron algorithm functions.
- a ***`main function`*** for testing the static library.

***NOTE:*** **The Static library will be available for usage either downloaded and build manually or using CMake.**

## The Static Library's functionalities

These are the functionalities provided by the `static library`:

- **forward propagation**.
- **backward propagation**.

## Installation

To use Perceptron Algorithms in your C++ Project you need to include it either as a static library or a dynamic library.

You can either build the project on your own and tweak the build process as you wish or include it in your favourite IDE or your Cmake Definition.

### Cmake

In Cmake, we can use the `FetchContent` module to fetch a release of the library from GitHub.

```cmake
include(FetchContent)
FetchContent_Declare(
    PERCEPTRON
    GIT_REPOSITORY https://github.com/RaedAddala/Perceptron-in-Cpp.git
    GIT_TAG master
) 
# master tag used to get the latest - change if you need a certain version
FetchContent_MakeAvailable(PERCEPTRON)
```

and then link it to your project using:

```cmake
target_link_libraries( ${PROJECT_NAME} PRIVATE PERCEPTRON::PERCEPTRON )
```

Other methods can be used. This is only my preference.

### Build

To build this Library, follow these steps:

1. Create a folder for the build result (I always name it build)
2. At the build folder, Run this command

   `cmake ../src/ -G "<GENERATOR>"`

    I want to use Gnu Make so here is the command I use:

   `cmake ../src/ -G "MinGW Makefiles"`

   **Note:** Change the Cmake generator according to your preferences.

   Check **cmake --help** command for further information about different generators.

3. In the build folder, build your project depending on what generator you have used. If you have used Makefiles, just run the **make** command.
4. After completing the build, clean the directory. If you have used Makefiles, just run the **make clear** command.

***NOTE:***
The default Build Type is Release. This enables -O3 optimisation flag.

To build without any optimizations for Debugging, add this flag when building with Cmake: `-DCMAKE_BUILD_TYPE=Debug`

## What is Perceptron

### Historical Development

### Algorithm Definition

### References

## Contributions

This Perceptron Implementation is a small project I made for the fun of it. Contributions and feedback are most welcomed.

Whether you have ideas for improvements, encounter issues, or want to submit pull requests to enhance the functionality, your input is appreciated and welcomed.

### How to Contribute

1. **Issues**: If you encounter any bugs, have feature requests, or want to discuss potential improvements, please open an issue on the [issue tracker](https://github.com/RaedAddala/Perceptron-in-Cpp/issues/new).

2. **Pull Requests**: If you'd like to contribute directly to the codebase, feel free to fork the repository, make changes and submit a [pull request](https://github.com/RaedAddala/Perceptron-in-Cpp/compare).

**Otherwise,** all contributions and suggestions are welcome.

### Note

Thank you for your interest and support! :)
