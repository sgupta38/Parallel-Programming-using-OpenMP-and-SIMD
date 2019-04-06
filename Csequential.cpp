//
// Created by sonu on 4/2/19.
//

#include <iostream>
#include "Csequential.h"
#include "common.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

const vvf &CSequential::getPoints() const {
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

// Similar to parallel execution code
bool CSequential::generatePointsEx(long count) {
    // here we will generate points from 2-16 dimensions
    vf distance;
    std::default_random_engine eng;
    std::uniform_real_distribution<float> dist(-1, 1);
    float final[count];

    for(int i = 2; i <= 16; i++)
    {
        float Buckets[100] = {0};
        for(int i = 0 ; i < count; i++)
        {
            final[i] = 0;
        }

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

            sum = sqrt(sum);

            if (sum > 1) {
                n--;
                continue;
            }
            else if (sum <= 1) {
                final[n] = 1 - sum;
                int bin = (int)floor(final[n] * 100);
                Buckets[bin] = Buckets[bin] + 1; // count total members
            }
        }

        //vf temp(final, final+count);
        //plotGraph(temp);
        //final_points.push_back(temp);
        printBuckets(i, Buckets);
        vf buckets(Buckets, Buckets+100);
        plotGraph(i, buckets, 1); // Instead of plotting all points, normalized points are printted
    }
    return true;
}

bool CSequential::printPoints() {
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

void CSequential::plotGraph(int dim, vf &data, int save) {
    std::string name = "Dimension" + std::to_string(dim);
    std::string filename = name += ".png";

    plt::hist(data);
    plt::title(name);

    if(save) {
        std::string path = GRAPH_SEQUENTIAL;
        path += "/" + filename;
        plt::save(path);
        plt::close();
    }
    else
        plt::show();
}

void CSequential::printBuckets(int dim, float Buckets[]) {
    cout<<" Dimension: "<<dim<<endl;
    for(int k = 0; k< 100; k++)
    {
        cout<<fixed<<setprecision(2)<< k * 0.01<<"-"<<(k+1) * 0.01<<": "<<Buckets[k]<<endl;
    }
    cout<<endl;
}
