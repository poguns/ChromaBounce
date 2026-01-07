#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
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

    sf::Color hexToColor(const std::string& hex);

private:
    std::vector<ColourStripe> stripes;
    std::vector<sf::Color> baseColours = {
    hexToColor("#4C5938"),
    hexToColor("#8A8C3E"),
    hexToColor("#F28C0F"),
    hexToColor("#F2790F"),
    hexToColor("#F2E0DC"),
    hexToColor("#F48FBF"),
    hexToColor("#F2AF88"),
    hexToColor("#8C0B0B"),
    hexToColor("#D92323"),
    hexToColor("#400A0A")
    };
    
    float stripeWidth = 800.f / 10.0f; // create stripes

};
