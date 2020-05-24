//
// Created by clement.theotime on 04/05/2020.
//

#include <iostream>
#include "Vaisseau.h"
#include "SFML/Graphics.hpp"

int main() {
    Vaisseau gentille(100,20);
    Vaisseau mechant(40,10);



    sf::RenderWindow window(sf::VideoMode(800, 800), "Space");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    sf::Event event{};
    sf::Color color(sf::Color::Black);


    float g_xposition = 350;
    float g_yposition = 700;
    float g_ymissile = 700;
    float g_xmissile = 350;
    int xmechant = 20;
    int ymechant = 20;




    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        //les caractéristique du  vaisseau gentille
        sf::RectangleShape vaisseau(sf::Vector2f(50, 50));
        vaisseau.setFillColor(sf::Color::Green);
        vaisseau.setPosition(g_xposition,g_yposition);

        //les caractéristique du vaisseau méchant
        sf::RectangleShape vmechant(sf::Vector2f(50, 50));
        vmechant.setFillColor(sf::Color::Yellow);
        for (int i = 0; i < 8; i++) {

            vmechant.setPosition(xmechant * i,ymechant);
        }


        //les caractéristique du missile vaisseau gentille
        sf::CircleShape g_missil(50);
        g_missil.setFillColor(sf::Color::Red);
        g_missil.setPosition(g_xmissile,g_ymissile);








        //systéme pour faire bouger le vaisseau gentille
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            if(g_xposition > -10) {
                g_xposition = g_xposition - 5;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            if(g_xposition < 760) {
                g_xposition = g_xposition + 5;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            if(g_yposition > 680) {
                g_yposition = g_yposition - 5;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            if(g_yposition < 775) {
                g_yposition = g_yposition + 5;
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            g_missil.setPosition(vaisseau.getPosition());

            for (float i = g_ymissile; i >= 100; i=i-1){
                std::cout<< g_ymissile << std::endl;
            }

        }



        window.draw(vmechant);
        window.draw(vaisseau);
        window.display();
        window.clear(color);
    }

    std::cout << "fenetre fermer" << std::endl;

    gentille.attaquer(mechant);
    mechant.attaquer(gentille);

    std::cout << "gentille" << std::endl;
    gentille.afficherEtat();
    std::cout << std::endl << "mechant" << std::endl;
    mechant.afficherEtat();
    if (gentille.afficherEtat() == 90) {
        std::cout << "20 is greater than 18";
    }

    return 0;
}