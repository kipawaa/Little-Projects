#include<SFML/Graphics.hpp>

int main() {
        // create new window
        sf::RenderWindow(sf::VideoMode(800, 600), "New Window");

        // draw loop
        while (window.isOpen()) {
                // poll for events
                sf::Event event;
                while(window.pollEvent(event)) {
                        // close window if window is closed?
                        if (event.type == sf::Event::Closed) window.close();
                }

                window.clear(sf::Color::Black);

                // draw things here

                window.display();
        }
}
