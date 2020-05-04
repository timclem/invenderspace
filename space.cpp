//
// Created by clement.theotime on 04/05/2020.
//

#include <iostream>
#include "SFML/Graphics.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Cercles");
    window.setVerticalSyncEnabled(true);

    float y = 0;
    float radius = 20;

    while(window.isOpen())

    {
        sf::Event event{};
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color(200,50,8));
        sf::CircleShape cercle(radius,3);
        sf::RectangleShape recyangle(sf::Vector2f(150, 75));
        recyangle.setPosition(400,y);
        cercle.setPosition(200,y);

        window.draw(cercle);
        window.draw(recyangle);
        window.display();
        y++;
        if (y == 200)
        {
            y = y-y;
        }

    }


    std::cout << "J'ai quitté la fenêtre proprement !" << std::endl;

    return 0;
}
