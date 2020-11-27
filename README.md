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
The BriskEngine is only support for Windows, but it was designed with cross-platform abilities by implementing the different abstract of window provider and renderer.

The table below shows the details of the platform to which BriskEngine applies:

| Graphic API | Supports Platform                 | Developer-side IDE        |      Progress      |
|:-----------:|:----------------------------------|:--------------------------|:------------------:|
|   Direct12  | Windows                           | VC++                      |    On going now    |

# Installation
BriskEngine is not a header-only C++ library. Just use the tools we provide from the outermost `tool` folder to simply deploy your development environment.

# Licences
Basically, BriskEngine uses the MIT license. At the same time, BriskEngine also uses following software as its dependencies:
- [CMake](https://cmake.org) as a general build tool.
- [ImGui](https://github.com/ocornut/imgui) as built-in GUI framework.
- [Boost](https://www.boost.org/) for using MPL and network function.
- (optional) [Google Test](https://github.com/google/googletest) for unit and performance testing.

# Architecture
```
.	
├── CMakelists.txt
├── LICENSE
├── README.md
├── cmake_val.cfg
├── framework                     <- Here is the source code of BriskEngine.
│   ├── IO
│   ├── audio
│   ├── common                    <- Common cross-platform C++ construction.
│   ├── event
│   ├── game_obj
│   ├── graphic
│   │   └── renderer              <- DX12 API is used here.
│   ├── physic
│   ├── platform
│   │   └── native_application    <- Provides the native game window.
│   └── ui
├── include                       <- The header files of BriskEngine API.
├── lib
├── src                           <- Developer-side sources.
└── tool
    └── build                     <- Scripts for build system.
```