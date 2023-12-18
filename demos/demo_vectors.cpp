#include <cstdlib>
#include <iostream>

#include "vectors.hpp"

using namespace std;
using namespace geometry;

void apply_speed(Vector<double> &position, Vector<double> const &speed, double dt) {
    position += speed * dt;
}

int main() {
    Vector<double> p = -2.0 * (Vector(2.1, 1.25)+Vector(-0.1, 0.25));

    cout << "p = " << p << endl;
    apply_speed(p, -Vector(30.0, 60.0)/3.0, 0.1);
    cout << "p = " << p << endl;

    Vector<float> u{3.14f, 5.3f};
    Vector<double> v{3.14, 5.3};

    cout << u.normalized() << endl;
    cout << u.normalized().squared_norm() << endl;

    cout << v.normalized() << endl;
    cout << v.normalized().squared_norm() << endl;

    return EXIT_SUCCESS;
}
