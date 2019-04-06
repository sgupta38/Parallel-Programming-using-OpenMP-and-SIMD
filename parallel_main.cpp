//
// Created by sonu on 4/2/19.
//

#include<iostream>
#include "CParallel.h"
#include <omp.h>
const int N = 1000; // number of points

int
main()
{
    std::cout<<" Number of points: "<<N<<endl;
    CParallel par;
    par.generatePointsEx(N);
    return 0;
}
