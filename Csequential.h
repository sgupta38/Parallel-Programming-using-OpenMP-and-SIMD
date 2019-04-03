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
    bool generatePoints(long n);
    bool generatePointsEx(long n);
    bool printPoints();

};

#endif //ASSIGNMENT_2_SGUPTA38_CSEQUENTIAL_H
