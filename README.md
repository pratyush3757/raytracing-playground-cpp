## raytracing-playground-cpp
[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)  

A Raytracer written in C++ to learn Raytracing
and other graphic concepts while following the book 
~~[Raytracing in one weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)~~ 
[The Ray Tracer Challenge](https://pragprog.com/titles/jbtracer/the-ray-tracer-challenge/).  

I was following the `Raytracing in one weekend` book series and felt the explanations to be not good enough.  
Switching the repository to follow `The Ray Trace Challenge`. Old code can be found in `deprecated_archive` branch.

More optimizations and extra features will be added as I progress through the book series, and get more in-depth insights through other papers.

TODO:
- [ ] Add PPM binary (P6) image support to complement and optimize PPM ascii (P3) format.
- [ ] Add [Sixel](https://en.wikipedia.org/wiki/Sixel) image support for terminal images.
- [ ] Add multithreading
- [ ] Add GPU offloading
- [ ] Add quake 3 fast inverse square root or some better algorithm
- [ ] Add glass [caustics](https://en.wikipedia.org/wiki/Caustic_(optics)) using depth maps [youtube extra resource link](https://www.youtube.com/watch?v=7l6QOcgWXfI)
