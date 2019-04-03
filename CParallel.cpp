//
// Created by sonu on 4/2/19.
//

#include <iostream>
#include "CParallel.h"
#include "common.h"
#include <omp.h>
#include <cstring>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

const vvvf &CParallel::getPoints() const {
    return final_points;
}

int CParallel::writeToFile() {
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

bool CParallel::generatePoints(long count, int thread) {
    // here we will generate points from 2-16 dimensions
    vf distance;
    std::default_random_engine eng;
    std::uniform_real_distribution<float> dist(-1, 1);
    int workPerThread = count/thread;
    float final[count];
    float Buckets[count];

    for(int i = 2; i <= 16; i++) {
        memset(Buckets, 0, sizeof(Buckets));
#pragma omp parallel
        {
            int id = omp_get_thread_num();
            float e_distance[workPerThread];
            float e_dist = 0;

            for (int n = 0; n < workPerThread;)
            {
                vf points(i);
                for (int j = 0; j < i; j++) {
                    float p = dist(eng);
                    points[j] = p;
                }

                // Calculate distance here.
                float sum = 0;
                for (auto &num : points) {
                    sum += (num * num);
                }

                if (sum > 1)
                    continue;
                else if (sum <= 1) {
                    e_dist = 1 - sum;
                    e_distance[n] = e_dist;
                    n++;
                }
            }

            for(int n = 0; n < workPerThread; n++)
            {
                final[(id * workPerThread) + n] = e_distance[n];
            }
        }

        // Normalize to buckets of size 100 intervals.
        for(int i=0; i<count; i++){
            int bin = int(final[i] * 100);
            Buckets[bin] = Buckets[bin] + 1; // count total members
        }

        // steps of 0.01
        for(int i=0; i<count-1; i++){
            Buckets[i] = float(Buckets[i])/float(count) * 100; // count total members
        }
        Buckets[99] = Buckets[99] + Buckets[100];

        vf ff(Buckets, Buckets + count);
        cout<<" For dimension: "<<i<<endl;
        for(int k = 0; k< 100; k++)
        {
            //cout<<final[k] <<" ";
            cout<<fixed<<"\n Dimension :"<<i<<" Bucket: "<<k<<"--> "<<float(Buckets[k])<<"\n";
        }

        plt::hist(ff);
        plt::title("Histogram");
        plt::show();
        cout<<endl;
    }

    return true;
}
