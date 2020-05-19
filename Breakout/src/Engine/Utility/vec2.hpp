#ifndef VEC2_H
#define VEC2_H

namespace bet
{
struct vec2
{
    float x;
    float y;

    vec2() : x(0), y(0){};
    vec2(float x_, float y_) : x(x_), y(y_){};

    vec2 operator+(const vec2 &v) const
    {
        return vec2(x + v.x, y + v.y);
    }

    vec2 operator-(const vec2 &v) const
    {
        return vec2(x - v.x, y - v.y);
    }

    vec2 operator*(const vec2 &v) const
    {
        return vec2(x * v.x, y * v.y);
    }

    vec2 operator/(const vec2 &v) const
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