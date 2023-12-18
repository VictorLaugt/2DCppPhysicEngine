#pragma once

#include <iostream>

#include "calculus.hpp"

// template declarations
namespace geometry {
    template <typename K>
    class Vector;


    // out of place algebraic operations
    template <typename K>
    Vector<K> operator+(Vector<K> const &, Vector<K> const &);

    template <typename K>
    Vector<K> operator-(Vector<K> const &, Vector<K> const &);

    template <typename K>
    Vector<K> operator*(K, Vector<K> const &);

    template <typename K>
    Vector<K> operator*(Vector<K> const &, K);

    template <typename K>
    Vector<K> operator/(Vector<K> const &, K);

    template <typename K>
    Vector<K> operator-(Vector<K> const &);

    template <typename K>
    Vector<K> operator+(Vector<K> const &);


    // in place algebraic operations
    template <typename K>
    void operator+=(Vector<K> &, Vector<K> const &);

    template <typename K>
    void operator-=(Vector<K> &, Vector<K> const &);

    template <typename K>
    void operator*=(Vector<K> &, K);

    template <typename K>
    void operator/=(Vector<K> &, K);


    template <typename K>
    std::ostream &operator<<(std::ostream &, Vector<K> const &);
}  // namespace geometry


// template definitions
namespace geometry {
    template <typename K>
    class Vector {
    private:
        friend Vector<K> operator+ <>(Vector<K> const &, Vector<K> const &);
        friend Vector<K> operator- <>(Vector<K> const &, Vector<K> const &);
        friend Vector<K> operator* <>(K, Vector<K> const &);
        friend Vector<K> operator* <>(Vector<K> const &, K);
        friend Vector<K> operator/ <>(Vector<K> const &, K);

        friend Vector<K> operator- <>(Vector<K> const &);
        friend Vector<K> operator+ <>(Vector<K> const &);

        friend void operator+= <>(Vector<K> &, Vector<K> const &);
        friend void operator-= <>(Vector<K> &, Vector<K> const &);
        friend void operator*= <>(Vector<K> &, K);
        friend void operator/= <>(Vector<K> &, K);

        friend std::ostream &operator<< <>(std::ostream &, Vector<K> const &);

    protected:
        K _x;
        K _y;

    public:
        Vector(K x, K y) : _x(x), _y(y){};

        K get_x() const {
            return _x;
        }

        K get_y() const {
            return _y;
        }

        Vector<K> normalized() const {
            return (*this) * fast_inverse_square_root(squared_norm());
        }

        K dot(Vector<K> const &other) const {
            return _x * other._x + _y * other._y;
        }

        K squared_norm() const {
            return dot(*this);
        }

        void normalize() {
            (*this) *= fast_inverse_square_root(squared_norm());
        }
    };


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
