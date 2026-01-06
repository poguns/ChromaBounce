#include <SFML/Graphics.hpp>
#include "play.hpp"

Play::Play() {};

void handleInput(sf::RenderWindow& window) {
    Ball ball;
    ball.handleInput();

};


void Play::update(float dt) {
    ball.handleInput();
    ball.update(dt);
};


void Play::render(sf::RenderWindow& window) {
    window.clear();
    stripes.render(window);
    ball.render(window);
    window.display();
};