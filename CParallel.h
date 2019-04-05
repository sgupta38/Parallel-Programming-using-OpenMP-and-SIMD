//
// Created by sonu on 4/2/19.
//

#ifndef ASSIGNMENT_2_SGUPTA38_CPARALLEL_H
#define ASSIGNMENT_2_SGUPTA38_CPARALLEL_H

#include "common.h"

class CParallel
{
private:
    vvf final_points;
public:
    const vvf &getPoints() const;
    int writeToFile();
    bool generatePoints(long n, int);
    bool generatePointsEx(long n);
    bool printPoints();
    float *m_final;
    void plotGraph(vf& data);
    CParallel()
    {
        m_final = nullptr;
    }

    ~CParallel()
    {
        if(m_final != nullptr)
            free(m_final);
    }
};

#endif //ASSIGNMENT_2_SGUPTA38_CPARALLEL_H
