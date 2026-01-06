#include <SFML/Graphics.hpp>
#include "stripes.hpp"
#include "ball.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode({800, 600}), "ChromaBounce");

    Stripes stripes;
    Ball ball; 

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            //ESC key to close
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        window.clear();
        stripes.render(window);
        ball.render(window);
        window.display();
    }
    return 0;
}
