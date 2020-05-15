//
// Created by clement.theotime on 04/05/2020.
//

#include <iostream>
#include "Vaisseau.h"

int main() {
    Vaisseau gentille(100,20);
    Vaisseau mechant(40,10);

    gentille.attaquer(mechant);
    mechant.attaquer(gentille);

    std::cout << "gentille" << std::endl;
    gentille.afficherEtat();
    std::cout << std::endl << "mechant" << std::endl;
    mechant.afficherEtat();
    if (gentille.afficherEtat() == 100) {
        std::cout << "20 is greater than 18";
    }

    return 0;
}
