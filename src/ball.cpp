#include <SFML/Graphics.hpp>
#include "ball.hpp"

Ball::Ball() {
    ball = sf::CircleShape(40.f);
    ball.setPosition(100.f, 300.f);
    velocity = sf::Vector2f(0.f, 0.f);
};

void Ball::handleInput() {
    
    velocity.x = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x += speed;
    }
};


void Ball::update(float dt) {
    ball.move(dt * velocity);

};


void Ball::render(sf::RenderWindow& window) {
    ball.setFillColor(sf::Color::White);
    window.draw(ball);

};
