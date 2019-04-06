//  @author: Sonu Gupta
//  @purpose: SIMD (AVX specification) to accelerate the computation of the lengths of a sequence of line segments using two 4-D points
//
#include <immintrin.h>
#include <cmath>
#include <functional>
#include <chrono>
#include <random>
#include <iostream>
#include <cassert>

const int N = 24*1000000; // line segments

double
time(const std::function<void ()> &f) {
    f();
    // Now time it for real.
    auto start = std::chrono::system_clock::now();
    f();
    auto stop = std::chrono::system_clock::now();
    return std::chrono::duration<double>(stop - start).count();
}

int
main() {

    std::cout<<"Computing for "<<N<<" segments\n";

    alignas(32) static float x1[N], y1[N], z1[N], w1[N];
    alignas(32) static float x2[N], y2[N], z2[N], w2[N];

    /*
     * Generate data.
     */

    std::default_random_engine eng;
    std::uniform_real_distribution<float> dist(-1, 1);
    for (int i = 0; i < N; i++) {
        x1[i] = dist(eng);
        y1[i] = dist(eng);
        z1[i] = dist(eng);
        w1[i] = dist(eng);
        x2[i] = dist(eng);
        y2[i] = dist(eng);
        z2[i] = dist(eng);
        w2[i] = dist(eng);
    }

    /*
     * Sequential.
     */

    // Note: Dont use pow(x,2) here. I tested it and resulted in precison accuracy which was failing assert.
    static float l_s[N];
    auto seq = [&]() {
        for (int i = 0; i < N; i++) {
            l_s[i] = std::sqrt((((x1[i]-x2[i]) * (x1[i]-x2[i])) + ((y1[i]-y2[i]) * (y1[i]-y2[i])) + \
                                ((z1[i]-z2[i]) * (z1[i]-z2[i])) + ((w1[i]-w2[i]) * (w1[i]-w2[i]))
                               )
            );
        }
    };

    std::cout << "Sequential: " << (N/time(seq))/1000000 << " Mops/s" << std::endl;

    alignas(32) static float l_v[N];

    auto vec = [&]() {
        for (int i = 0; i < N/8; i++) {
            __m256 ymm_x1 = _mm256_load_ps(x1 + 8*i);
            __m256 ymm_y1 = _mm256_load_ps(y1 + 8*i);
            __m256 ymm_z1 = _mm256_load_ps(z1 + 8*i);
            __m256 ymm_w1 = _mm256_load_ps(w1 + 8*i);
            __m256 ymm_x2 = _mm256_load_ps(x2 + 8*i);
            __m256 ymm_y2 = _mm256_load_ps(y2 + 8*i);
            __m256 ymm_z2 = _mm256_load_ps(z2 + 8*i);
            __m256 ymm_w2 = _mm256_load_ps(w2 + 8*i);

            // substract
            __m256 ymm_subx = _mm256_sub_ps(ymm_x1, ymm_x2);
            __m256 ymm_suby = _mm256_sub_ps(ymm_y1, ymm_y2);
            __m256 ymm_subz = _mm256_sub_ps(ymm_z1, ymm_z2);
            __m256 ymm_subw = _mm256_sub_ps(ymm_w1, ymm_w2);

            // square/multiplication
            __m256 ymm_xsqr = _mm256_mul_ps(ymm_subx, ymm_subx);
            __m256 ymm_ysqr = _mm256_mul_ps(ymm_suby, ymm_suby);
            __m256 ymm_zsqr = _mm256_mul_ps(ymm_subz, ymm_subz);
            __m256 ymm_wsqr = _mm256_mul_ps(ymm_subw, ymm_subw);

            __m256 ymm_sqrtxyzw = _mm256_sqrt_ps(ymm_xsqr + ymm_ysqr + ymm_zsqr + ymm_wsqr);
            _mm256_store_ps(l_v + 8*i, ymm_sqrtxyzw);
        }
    };

    std::cout << "Vector: " << (N/time(vec))/1000000 << " Mops/s" << std::endl;

    for (int i = 0; i < N; i++) {
        if (l_s[i] - l_v[i] != 0.0) {
            assert(false);
        }
    }

    return 0;
}
