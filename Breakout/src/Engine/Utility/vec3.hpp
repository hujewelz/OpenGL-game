#ifndef VEC3_H
#define VEC3_H

#include "vec2.hpp"

namespace bet
{
    template <typename T>
    struct vec3
    {
        T x;
        T y;
        T z;

        vec3();
        vec3(const T x_, const T y_, const T z_) : x(x_), y(y_), z(z_){};
        vec3(const vec3<T> &v) : x(v.x), y(v.y), z(v.z){};
        vec3(const vec2<T> &v, T z_) : x(v.x), y(v.y), z(z_){};

        vec3 &operator+(const vec3 &v) const
        {
            return vec3(x + v.x, y + v.y, z + v.z);
        }

        vec3 &operator-(const vec3 &v) const
        {
            return vec3(x - v.x, y - v.y, z - v.z);
        }

        vec3 &operator*(const vec3 &v) const
        {
            return vec3(x * v.x, y * v.y, z * v.z);
        }

        vec3 &operator/(const vec3 &v) const
        {
            return vec3(x / v.x, y / v.y, z / v.z);
        }

        bool operator==(const vec3 &v) const
        {
            return x == v.x && y == v.y && z == v.z;
        }
    };

} // namespace bet

#endif