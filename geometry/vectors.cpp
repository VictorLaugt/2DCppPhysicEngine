#include "vectors.hpp"

// template implementations
namespace geometry {
    template <typename K>
    Vector<K>::Vector(K x, K y) : _x(x), _y(y){};

    template <typename K>
    K Vector<K>::get_x() const {
        return _x;
    }

    template <typename K>
    K Vector<K>::get_y() const {
        return _y;
    }

    template <typename K>
    Vector<K> Vector<K>::normalized() const {
        return (*this) * fast_inverse_square_root(squared_norm());
    }

    template <typename K>
    K Vector<K>::dot(Vector<K> const &other) const {
        return _x * other._x + _y * other._y;
    }

    template <typename K>
    K Vector<K>::squared_norm() const {
        return dot(*this);
    }

    template <typename K>
    void Vector<K>::normalize() {
        (*this) *= fast_inverse_square_root(squared_norm());
    }


    template <typename K>
    Vector<K> operator+(Vector<K> const &u, Vector<K> const &v) {
        return {u._x + v._x, u._y + v._y};
    }

    template <typename K>
    Vector<K> operator-(Vector<K> const &u, Vector<K> const &v) {
        return {u._x - v._x, u._y - v._y};
    }

    template <typename K>
    Vector<K> operator*(K scalar, Vector<K> const &u) {
        return {scalar * u._x, scalar * u._y};
    }

    template <typename K>
    Vector<K> operator*(Vector<K> const &u, K scalar) {
        return {u._x * scalar, u._y * scalar};
    }

    template <typename K>
    Vector<K> operator/(Vector<K> const &u, K scalar) {
        return {u._x / scalar, u._y / scalar};
    }


    template <typename K>
    Vector<K> operator-(Vector<K> const &u) {
        return {-u._x, -u._y};
    }

    template <typename K>
    Vector<K> operator+(Vector<K> const &u) {
        return u;
    }


    template <typename K>
    void operator+=(Vector<K> &u, Vector<K> const &v) {
        u._x += v._x;
        u._y += v._y;
    }

    template <typename K>
    void operator-=(Vector<K> &u, Vector<K> const &v) {
        u._x -= v._x;
        u._y -= v._y;
    }

    template <typename K>
    void operator*=(Vector<K> &u, K scalar) {
        u._x *= scalar;
        u._y *= scalar;
    }

    template <typename K>
    void operator/=(Vector<K> &u, K scalar) {
        u._x /= scalar;
        u._y /= scalar;
    }


    template <typename K>
    std::ostream &operator<<(std::ostream &os, Vector<K> const &u) {
        return os << "[" << u._x << ", " << u._y << "]";
    }
}  // namespace geometry


// explicit compilation of Vector specialized with K = double.
namespace geometry {
    template class Vector<double>;
    template Vector<double> operator+(Vector<double> const &, Vector<double> const &);
    template Vector<double> operator-(Vector<double> const &, Vector<double> const &);
    template Vector<double> operator*(double, Vector<double> const &);
    template Vector<double> operator*(Vector<double> const &, double);
    template Vector<double> operator/(Vector<double> const &, double);
    template Vector<double> operator-(Vector<double> const &);
    template Vector<double> operator+(Vector<double> const &);
    template void operator+=(Vector<double> &, Vector<double> const &);
    template void operator-=(Vector<double> &, Vector<double> const &);
    template void operator*=(Vector<double> &, double);
    template void operator/=(Vector<double> &, double);
    template std::ostream &operator<<(std::ostream &, Vector<double> const &);
}
