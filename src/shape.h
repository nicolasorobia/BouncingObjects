#ifndef SHAPE_H
#define SHAPE_H
#include <SFML/Graphics.hpp>

template <typename Geometry>
class Shape
{
public:
    // parameter for velocity has a default speed
    Shape(sf::Vector2u window_size, Geometry& figure, sf::Color color, sf::Vector2f velocity = {5.f, 5.f});
    void bounce(sf::Vector2u window_size, Geometry& figure);

private:
    sf::Vector2f    velocity {5.f, 5.f};
    
};

#include "shape.cpp" // comment out if not using header guards in shape.cpp
#endif