#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball(sf::Vector2u window_size, sf::CircleShape& circle);
    void bounce(sf::Vector2i window_size, sf::CircleShape& circle);

private:
    // ball properties
    sf::Color       color         {sf::Color::Red};
    sf::Vector2f    velocity      {5.f, 5.f};
    float           radius        {60.0f};
};

#endif