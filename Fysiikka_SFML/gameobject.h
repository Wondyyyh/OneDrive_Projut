#pragma once

// Abstract base-class
// for all game objects in our game
class GameObject {

public:
    // A pure virtual function --> no objects
    // can be made from this class!
    virtual void update(double deltatime) = 0;

private:

};