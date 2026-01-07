#include <SFML/Graphics.hpp>
#include "play.hpp"

Play::Play() {
    ball.setStripes(stripes.getStripes());
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