//
// Created by clement.theotime on 11/05/2020.
//

#ifndef INVENDERSPACE_VAISSEAU_H
#define INVENDERSPACE_VAISSEAU_H


class Vaisseau {

public:
    Vaisseau();
    Vaisseau(int m_vie, int m_degatarm);
    void recevoirDegats(int nbDegats);
    void attaquer(Vaisseau &cible);
    int afficherEtat() const;


private:
    int m_vie;
    int m_degatarm;

};


#endif //INVENDERSPACE_VAISSEAU_H
