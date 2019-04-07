//
// Created by sonu on 4/2/19.
//

#include<iostream>
#include "CParallel.h"
#include <omp.h>

int
main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout<<"Usage: ./parallel_sphere <number_of_points>\n"<<endl;
        return 0;
    }

    std::string arg = argv[1];
    std::size_t pos;
    int N = std::stoi(arg, &pos);

    if(N <=0)
    {
        std::cout<<"Invalid Number of Points. "<<endl;
        return 0;
    }

    std::cout<<" Number of points: "<<N<<endl;
    CParallel par;
    par.generatePointsEx(N);
    par.plotGlobalGraph();
    return 0;
}
