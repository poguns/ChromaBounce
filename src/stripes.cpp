#include <SFML/Graphics.hpp>
#include <vector>
#include "stripes.hpp"


Stripes::Stripes() {

    //create stripes
    float stripeWidth = 800.f / 6.0f;

    //stripes colours
    stripes.push_back({0 * stripeWidth, stripeWidth, sf::Color(255, 127, 80)});
    stripes.push_back({1 * stripeWidth, stripeWidth, sf::Color(180, 160, 255)});
    stripes.push_back({2 * stripeWidth, stripeWidth, sf::Color(152, 255, 152)});
    stripes.push_back({3 * stripeWidth, stripeWidth, sf::Color(135, 206, 250)});
    stripes.push_back({4 * stripeWidth, stripeWidth, sf::Color(255, 218, 185)});
    stripes.push_back({5 * stripeWidth, stripeWidth, sf::Color(170, 200, 170)});

};


void Stripes::update(float dt) {
    // nothing for now,could be used to move or animation later?
};


void Stripes::render(sf::RenderWindow& window) {
    for (const auto& stripe : stripes) {
        sf::RectangleShape rect(sf::Vector2f(stripe.width, 600));
        rect.setPosition(stripe.x, 0);
        rect.setFillColor(stripe.colour);
        window.draw(rect);
    }
};


sf::Color Stripes::getStripColourAt(float x, const std::vector<ColourStripe>& stripes) {
    for (const auto& stripe : stripes) {
        if (x >= stripe.x && x < stripe.x + stripe.width) {
            return stripe.colour;
        }
    }
    return sf::Color::Black; //default if nothing matches
};
