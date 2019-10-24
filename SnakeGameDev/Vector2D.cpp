#include "Vector2D.h"

Vector2D::Vector2D(){
    x = 0.0f; y = 0.0f;
}

Vector2D::Vector2D(double initX, double initY){
    x = initX; y = initY;
}

Vector2D& Vector2D::add(const Vector2D& vec){
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& vec){
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& vec){
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Vector2D& Vector2D::divide(const Vector2D& vec){
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vector2D& operator+(Vector2D& vec1, Vector2D& vec2){
    return vec1.add(vec2);
}

Vector2D& operator-(Vector2D& vec1, Vector2D& vec2){
    return vec1.subtract(vec2);
}

Vector2D& operator*(Vector2D& vec1, Vector2D& vec2){
    return vec1.multiply(vec2);
}

Vector2D& operator/(Vector2D& vec1, Vector2D& vec2){
    return vec1.divide(vec2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec){
    return this->add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec){
    return this->subtract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec){
    return this->multiply(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec){
    return this->divide(vec);
}

Vector2D& Vector2D::operator*=(const int &value){
    x *= value;
    y *= value;
    return *this;
}

Vector2D& Vector2D::zero(){
    x = 0;
    y = 0;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec){
    stream << "(" << vec.x << ", " << vec.y << ")\n";
    return stream;
}




