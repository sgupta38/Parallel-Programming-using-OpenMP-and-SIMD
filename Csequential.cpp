//
// Created by sonu on 4/2/19.
//

#include <iostream>
#include "Csequential.h"
#include "common.h"

bool CSequential::generatePoints(long count) {
    // here we will generate points from 2-16 dimensions
    vf distance;
    vf points;
    vvf d_points;
    std::default_random_engine eng;
    std::uniform_real_distribution<float> dist(-1, 1);

    for(int i = 2; i <= 16; i++)
    {
        int n = 0;
        d_points.clear();
        float e_dist = 0;
        while(n != count)
        {
            points.clear();
            for (int j = 0; j < i; j++) {
                float p = dist(eng);
                points.push_back(p);
            }

            // Calculate distance here.
            float sum = 0;
            for(auto& num : points)
            {
                sum += (num * num);
            }

            if(sum > 1)
                continue;
            else if(sum <= 1)
            {
                n++;
                vf origin(i,0);
                e_dist = 1 - sum;
                d_points.push_back(std::make_pair(points, e_dist));
            }
        }
        final_points.push_back(d_points);
    }

    return true;
}

const vvvf &CSequential::getPoints() const {
    return final_points;
}

int CSequential::writeToFile() {
    ofstream ofs("sample.csv");

    if( ! ofs ) {
        std::cout << "Error opening file for output" << endl ;
        return -1 ;
    }

    for(int i = 0; i < final_points.size(); i++) {
    //todo
    }

    ofs.close() ;
    return 0;
}
