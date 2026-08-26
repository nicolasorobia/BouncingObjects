#include "ball.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1024, 768}), "Bouncing Objects");
    window.setFramerateLimit(60);

    sf::CircleShape ball;
    // Call ball to center of window
    Ball circle(window.getSize(), ball);
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();

        // update call to move & bounce ball
        circle.bounce(sf::Vector2i{window.getSize()}, ball);
        // draw ball into screen
        window.draw(ball);

        window.display();
    }
}
