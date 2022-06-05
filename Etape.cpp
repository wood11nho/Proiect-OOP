//
// Created by Elias Stoica on 18-May-22.
//

#include "Etape.h"

Etape::Etape(const std::vector<Meci> &vectorMeciuri) : VectorMeciuri(vectorMeciuri) {}

std::ostream &operator<<(std::ostream &os, const Etape &meciuri) {
    os << "VectorMeciuri: ";
    int i = 0;
    for (const auto& meci1 : meciuri.VectorMeciuri) {
        i = i + 1;
        os << "Meciul" << i << meci1<<"\n";
    }
    return os;
}

void Etape::adaugare_meci(const Meci &m1) {
    this->VectorMeciuri.push_back(m1);
}

Meci &Etape::last_one() {
    return VectorMeciuri.back();
}

void Etape::joaca_campionat(Aplicatie &a1, Jucator &j1) {
    for(int i = 0 ;i < a1.getNrechipe() * 2 - 2;i++){
        int mid = a1.getNrechipe() / 2;
        std::vector<Echipa> v1, v2;
//        vEchipe v1({}), v2({});
        for(int j = 1; j<=mid;j++)
            v1.push_back((Echipa &) a1.getVectorEchipe().at(j));
        for(int j = a1.getNrechipe();j>mid;j--)
            v2.push_back((Echipa &) a1.getVectorEchipe().at(j));
//        std::cout<<v1<<"\n"<<v2;
        std::cout<<"\nETAPA "<<i + 1<<"\n";
        if((i%2==1 and i <= a1.getNrechipe() - 1) or (i%2 == 0 and i>a1.getNrechipe() - 1)){
            for(int j = 0;j<mid;j++){
                this->adaugare_meci(Meci((Echipa &) v1.at(j), (Echipa &) v2.at(j), {0,0}));
                std::cout<<"\n---"<<VectorMeciuri.back().getTeam1().getNume()<<" "<<VectorMeciuri.back().getScor().first<<" - "<<VectorMeciuri.back().getScor().second<<" "<<VectorMeciuri.back().getTeam2().getNume()<<"\n\n\n";
            }
        }
        else if((i%2 == 1 and i > a1.getNrechipe() - 1) or (i%2 == 0 and i<=a1.getNrechipe() - 1)){
            for(int j = 0;j<mid;j++){
                this->adaugare_meci(Meci((Echipa &) v2.at(j), (Echipa &) v1.at(j), {0,0}));
                std::cout<<"\n---"<<VectorMeciuri.back().getTeam1().getNume()<<" "<<VectorMeciuri.back().getScor().first<<" - "<<VectorMeciuri.back().getScor().second<<" "<<VectorMeciuri.back().getTeam2().getNume()<<"\n\n\n";
            }
        }
        char tasta;
        do {
            std::cout << "\n1. Joaca etapa\n";
            std::cin >> tasta;
            if (tasta == '1') {
                for(int k = 0;k<mid;k++){
                    if(VectorMeciuri.at(k).getTeam1() == j1.getEchipa() or VectorMeciuri.at(k).getTeam2() == j1.getEchipa())
                    {
                        VectorMeciuri.at(k).playmatch();
                        rlutil::cls();
                        std::cout<<"\n---"<<VectorMeciuri.at(k).getTeam1().getNume()<<"  -  "<<VectorMeciuri.at(k).getTeam2().getNume()<<"\n\n\n";
                        std::cout<<"\n1. Incepe meci\n";
                        std::string incepere;
                        do {
                            std::cout<<"\nAlegere: ";
                            std::cin>>incepere;
                            if (incepere == "1") {
                                for(int timp = 0;timp<=90;timp+=10){
                                    rlutil::cls();
                                    std::cout<<"Minutul "<<timp<<"\n";
                                    std::cout<<"\n---"<<VectorMeciuri.at(k).getTeam1().getNume()<<"  -  "<<VectorMeciuri.at(k).getTeam2().getNume()<<"\n\n";
                                    //aici urmeaza sa fac niste actiuni pentru a da gol
                                    rlutil::anykey();
                                }
                            }
                            else std::cout<<"Ai apasat o tasta gresita!\n";
                        }
                        while(incepere!="1");
                        break;
                    }
                }
                for (int k = 1; k <= mid; k++) {
                    VectorMeciuri.back().playmatch();
                    std::cout<<"\nMeciul s-a terminat!\n";
                    std::cout<<"REZULTAT FINAL: \n";
                    std::cout<<VectorMeciuri.back().getTeam1().getNume()<<" "<<VectorMeciuri.back().getScor().first<<" - "<<VectorMeciuri.back().getScor().second<<" "<<VectorMeciuri.back().getTeam2().getNume();
                    std::cout<<"\n-------------------------------------------";
                    VectorMeciuri.back().statistici();
                    std::cout<<"\n";
                    int goluri1 = 0, goluri2 = 0;
                    goluri1 = VectorMeciuri.back().getScor().first;
                    goluri2 = VectorMeciuri.back().getScor().second;
                    if(goluri1 > goluri2){
                        Clasament::get_clasament().setPunctaj(VectorMeciuri.back().getTeam1(), 3);
                    }
                    else if(goluri1 < goluri2){
                        Clasament::get_clasament().setPunctaj(VectorMeciuri.back().getTeam2(), 3);
                    }
                    else
                    {
                        Clasament::get_clasament().setPunctaj(VectorMeciuri.back().getTeam1(), 1);
                        Clasament::get_clasament().setPunctaj(VectorMeciuri.back().getTeam2(), 1);
                    }
                    VectorMeciuri.pop_back();
                }
                std::cout<<"\nAcestea sunt rezultatele din etapa "<< i + 1 <<".\n";
                std::cout<<"\nClasament:\n---------------------------------\n";
                std::cout<<Clasament::get_clasament();
                rlutil::anykey();
            } else {
                std::cout << "Ai introdus o tasta gresita. Incearca din nou!";
                rlutil::anykey();
            }
        }while(tasta!='1');
        Echipa aux(a1.getVectorEchipe().back());
        a1.pop_echipa();
        a1.insert_echipa(2, aux);
    }
}
