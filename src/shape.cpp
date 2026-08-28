// comment header guard out if using explicit template instantiation
#ifndef SHAPE_CPP
#define SHAPE_CPP

#include "shape.h"

template <typename Geometry>
Shape<Geometry>::Shape(sf::Vector2u window_size, Geometry& figure, sf::Color color, sf::Vector2f startVelocity)
/* 
    NOTE:   Used AI to get this method
    Prompt: How to pass private variable velocity into function that instantiates shape object 
            without using setter/getter functions?
*/
    // initialize shape's velocity with the startVelocity assigned by user upon instancing 
    // or omit to use default velocity of Shape class
    : velocity {startVelocity}
{
    sf::FloatRect bound = figure.getGlobalBounds();

    figure.setFillColor(color);
    
    // accounts the offset from x,y origin to position shape in center of screen
    figure.setPosition({window_size.x / 2.f - bound.size.x / 2.f, 
                        window_size.y / 2.f - bound.size.y / 2.f});
}

template <typename Geometry>
void Shape<Geometry>::bounce(sf::Vector2u window_size, Geometry& figure)
{
    figure.move(velocity);

    sf::FloatRect bound = figure.getGlobalBounds();

    float left   = bound.position.x;
    float right  = left + bound.size.x;
    float top    = bound.position.y;
    float bottom = top + bound.size.y;

    // bounce from left or right wall
    if ((right >= window_size.x && velocity.x > 0) || ( left <= 0 && velocity.x < 0))
    {
        velocity.x *= -1;
    }

    // bounce from top or bottom wall
    if ((bottom >= window_size.y && velocity.y > 0) || (top <= 0 && velocity.y < 0))
    {
        velocity.y *= -1;
    }
}

// Uncomment if not using header guards:
// template class Shape<sf::CircleShape>;
// template class Shape<sf::RectangleShape>;

#endif
