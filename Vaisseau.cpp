//
// Created by clement.theotime on 11/05/2020.
//

#include "Vaisseau.h"
#include <iostream>

Vaisseau::Vaisseau():m_vie(100),m_degatarm(20)
{}
Vaisseau::Vaisseau(int Vie,int degatarm):m_vie(Vie),m_degatarm(degatarm)
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

