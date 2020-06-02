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
    float m_xposition = 20;
    float m_yposition = 20;
    int tir = 0;
    int couleurm = 0;





    while(window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                //gérerla direction du vaisseau gentille
                if (event.key.code == sf::Keyboard::Up){
                    if(g_yposition > 680) {
                        g_yposition = g_yposition - 10;
                        if (tir == 0){
                            g_ymissile = g_ymissile - 10;
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::Down){
                    if(g_yposition < 775) {
                        g_yposition = g_yposition + 10;
                        if (tir == 0){
                            g_ymissile = g_ymissile + 10;
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::Left){
                    if (g_xposition > -10) {
                        g_xposition = g_xposition - 10;
                        if (tir == 0){
                            g_xmissile = g_xmissile -10;
                        }
                    }
                }
                if (event.key.code == sf::Keyboard::Right){
                    if(g_xposition < 760) {
                        g_xposition = g_xposition + 10;
                        if (tir == 0){
                            g_xmissile = g_xmissile +10;
                        }
                    }
                }
                //gérer le tir du missile
                if (event.key.code == sf::Keyboard::Space) {
                    if (g_ymissile > 0) {
                        tir = 1;
                        g_ymissile = g_ymissile - 700;
                    }
                    //enlever de la vie au vaisseau méchant
                    if((g_xmissile >= m_xposition)&&(g_xmissile <= m_xposition+40)){
                        std::cout << std::endl << g_ymissile << m_yposition << m_xposition<<std::endl;
                            gentille.attaquer(mechant);
                            if(mechant.afficherEtat() == 0) {
                                std::cout << std::endl << "mort" << std::endl;
                                // ce qui va changer la couleur du méchant pour dire quil est élimminer
                                couleurm = 1;

                            }




                    }

                }
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    tir = 0;
                    g_ymissile = g_yposition;
                    g_xmissile = g_xposition;
                }

            }

        }


        //les caractéristique du  vaisseau gentille
        sf::RectangleShape vaisseau(sf::Vector2f(50, 50));
        vaisseau.setFillColor(sf::Color::Green);
        vaisseau.setPosition(g_xposition,g_yposition);

        //les caractéristique du missile vaisseau gentille
        sf::CircleShape g_missil(10);
        g_missil.setFillColor(sf::Color::Red);
        g_missil.setPosition(g_xmissile,g_ymissile);

        //les caractéristique du vaisseau méchant
        sf::RectangleShape vmechant(sf::Vector2f(50, 50));
        vmechant.setFillColor(sf::Color::Yellow);
        if(couleurm == 1){
            vmechant.setFillColor(sf::Color::Black);
        }
        vmechant.setPosition(m_xposition,m_yposition);



        //systéme pour faire bouger le vaisseau gentille
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            if (g_xposition > -10) {
                g_xposition = g_xposition - 5;
                if (tir == 0){
                    g_xmissile = g_xmissile -5;
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            if(g_xposition < 760) {
                g_xposition = g_xposition + 5;
                if (tir == 0){
                    g_xmissile = g_xmissile +5;
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            if(g_yposition > 680) {
                g_yposition = g_yposition - 5;
                if (tir == 0){
                    g_ymissile = g_ymissile - 5;
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            if(g_yposition < 775) {
                g_yposition = g_yposition + 5;
                if (tir == 0){
                    g_ymissile = g_ymissile + 5;
                }
            }

        // faire bouger le méchant
        m_xposition = m_xposition-m_xposition;
            if((m_xposition == 700)||(m_xposition == 10)){
                m_yposition = m_yposition-m_yposition
            }




        window.draw(vmechant);
        window.draw(g_missil);
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
    if (mechant.afficherEtat() == 20) {
        std::cout << "20 is greater than 18";
    }

    return 0;
}