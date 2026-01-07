#include <SFML/Graphics.hpp>
#include <cmath>
#include "ball.hpp"
#include <iostream>

Ball::Ball() {
    ball = sf::CircleShape(20.f);
    ball.setPosition(100.f, 300.f);
    velocity = sf::Vector2f(200.f, 150.f);
};

void Ball::handleInput() {
    //moving the ball around
    
    // horizontal movement
    velocity.x = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x += speed;
    }

    // vetrical movement
    velocity.y = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity.y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocity.y += speed;
    }

    // supports diagonal movement
    if (velocity.x != 0.f && velocity.y != 0.f) {
    velocity /= std::sqrt(2.f);
    }
};


void Ball::update(float dt) {
    ball.move(dt * velocity);

    sf::Vector2f pos = ball.getPosition();
    float radius = ball.getRadius();

    // Keep ball fully inside screen
    if (pos.x < 0.f) {
        pos.x = 0.f;
        velocity.x = -velocity.x;
    }
    if (pos.x + 2 * radius > windowSize.x) {
        pos.x = windowSize.x - 2 * radius;
        velocity.x = -velocity.x;
    }
    if (pos.y < 0.f) {
        pos.y = 0.f;
        velocity.y = -velocity.y;
    }
    if (pos.y + 2 * radius > windowSize.y) {
        pos.y = windowSize.y - 2 * radius;
        velocity.y = -velocity.y;
    }

    ball.setPosition(pos);


    // Stripe interception detection
    sf::FloatRect bounds = ball.getGlobalBounds();
    bool onStripe = false;

    for (const auto& stripe : stripesRef) {
        if (bounds.left < stripe.x + stripe.width && bounds.left + bounds.width > stripe.x) {
            ball.setFillColor(stripe.contrastColour); // apply contrast
            onStripe = true;
            break; 
        }
    }

    if (!onStripe) {
        ball.setFillColor(sf::Color::White);
    }
};


void Ball::render(sf::RenderWindow& window) {
    window.draw(ball);

};
