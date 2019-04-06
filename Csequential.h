//
// Created by sonu on 4/2/19.
//

#ifndef ASSIGNMENT_2_SGUPTA38_CSEQUENTIAL_H
#define ASSIGNMENT_2_SGUPTA38_CSEQUENTIAL_H

#include "common.h"

class CSequential
{
private:
    vvf final_points;
public:
    const vvf &getPoints() const;
    int writeToFile();
    bool generatePointsEx(long n);
    bool printPoints();
    void plotGraph(int dim, vf& data, int save);
    void printBuckets(int, float [] );
    CSequential()
    {
        // Directories where graphs will be stored
        mkdir(GRAPH_SEQUENTIAL, 0777);
    }
};

#endif //ASSIGNMENT_2_SGUPTA38_CSEQUENTIAL_H
