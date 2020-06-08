//
// Created by clement.theotime on 11/05/2020.
//

#include "Vaisseau.h"
#include <iostream>
#include "SFML/Graphics.hpp"

Vaisseau::Vaisseau():m_vie(100),m_degatarm(20)
{}
Vaisseau::Vaisseau(int vie,int degatarm, bool gentille):m_vie(vie),m_degatarm(degatarm),m_gentille(gentille)
{}

void Vaisseau::recevoirDegats(int nbDegats) {

        m_vie -= nbDegats;

        if (m_vie < 0){
            m_vie = 0; //On met la vie à 0 (cela veut dire mort)
        }
}



void Vaisseau::attaquer(Vaisseau &cible) {
    cible.recevoirDegats(m_degatarm);

}

int Vaisseau::afficherEtat() const {
    {
        return m_vie;

    }
}








