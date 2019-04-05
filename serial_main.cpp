//
// Created by sonu on 4/2/19.
//

#include "Csequential.h"

int
main()
{
    CSequential seq;
    seq.generatePointsEx(1000);
    vvf res = seq.getPoints();
    seq.printPoints();
    return 0;
}


