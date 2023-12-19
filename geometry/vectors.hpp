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


    // for printing in a stream
    template <typename K>
    std::ostream &operator<<(std::ostream &, Vector<K> const &);


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
        Vector(K x, K y);

        K get_x() const;
        K get_y() const;

        Vector<K> normalized() const;

        K dot(Vector<K> const &other) const;
        K squared_norm() const;

        void normalize();
    };
}  // namespace geometry
