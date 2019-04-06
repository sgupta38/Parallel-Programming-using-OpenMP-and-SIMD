//
// Created by sonu on 4/2/19.
//

#include <iostream>
#include <iomanip>
#include "CParallel.h"
#include "common.h"
#include <omp.h>
#include <cstring>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

const vvf &CParallel::getPoints() const {
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

bool CParallel::generatePointsEx(long count) {
    // here we will generate points from 2-16 dimensions
    vvf distance;
    std::default_random_engine eng;
    std::uniform_real_distribution<float> dist(-1, 1);
    float final[count];

    for(int i = 2; i <= 16; i++)
    {
        float Buckets[100] = {0};

#pragma omp parallel for
        for(int i = 0; i<count; i++) {
            final[i] = 0;
        }


#pragma omp parallel
        {

            #pragma omp for
            for (int n = 0; n < count;n++)
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

                // final, sqrt of distance
                sum = sqrt(sum);

                if (sum > 1)
                {
                    n--;
                    continue;   // point is outside sphere, ignore and find new point
                }
                else if (sum <= 1) {    // point is inside sphere, considering it.
                    final[n] = 1 - sum;
                    int bin = (int)floor(final[n] * 100);
                    Buckets[bin] = Buckets[bin] + 1; // count total members
                }
            }
        }

        //vf temp(final, final+count);
        //plotGraph(temp);
        //final_points.push_back(temp);

        printBuckets(i, Buckets);

        vf buckets(Buckets, Buckets+100);
        plotGraph(i, buckets, 1);
        buckets.clear();

        cout<<" Dimension: "<<i<<endl;
        for(int k = 0; k< 100; k++)
        {
            cout<<fixed<<setprecision(2)<< k * 0.01<<"-"<<(k+1) * 0.01<<": "<<Buckets[k]<<endl;
        }
        cout<<endl;
    }

    return true;
}

bool CParallel::printPoints() {
    int d = 2;
    for(auto& points : final_points)
    {
        cout<<" Dim: "<<d<<" ";
        for(auto&p:points)
        {
            cout<<p<<" ";
        }
        cout<<endl;
        d++;
    }
}

void CParallel::plotGraph(int dim, vf &data, int save) {
    std::string name = "Dimension" + std::to_string(dim);
    std::string filename = name += ".png";

    plt::hist(data);
    plt::title(name);

    if(save) {
        std::string path = GRAPH_PARALLEL;
        path += "/" + filename;
        plt::save(path);
        plt::close();
    }
    else
        plt::show();
}

void CParallel::printBuckets(int dim, float Buckets[]) {
    cout<<" Dimension: "<<dim<<endl;
    for(int k = 0; k< 100; k++)
    {
        cout<<fixed<<setprecision(2)<< k * 0.01<<"-"<<(k+1) * 0.01<<": "<<Buckets[k]<<endl;
    }
    cout<<endl;
}
