# BriskEngine
A hardware-accelerated, simple **C++** game engine with data-oriented design.

# Introduction
BriskEngine is a modern C++ library and provides CPU acceleration, which powered by origin low-level instruction set such as SSE 4.2. It was inspired by [GameEngineFromScratch](https://github.com/netwarm007/GameEngineFromScratch).

BriskEngine provides the following features:
- High Performance. Using the SSE2/4.2 CPU instruction set to deliver a performance boost.
- MVVM and Data Binding.
  + You can define interfaces that required to build your own MVVM pattern in XML.
  + Using reflection you can set up data to control during runtime (On the roadmap till the C++23 is published).
- Develop your game using pure C++.

# Compatibility
Now BriskEngine is only support for Windows, but it was designed with cross-platform abilities by implementing the different abstract of window provider and renderer.

In the future, in order to support more platforms, we are considering adding other graphic API such as Vulkan or Mental.

The table below shows the details of the platform to which BriskEngine applies:

| Graphic API | Supports Platform            b    | Developer-side IDE        |      Progress      |
|:-----------:|:----------------------------------|:--------------------------|:------------------:|
|  Direct12   | Windows                           | VC++                      | On going now       |
|   OpenGl    | Windows/linux/Android/Mac OS/iOS  | VC++ / LLVM+Clang / Xcode | Under construction |
|   Vulkan    | Windows/linux/Android             | VC++ / LLVM+Clang         | Under construction |
|   Mental    | Mac OS/iOS                        | XCode                     | Under construction |

# Installation
BriskEngine is not a header-only C++ library. Just use the tools we provide from the outermost `Tool` folder to simply deploy your development environment.

# Licences
Basically, BriskEngine uses the MIT license. At the same time, BriskEngine also uses following software as its dependencies:
- [CMake](https://cmake.org) as a general build tool.
- [ImGui](https://github.com/ocornut/imgui) as built-in GUI framework.
- [Boost](https://www.boost.org/) for using MPL and network function.
- (optional) [Google Test](https://github.com/google/googletest) for unit and performance testing.

# Architecture
```
.
├─framework           <- Here is the source code of BriskEngine.
│  ├─audio
│  ├─common           <- Common cross-platform C++ construction.
│  │  ├─interface
│  │  └─utils
│  ├─event
│  ├─game_obj
│  ├─graphic
│  │  └─render
│  ├─IO
│  │  ├─file
│  │  └─network
│  ├─platform
│  │  ├─native_application
│  │  │  ├─linux
│  │  │  ├─mac_os
│  │  │  └─windows
│  │  └─native_window <- Providor of the game window.
│  └─ui
├─include             <- The header files of BriskEngine API.
├─lib
├─src                 <- Developer-side sources.
└─tool
    └─build           <-Scripts for build system.
        ├─linux
        └─windows
```