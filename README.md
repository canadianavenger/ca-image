# ca-image
Core imaging library for working with paletted images for my various projects. This repository contains no stand-alone executables. Instead it is meant to be included as a git module and linked into other projects.

## Library contents
- `include/image.h`: types, macros, and function declarations for the base image structure
  - `src/image.c`: allocation and freeing routines for the image structure
- `include/pal-tools.h`: types, macros, and function declarations for maniplating palettes
  - `src/pal-bits.c`: function for converting to/from RGB888 for 4-6 bits per component palettes
  - `src/pal-565.c`: function for converting to/from RGB888 for RGB565 palettes
  - `src/pal-order.c`: funsctions for remapping palette component ordering

## Adding ca-image to a project
To add this submodule into a folder perform the following command:

`git submodule add https://github.com/canadianavenger/ca-image.git <folder name>`

if `git` does not automatically include the contents into `<folder name>` perfrom the following

`git submodule update --init --recursive`

For more info: [Working with Submodules on GitHub](https://github.blog/open-source/git/working-with-submodules/)

