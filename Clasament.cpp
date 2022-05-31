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

void Clasament::setCampioana(const Echipa &campioana_) {
    Clasament::campioana = campioana_;
}

void Clasament::creare_clasament(const vEchipe &v1) {
    std::for_each(v1.getVectorEchipe().begin(), v1.getVectorEchipe().end(), [&](const Echipa& o) { punctaj.emplace_back(o,0); });
}
