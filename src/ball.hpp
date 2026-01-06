#include <SFML/Graphics.hpp>

class Ball {
public:

    Ball();
    void update(float dt);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const; //for collision checks


private:
    float ballRadius = 30.f;
    sf::CircleShape ball;
    float radius = 30.f;
    float speed = 500.f;
    sf::Vector2f velocity;

};
