#ifndef RECT_H
#define RECT_H

namespace bet
{

    typedef vec2 Size;
    typedef vec2 Point;

    struct Rect
    {
        Point origin;
        Size size;

        Rect(float x, float y, float width, float height) : origin(x, y), size(width, height) {}
        Rect(const Point &origin_, const Size &size_) : origin(origin_), size(size_) {}

        // Get the center of rect
        Point Center() const { return vec2(size.x * 0.5, size.y * 0.5) + origin; }
    };

} // namespace bet

#endif