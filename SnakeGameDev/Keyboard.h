#pragma once

class Keyboard{
private:
    bool prevKey[];
    bool keyPressed[];
    bool keyReleased[];
public:
    Keyboard();
    ~Keyboard();
    bool isKeyPressed();
    bool isKeyReleased();
};