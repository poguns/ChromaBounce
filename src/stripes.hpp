#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#pragma once

//represents a colour stripe
struct ColourStripe{
    float x;
    float width;
    sf::Color colour;
    sf::Color contrastColour;
};

class Stripes {
public:

    Stripes();
    void update(float dt);
    void render(sf::RenderWindow& window);
    sf::Color getStripColourAt(float x, const std::vector<ColourStripe>& stripes);
    sf::Color getContrastColour(const sf::Color& bgColour);

    const std::vector<ColourStripe>& getStripes() const {
        return stripes;
    }

private:
    std::vector<ColourStripe> stripes;
    std::vector<sf::Color> baseColours {
        {255,127,80}, //coral
        {180,160,255}, //lavender
        {152,255,152}, //mint
        {135,206,250}, //sky blue
        {255,218,185}, //peach
        {170,200,170} //sage
    };
    
    float stripeWidth = 800.f / 6.0f; // create stripes

};
