//
// Created by Elias Stoica on 30-May-22.
//

#include "Clasament.h"

Clasament &Clasament::get_clasament() {
    static Clasament clas;
    return clas;
}


void Clasament::setPunctaj(const Echipa& e1, int nr_puncte) {
    for(int i = 0; i < (long long) punctaj.size();i++)
    {
        if(punctaj[i].first.getNume() == e1.getNume())
        {
            punctaj[i].second += nr_puncte;
        }
    }
}

void Clasament::setCampioana(const Echipa &campioana) {
    Clasament::campioana = campioana;
}
