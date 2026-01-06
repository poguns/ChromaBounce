#include <SFML/Graphics.hpp>
#include "play.hpp"

Play play;

int main(){
    sf::RenderWindow window(sf::VideoMode({800, 600}), "ChromaBounce");
    sf::Clock clock;

    while (window.isOpen()){
        float dt = clock.restart().asSeconds();
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            //ESC key to close
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        };

        play.update(dt);

        //render
        play.render(window);
    }
}
