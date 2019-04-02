//
// Created by sonu on 4/2/19.
//

#ifndef ASSIGNMENT_2_SGUPTA38_CSEQUENTIAL_H
#define ASSIGNMENT_2_SGUPTA38_CSEQUENTIAL_H

#include "common.h"
class CSequential
{
private:
    vvvf final_points;
public:
    const vvvf &getPoints() const;
    int writeToFile();

    template<class Iter_T, class Iter2_T>
    double vectorDistance(Iter_T first, Iter_T last, Iter2_T first2) {
        double ret = 0.0;
        while (first != last) {
            double dist = (*first++) - (*first2++);
            ret += dist * dist;
        }
        return ret > 0.0 ? sqrt(ret) : 0.0;
    }


public:
    bool generatePoints();

};

#endif //ASSIGNMENT_2_SGUPTA38_CSEQUENTIAL_H
