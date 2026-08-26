#include "shape.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1024, 768}), "Bouncing Objects");
    window.setFramerateLimit(60);

    // ball properties
    sf::CircleShape circle;
    circle.setRadius(30.f);

    // box properties
    sf::RectangleShape rect;
    rect.setSize({50.f, 50.f});

    // Call shapes to center of window
    Shape<sf::CircleShape> ball(window.getSize(), circle, sf::Color::Red);                // uses default velocity
    Shape<sf::RectangleShape> box(window.getSize(), rect, sf::Color::Blue, {-3.f, -3.f}); // assigns unique velocity
    
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

        // update call to move & bounce shape objects
        ball.bounce(window.getSize(), circle);
        box.bounce(window.getSize(), rect);
        // draw shapes into screen
        window.draw(circle);
        window.draw(rect);

        window.display();
    }
}
