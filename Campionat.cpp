//
// Created by Elias Stoica on 18-May-22.
//

#include "Campionat.h"

Campionat::Campionat(const std::vector<Meci> &vectorMeciuri) : VectorMeciuri(vectorMeciuri) {}

std::ostream &operator<<(std::ostream &os, const Campionat &meciuri) {
    os << "VectorMeciuri: ";
    int i = 0;
    for (const auto& meci1 : meciuri.VectorMeciuri) {
        i = i + 1;
        os << "Meciul" << i << meci1<<"\n";
    }
    return os;
}

void Campionat::adaugare_meci(const Meci &m1) {
    this->VectorMeciuri.push_back(m1);
}

Meci &Campionat::last_one() {
    return VectorMeciuri.back();
}

void Campionat::joaca_campionat(vEchipe &ve) {
    for(int i = 0 ;i< ve.getNrechipe();i++){
        int mid = ve.getNrechipe() / 2;
        vEchipe v1({}), v2({});
        for(int j = 1; j<=mid;j++)
            v1.adaugare_echipa((Echipa &)ve.getVectorEchipe().at(j));
        for(int j = ve.getNrechipe();j>mid;j--)
            v2.adaugare_echipa((Echipa &) ve.getVectorEchipe().at(j));
        std::cout<<v1<<"\n"<<v2;
        if(i%2==1){
            std::cout<<"\nETAPA "<<i + 1<<"\n";
            for(int j = 0;j<mid;j++){
                this->adaugare_meci(Meci((Echipa &) v1.getVectorEchipe().at(j), (Echipa &) v2.getVectorEchipe().at(j), {0,0}));
                std::cout<<"\n---"<<VectorMeciuri.back().getTeam1().getNume()<<" "<<VectorMeciuri.back().getScor().first<<" - "<<VectorMeciuri.back().getScor().second<<" "<<VectorMeciuri.back().getTeam2().getNume()<<"\n\n\n";
            }
        }
        else{
            std::cout<<"\nETAPA "<<i + 1<<"\n";
            for(int j = 0;j<mid;j++){
                this->adaugare_meci(Meci((Echipa &) v2.getVectorEchipe().at(j), (Echipa &) v1.getVectorEchipe().at(j), {0,0}));
                std::cout<<"\n---"<<VectorMeciuri.back().getTeam1().getNume()<<" "<<VectorMeciuri.back().getScor().first<<" - "<<VectorMeciuri.back().getScor().second<<" "<<VectorMeciuri.back().getTeam2().getNume()<<"\n\n\n";
            }
        }
        char tasta;
        do {
            std::cout << "\n1. Joaca etapa\n";
            std::cin >> tasta;
            if (tasta == '1') {
                for (int k = 1; k <= mid; k++) {
                    VectorMeciuri.back().playmatch();
                    std::cout<<"\n-------------------------------------------";
                    VectorMeciuri.back().statistici();
                    std::cout<<"\n";
                    VectorMeciuri.pop_back();
                }
                std::cout<<"\nAcestea sunt rezultatele din prima etapa.\n";
                rlutil::anykey();
            } else {
                std::cout << "Ai introdus o tasta gresita. Incearca din nou!";
                rlutil::anykey();
            }
        }while(tasta!='1');
        Echipa aux(ve.getVectorEchipe().back());
        ve.pop_echipa();
        ve.insert_echipa(1, aux);
    }
}
