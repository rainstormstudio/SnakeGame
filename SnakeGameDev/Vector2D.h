#pragma once
#include <iostream>

class Vector2D{
public:
    double x;
    double y;

    Vector2D();
    Vector2D(double initX, double initY);

    Vector2D& add(const Vector2D& vec);
    Vector2D& subtract(const Vector2D& vec);
    Vector2D& multiply(const Vector2D& vec);
    Vector2D& divide(const Vector2D& vec);

    friend Vector2D& operator+(Vector2D& vec1, Vector2D& vec2);
    friend Vector2D& operator-(Vector2D& vec1, Vector2D& vec2);
    friend Vector2D& operator*(Vector2D& vec1, Vector2D& vec2);
    friend Vector2D& operator/(Vector2D& vec1, Vector2D& vec2);

    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);

    Vector2D& operator*(const int &value);
    Vector2D& zero();

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};