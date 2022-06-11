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
            int fitness_utilizat = 0;
            int goluri_player = 0;
            if (tasta == '1') {
                for(int k = 0;k<mid;k++){
                    if(VectorMeciuri.at(k).getTeam1() == j1.getEchipa() or VectorMeciuri.at(k).getTeam2() == j1.getEchipa())
                    {
                        std::vector<int> sanse = VectorMeciuri.at(k).setare_sanse();

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
                                    fitness_utilizat += 5;
                                    std::cout<<"\n---"<<VectorMeciuri.at(k).getTeam1().getNume()<<" "<<VectorMeciuri.at(k).getScor().first<<"  -  "<<VectorMeciuri.at(k).getScor().second<<" "<<VectorMeciuri.at(k).getTeam2().getNume()<<"\n\n";
                                    int sansa_random = Random::get(0, 150);
                                    if(sansa_random <= j1.getAttStats()){
                                        std::cout<<"\nOcazie buna pentru "<<j1.getPrenume()<<"...\n";
                                        fitness_utilizat += 2;
                                        sansa_random = Random::get(0, 99);
                                        rlutil::anykey();
                                        std::cout<<"\n";
                                        if(sansa_random <= j1.getDrbStats())
                                        {
                                            std::cout<<"\nDribbling-ul este reusit! Sa vedem finalizarea...\n";
                                            fitness_utilizat +=2;
                                            sansa_random = Random::get(0,99);
                                            rlutil::anykey();
                                            if(sansa_random<=j1.getAttStats()) {
                                                std::cout << "\nGOOOOL inscris de " << j1.getPrenume() << "...\n";
                                                goluri_player += 1;
                                                if(VectorMeciuri.at(k).getTeam1() == j1.getEchipa())
                                                    VectorMeciuri.at(k).gol1();
                                                else
                                                    VectorMeciuri.at(k).gol2();
                                                fitness_utilizat +=2;
                                            }
                                            else{
                                                std::cout<<"\nDin pacate, "<<j1.getPrenume()<<" nu nimereste spatiul portii...\n";
                                                fitness_utilizat +=1;
                                            }

                                        }
                                        else {
                                            std::cout << "\nIncercarea de dribbling da gres! Meciul continua...\n";
                                            fitness_utilizat +=1;
                                        }
                                    }
                                    else{
                                        auto nr_random = Random::get(0,150);
                                        if(nr_random <= sanse[0])
                                            VectorMeciuri.at(k).gol1();
                                        else if(nr_random >= 100- sanse[2] and nr_random <=100)
                                            VectorMeciuri.at(k).gol2();
                                    }
                                    rlutil::anykey();
                                    std::cout<<"\n";
                                }
                                rlutil::cls();
                                std::cout<<"Meciul s-a incheiat!\n";
                                std::cout<<"\n---"<<VectorMeciuri.at(k).getTeam1().getNume()<<" "<<VectorMeciuri.at(k).getScor().first<<"  -  "<<VectorMeciuri.at(k).getScor().second<<" "<<VectorMeciuri.at(k).getTeam2().getNume()<<"\n\n";
                                rlutil::anykey();
                            }
                            else std::cout<<"Ai apasat o tasta gresita!\n";
                        }
                        while(incepere!="1");
                        break;
                    }
                }
                std::cout<<"\nAcestea sunt rezultatele din etapa "<< i + 1 <<".\n";
                for (int k = 0; k < mid; k++) {
                    if(VectorMeciuri.back().getTeam1() != j1.getEchipa() and VectorMeciuri.back().getTeam2() != j1.getEchipa())
                        VectorMeciuri.back().playmatch();
                    std::cout<<VectorMeciuri.back().getTeam1().getNume()<<" "<<VectorMeciuri.back().getScor().first<<" - "<<VectorMeciuri.back().getScor().second<<" "<<VectorMeciuri.back().getTeam2().getNume();
                    std::cout<<"\n-------------------------------------------";
                    VectorMeciuri.back().statistici();
                    std::cout<<VectorMeciuri.back().setare_sanse()[0]<< " "<<VectorMeciuri.back().setare_sanse()[1]<< " "<<VectorMeciuri.back().setare_sanse()[2]<<"\n";
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

                std::cout<<"\nClasament:\n---------------------------------\n";
                j1.setFitness(j1.getFitness() - fitness_utilizat);
                j1.setAvere(j1.getAvere() + j1.getSalariu());
                std::cout<<Clasament::get_clasament();
                rlutil::anykey();
                std::cout<<"\n-------------------------------------------------\n";
                std::cout<<"\nFITNESS: "<<j1.getFitness();
                std::cout<<"\nGOLURI: "<<goluri_player;
                std::cout<<"\nASSISTS: "<<0;
                std::cout<<"\nAVERE: "<<j1.getAvere();
                std::cout<<"\n-------------------------------------------------\n";
                rlutil::anykey();
                std::string alegere;
                do {
                    std::cout<<"\n1. Continua";
                    std::cout<<"\n2. Inventar";
                    std::cout<<"\n3. Magazin";
                    std::cout << "\nAlegere: ";
                    std::cin >> alegere;
                    std::cout<<"\n-------------------------";
                    if(alegere == "1")
                    {
                        continue;
                    }
                    else if (alegere == "2")
                    {
                        Aplicatie::get_aplicatie().afisare_colectie();
                    }
                    else if (alegere == "3")
                    {
                        Aplicatie::get_aplicatie().afisare_consumabile();
                        std::cout<<"\nPentru a cumpara item-ul dorit, scrieti numarul corespunzator acestuia: ";
                        std::cout<<"\nITEM DORIT: ";
                        std::string dorinta;
                        std::cin >> dorinta;
                        do {
                            if (std::stoi(dorinta) >= 1 and std::stoi(dorinta) <= (int) Aplicatie::get_aplicatie().getMultimeConsumabile().size() ) {
                                j1.cumpara(*Aplicatie::get_aplicatie().getMultimeConsumabile().at(std::stoi(dorinta) - 1), Aplicatie::get_aplicatie());
                                dorinta = "0";
                                //aici ori il adaug la colectie, ori il consum
                            } else {
                                std::cout << "\nTasta incorecta! Alege din nou!\n";
                                std::cin >> tasta;
                            }
                        }
                        while(dorinta!="0");
                    }
                    else
                    {
                        std::cout << "Ai introdus o tasta gresita. Incearca din nou!";
                        rlutil::anykey();
                    }
                }
                while(alegere!="1");
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
