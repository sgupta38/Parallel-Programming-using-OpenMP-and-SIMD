//
// Created by sonu on 4/2/19.
//

#include <iostream>
#include "Csequential.h"
const int N = 1000; // number of points
int
main()
{
    std::cout<<" Number of points: "<<N<<endl;
    CSequential seq;
    seq.generatePointsEx(N);
    return 0;
}


