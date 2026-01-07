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
    hexToColor("#FFFFFF"),
    hexToColor("#0055FF"),
    hexToColor("#8B2263"),
    hexToColor("#000000"),
    hexToColor("#FFFFFF"),
    hexToColor("#FFAA00"),
    hexToColor("#228B22"),
    hexToColor("#000000"),
    hexToColor("#FFFFFF"),
    hexToColor("#0055FF"),
    hexToColor("#8B2263"),
    hexToColor("#000000"),
    hexToColor("#FFFFFF"),
    hexToColor("#FFAA00"),
    hexToColor("#228B22"),
    hexToColor("#000000"),
    hexToColor("#FFFFFF"),
    hexToColor("#0055FF"),
    hexToColor("#8B2263"),
    hexToColor("#000000")
    };
    
    float stripeWidth = 800.f / 20.0f; // create stripes

};
