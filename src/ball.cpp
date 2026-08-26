#include "ball.h"

Ball::Ball(sf::Vector2u window_size, sf::CircleShape& circle)
{
    circle.setRadius(radius);
    circle.setFillColor(color);
    // subtract by radius to account for offset of ball's origin not in its center
    circle.setPosition({window_size.x / 2.f - radius, window_size.y / 2.f - radius});
}

void Ball::bounce(sf::Vector2i window_size, sf::CircleShape& circle)
{
    sf::Vector2f pos {circle.getPosition()};
    float xPos {pos.x};
    float yPos {pos.y};
    circle.move(velocity);

    // bounce from left or right wall
    if ((xPos + radius >= window_size.x && velocity.x > 0) || (xPos <= 0 && velocity.x < 0))
    {
        velocity.x *= -1;
    }

    // bounce from top or bottom wall
    if ((yPos + radius >= window_size.y && velocity.y > 0) || (yPos <= 0 && velocity.y < 0))
    {
        velocity.y *= -1;
    }
}