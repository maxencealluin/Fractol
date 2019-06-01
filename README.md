# Fractol
Interactive representation of different fractals. Written in C, using the MLX library, as part of the cursus at 42 Paris.

## Description

The goal of the project is to present the user with an interactive 2d representation of several fractals.
Fractals are mathematical objets which have the property of 'exhibiting similar patterns at increasingly small scales called self similarity'.

<img src="http://g.recordit.co/guNjGlKdLh.gif" width=500 height=500/>

Main features:
* Infinite zooming(up to computer capabilities) 
* 5 different types of fractals: Mandelbrot, Julia, Douady, burning_ship, burning_julia
* 10 colors sets
* Redefine julia fractals through mouse cursor ('L' key to activate)
* Manually adjust number of iterations

<img src="http://g.recordit.co/DpJv4uwGql.gif" width=500 height=500/>
<img src="http://g.recordit.co/9X4wusu1ye.gif" width=500 height=500/>

## Installation
***Only works on MacOS due to library***<br/>
To install simply type: <br/>
`make`

OpenGL has to be installed as it is required by the MLX library.

## Usage
`./fractol [mandelbrot/julia/douady/burning_ship/burning_julia]`
