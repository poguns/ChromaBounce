#include <SFML/Graphics.hpp>
#include "ball.hpp"

Ball::Ball() {
    ball = sf::CircleShape(40.f);
    ball.setPosition(100.f, 300.f);
    velocity = sf::Vector2f(0.f, 0.f);
};

void Ball::update(float dt) {
    ball.move(velocity * dt);

};


void Ball::render(sf::RenderWindow& window) {
    ball.setFillColor(sf::Color::White);
    window.draw(ball);

};
