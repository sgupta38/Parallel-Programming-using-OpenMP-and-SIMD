# Parallel Programming using OpenMP and SIMD

[Problem Statement](http://www.cs.binghamton.edu/~kchiu/cs547/prog/3/)

**Note** : 
	- Used [Matplotlib](https://github.com/lava/matplotlib-cpp) , a 3rd party libary for plotting histograms.
	- No memory leaks in actual program[ I've verified] . However, since this 3rd paty has been included, it gives some memory leaks.

How to Run?

### Part 1: High-dimensional Sphere

To see actual results in graph, try to plot more than **1000** points.

To compile 

	> make

 This wll create two binaries. One of which represents generation of High Dimensional sphere in 'Sequential' way and another in 'Parallel' [ using openmp] way.

 To run Sequential version:

 	> ./sequential_sphere <number_of_points>

 To run Parallel versin:

 	> ./parallel_sphere <number_of_points>


 For each version, separate __'graphs_xxx'__ is created which has 'Histograms' of all points. A third party library is used for this.

#### Part 2: SIMD(AVX specification) for computing lengths of a sequence of line segments.

	Computing 24000000 segments and showing results on condole.

To compile:

	> make

To Run:

	> ./simd
