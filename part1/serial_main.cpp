//
// Created by sonu on 4/2/19.
//

#include <iostream>
#include "Csequential.h"
//const int N = 5000; // number of points
int
main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout<<"Usage: ./sequential_sphere <number_of_points>\n"<<endl;
        return 0;
    }

    std::string arg = argv[1];
    std::size_t pos;
    int N = std::stoi(arg, &pos);

    if(N <=0)
    {
        std::cout<<" Invalid Number of Points. "<<endl;
        return 0;
    }

    std::cout<<" Number of points: "<<N<<endl;
    CSequential seq;
    seq.generatePointsEx(N);
    return 0;
}


