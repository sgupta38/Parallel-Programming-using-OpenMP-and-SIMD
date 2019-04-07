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
    bool generatePointsEx(long n);
    bool printPoints();
    float *m_final;
    void plotGraph(int dim, vf& data, int save);
    void printBuckets(int, float [] );
    void plotGlobalGraph();

    CParallel()
    {
        m_final = nullptr;

        // Directories where graphs will be stored
        mkdir(GRAPH_PARALLEL, 0777);
    }

    ~CParallel()
    {
        if(m_final != nullptr)
            free(m_final);
    }
};

#endif //ASSIGNMENT_2_SGUPTA38_CPARALLEL_H
