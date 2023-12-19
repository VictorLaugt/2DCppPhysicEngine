#include "calculus.hpp"

using namespace std;

double fast_inverse_square_root(double number) {
    long i;
    double x2, y;
    const double threehalfs = 1.5;

    x2 = number * 0.5;
    y = number;
    i = *(long *)&y;                    // evil doubleing point bit level hacking
    i = 0x5fe6eb50c7b537a9 - (i >> 1);  // what the fuck?
    y = *(double *)&i;
    y = y * (threehalfs - (x2 * y * y));
    // y = y * (threehalfs - (x2 * y * y));  // 2nd iteration

    return y;
}

float fast_inverse_square_root(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5;

    x2 = number * 0.5;
    y = number;
    i = *(long *)&y;            // evil doubleing point bit level hacking
    i = 0x5f3759df - (i >> 1);  // what the fuck?
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));
    // y = y * (threehalfs - (x2 * y * y));  // 2nd iteration

    return y;
}
