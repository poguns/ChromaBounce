#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>


//represents a colour stripe
struct ColourStripe{
    float x;
    float width;
    sf::Color colour;
};

class Stripes {
public:

    Stripes();
    void update(float dt);
    void render(sf::RenderWindow& window);
    sf::Color getStripColourAt(float x, const std::vector<ColourStripe>& stripes);

private:
    std::vector<ColourStripe> stripes;

};
