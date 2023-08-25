#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

    // Ball
    sf::CircleShape ball(15);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    sf::Vector2f ballVelocity(0.5f, 0.5f);

    // Paddles
    sf::RectangleShape leftPaddle(sf::Vector2f(20, 100));
    leftPaddle.setFillColor(sf::Color::White);
    leftPaddle.setPosition(30, window.getSize().y / 2 - leftPaddle.getSize().y / 2);

    sf::RectangleShape rightPaddle(sf::Vector2f(20, 100));
    rightPaddle.setFillColor(sf::Color::White);
    rightPaddle.setPosition(window.getSize().x - 50, window.getSize().y / 2 - rightPaddle.getSize().y / 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Ball movement and collision
        ball.move(ballVelocity.x, ballVelocity.y);

        if (ball.getPosition().y <= 0 || ball.getPosition().y + ball.getRadius() * 2 >= window.getSize().y)
            ballVelocity.y = -ballVelocity.y;

        if ((ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds())) || 
            (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds())))
            ballVelocity.x = -ballVelocity.x;

        // Paddle movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftPaddle.getPosition().y > 0)
            leftPaddle.move(0, -1.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftPaddle.getPosition().y + leftPaddle.getSize().y < window.getSize().y)
            leftPaddle.move(0, 1.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightPaddle.getPosition().y > 0)
            rightPaddle.move(0, -1.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightPaddle.getPosition().y + rightPaddle.getSize().y < window.getSize().y)
            rightPaddle.move(0, 1.0f);

        window.clear();
        window.draw(ball);
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.display();
    }

    return 0;
}
