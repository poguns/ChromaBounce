#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "stripes.hpp"


Stripes::Stripes() {

    //stripes colours
    for (int i = 0; i < baseColours.size(); i++) {
        sf::Color base = baseColours[i];
        sf::Color contrast = getContrastColour(base);

        stripes.push_back({ i * stripeWidth, stripeWidth, base, contrast });
    }
};


void Stripes::update(float dt) {
    // nothing for now, could be used to move or animation later?
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


sf::Color Stripes::getContrastColour(const sf::Color& bgColour) {
    //opposite color on the color wheel
    return sf::Color(
        255 - bgColour.r,  // invert red
        255 - bgColour.g,  // invert green
        255 - bgColour.b   // invert blue
    );
};

