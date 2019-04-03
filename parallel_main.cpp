//
// Created by sonu on 4/2/19.
//

#include "CParallel.h"
#include <omp.h>

int
main()
{
    // todo: Take number of threads from command line
    int numthreads = 4;
    omp_set_num_threads(numthreads);
    CParallel seq;
    seq.generatePoints(100, numthreads);
    vvvf res = seq.getPoints();
    return 0;
}
