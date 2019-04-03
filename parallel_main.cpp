//
// Created by sonu on 4/2/19.
//

#include "CParallel.h"
#include <omp.h>

int
main()
{
    // todo: Take number of threads from command line
    int numthreads = 2;
    omp_set_num_threads(numthreads);
    CParallel par;
    par.generatePoints(100, numthreads);
    vvvf res = par.getPoints();
    return 0;
}
