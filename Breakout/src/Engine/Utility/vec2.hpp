#ifndef VEC2_H
#define VEC2_H

namespace bet
{
    template <typename T>
    struct vec2
    {
        T x;
        T y;

        vec2() : x(), y(){};
        vec2(const T x_, const T y_) : x(x_), y(y_){};
        // vec2(const vec2<T> &v) : x(v.x), y(v.y){};

        vec2 &operator+(const vec2 &v) const
        {
            return vec2(x + v.x, y + v.y);
        }

        vec2 &operator-(const vec2 &v) const
        {
            return vec2(x - v.x, y - v.y);
        }

        vec2 &operator*(const vec2 &v) const
        {
            return vec2(x * v.x, y * v.y);
        }

        vec2 &operator/(const vec2 &v) const
        {
            return vec2(x / v.x, y / v.y);
        }

        bool operator==(const vec2 &v) const
        {
            return x == v.x && y == v.y;
        }
    };

} // namespace bet

#endif