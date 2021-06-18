# PRelax

Simple Gauss Iteration for Solving Poisson's Equation Parallelized by OpenMP Directives

## Description and Purpose

This software is an educational software that demonstrates the use of OpenMP in a simple loop-oriented solution process.

## Contents of this Project

```
README       - this file
linux        - directory with makefile for Linux (serial version only)
mac          - directory with makefile for macOS
src_datapar  - directory with data parallel sources
src_serial   - directory with serial (base) sources
```

## What do do here

First, try to build the serial executable

Move into the appropriate directory (mac or linux) and look into the Makefile. If all settings are ok, try to build the serial executable by just typing

```
>%  make
```

If this fails, i cannot help :-)

Second, try to build the parallel executable. This should work with

```
>% make datapar
```

## How to run the program

You may run the serial program by just calling it on the command line, adding a vector length/matrix size like this:

```
%> main 513
```

To run the parallel version, you have to specify the number of usable 
threads (here 4) by first issuing (for bash, zsh, tsh, etc.)

```
%> export OMP_NUM_THREADS=4
```

Then you may simply run the parallel version by 

```
%> maindatapar 513
```

(c) 2021, Jörn Behrens (joern.behrens@uni-hamburg.de)