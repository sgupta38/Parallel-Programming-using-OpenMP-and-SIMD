//
// Created by sonu on 4/2/19.
//

#include "CParallel.h"
#include <omp.h>

int
main()
{
    CParallel par;
    par.generatePointsEx(100);
    vvf res = par.getPoints();
    par.printPoints();
    return 0;
}
