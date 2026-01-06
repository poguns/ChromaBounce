#include <SFML/Graphics.hpp>

class Ball {
public:

    Ball();
    void handleInput();
    void update(float dt);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const; //for collision checks


private:
    sf::CircleShape ball;
    float speed = 500.f;
    sf::Vector2f velocity;

};
