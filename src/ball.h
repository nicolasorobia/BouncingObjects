#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball(sf::Vector2u windowSize, sf::CircleShape& circle);
    void bounce(sf::Vector2i window_size, sf::CircleShape& circle);

private:
    // ball properties
    sf::Color       color         {sf::Color::Red};
    sf::Vector2f    velocity      {3.f, 3.f};
    float           radius        {60.0f};
};

#endif