//
// Created by clement.theotime on 11/05/2020.
//

#ifndef INVENDERSPACE_VAISSEAU_H
#define INVENDERSPACE_VAISSEAU_H


class Vaisseau {

public:
    Vaisseau();
    Vaisseau(int vie, int degatarm, bool gentille);
    void recevoirDegats(int nbDegats);
    void attaquer(Vaisseau &cible);
    int afficherEtat() const;







private:

    int m_vie;
    int m_degatarm;
    bool m_gentille;


};


#endif //INVENDERSPACE_VAISSEAU_H
