#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "stripes.hpp"

class Play {
public:

    Play();
    void handleInput(sf::RenderWindow& window);
    void update(float dt);
    void render(sf::RenderWindow& window);

    Ball ball; 

private:
    Stripes stripes;
    
};