#include <SFML/Graphics.hpp>

class Ball {
public:

    Ball();
    void handleInput();
    void update(float dt);
    void render(sf::RenderWindow& window);

    void setWindowSize(sf::Vector2u size) {
        windowSize = size;
    }

    sf::FloatRect getBounds() const {
        return ball.getGlobalBounds();
    }

    sf::Vector2f getPosition() const { 
        return ball.getPosition(); 
    }

    void setPosition(sf::Vector2f p) { 
        ball.setPosition(p); 
    }

    float getRadius() const { 
        return ball.getRadius(); 
    }

    
private:
    sf::CircleShape ball;
    float speed = 500.f;
    sf::Vector2f velocity;
    sf::Vector2u windowSize;

};
