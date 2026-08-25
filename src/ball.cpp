#include "ball.h"

Ball::Ball(sf::Vector2u windowSize, sf::CircleShape& circle)
{
    circle.setRadius(radius);
    circle.setFillColor(color);
    // subtract by radius to account for offset of ball's origin not in its center
    circle.setPosition({windowSize.x / 2.f - radius, windowSize.y / 2.f - radius});
}

void Ball::bounce(sf::Vector2i window_size, sf::CircleShape& circle)
{
    circle.move(velocity);

}