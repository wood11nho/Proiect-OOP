#include "rlutil.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Echipa.h"
#include "Jucator.h"
#include "Transfer.h"
#include "Imprumut.h"
#include "Meci.h"
#include "Item.h"
#include "Adidas.h"
#include "Energizant.h"
#include "Etape.h"
#include "Clasament.h"
#include "Energizant_factory.h"
#include <memory>
#include <fstream>
#include <algorithm>

#include "ext/random.hpp"

using Random = effolkronium::random_static;

template <typename T>
void mySort(std::vector<std::shared_ptr<T>>& vec){
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
        return *a < *b;

    });

    for(auto &i:vec)
        std::cout<<*i<<"\n";
    std::cout << '\n';
}

template <class T>
class Statistici_jucator {
private:
    // Variable of type T
    T camp;

public:

    explicit Statistici_jucator(const T &camp) : camp(camp) {}

    [[nodiscard]] T getCamp() const {
        return camp;
    }

    void setCamp(const T &camp_) {
        Statistici_jucator::camp = camp_;
    }

    void afisStatistici(){
        std::cout<<camp;
    }

    Statistici_jucator() {

    }
};

int Adidas::nradidasi=0;
int Energizant::nrenerg=0;
int Echipa::id1 = 0;

int main() {

    std::ifstream f1("echipe.in");
    Echipa empty_team(0, 0, "Echipa test");
//    Jucator empty_jucator1;
//    cout<<empty_jucator1;
    Jucator empty_jucator(0,"","","",16,30,30,30,empty_team,1, 1, 1, 99);

    Etape vector_meciuri(std::vector<Meci> {});
    Aplicatie::get_aplicatie().adaugare_echipa(empty_team);
    int n = 0;
    int ovr = 0, buget = 0;
    std::string nume;
    f1>>n;
//    std::cout<<"CEVA";
//    std::cout<<n<<"\n";
    for(int i = 1; i <= n; i++)
    {
        f1>>ovr;
        f1>>buget;
        f1>>nume;
        for(int j = 0; j < (int) nume.length(); j++){
            if(nume[j] == '_')
            {
                nume[j] = ' ';
            }
        }
//        std::cout<<ovr<<" "<<buget<<" "<<nume<<"\n";
        try {
            Echipa e1{buget, ovr, nume};
            Aplicatie::get_aplicatie().adaugare_echipa(e1);
        }
        catch(invalidInput &err){
            std::cout<<err.what();
            std::cout<<"\n";
        }
    }

//    Aplicatie::get_aplicatie().afisare_vechipe();

    std::vector<std::shared_ptr<Item>> test;
    Jucator j1(1,"Stoica","Elias","Romania",19,70,45,50,empty_team,15, 10, 25, 99);
    try {
        Energizant nrg1(5, "NRG Classic", 100, 0);
        Energizant nrg2(30, "NRG Bronze", 100, 2);
        Energizant nrg3(70, "NRG Silver", 100, 3);
        Energizant nrg4(125, "NRG Gold", 100, 4);
        Adidas a1(15, "Adidas Nemezis", 3, 1, 1);
        Adidas a2(15, "Nike Tiempo", 1, 3, 1);
        Adidas a3(15, "Puma One", 1, 1, 3);
        Adidas a4(30, "Adidas Predator", 6, 2, 2);
        Adidas a5(30, "Nike Mercurial", 2, 6, 2);
        Adidas a6(30, "Puma Future", 2, 2, 6);
        Adidas a7(100, "Nike Mercurial Superfly x Cristiano Ronaldo", 15, 5, 10);
        Adidas a8(100, "Adidas x Speedflow Messi Unparalleled", 10, 5, 15);

        j1.cumpara(nrg1, Aplicatie::get_aplicatie());
        j1.consuma(nrg1);
        std::cout<<j1;

        Aplicatie::get_aplicatie().addItemConsumabile(nrg1.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(nrg2.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(nrg3.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(nrg4.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(a1.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(a2.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(a3.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(a4.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(a5.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(a6.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(a7.clone());
        Aplicatie::get_aplicatie().addItemConsumabile(a8.clone());
        test.push_back(nrg1.clone());
        test.push_back(nrg4.clone());
        test.push_back(nrg3.clone());
        test.push_back(nrg2.clone());
        test.push_back(a2.clone());
        test.push_back(a4.clone());
        test.push_back(a5.clone());
        test.push_back(a1.clone());
        test.push_back(a7.clone());
//        Aplicatie::get_aplicatie().afisare_consumabile();
//        std::cout<<"\n------------------------------------------------------------------\n";
//        mySort<Item>(Aplicatie::get_aplicatie().getMultimeConsumabile());
        std::cout<<"\nINCEPUT\n";
        mySort<Item>(test);
        std::cout<<"\nSFARSIT\n";

    }
    catch(invalidStat &err){
        std::cout<<err.what();
        std::cout<<"\n";
    }
    Aplicatie::get_aplicatie().afisare_consumabile();
    std::cout<<Energizant::getNrenerg()<<"  energizante \n"<<Adidas::getNradidasi()<<"  adidasi\n";

//    Inventar inventar_player(std::vector<std::shared_ptr<Item>> {});
//    Inventar multime_consumabile(std::vector<std::shared_ptr<Item>> {});

//    cout<<multime_consumabile;


//    cout<<vector_echipe<<"\n";

    Item* b = new Energizant(555,"Red Bull", 99, 10);
    Energizant energ1 = Energizant_factory::energ_full();
    Energizant energ2 = Energizant_factory::energ_skill();
    Energizant energ3 = Energizant_factory::energ_fitness();

    try
    {
        [[maybe_unused]]auto& baza1 = static_cast<Energizant&>(energ1);
        [[maybe_unused]]auto& baza2 = static_cast<Energizant&>(energ2);
        [[maybe_unused]]auto& baza3 = static_cast<Energizant&>(energ3);
    }
    catch (std::bad_cast& err)
    {
        std::cout << err.what() << '\n';
        rlutil::anykey();
    }

    try
    {
        [[maybe_unused]]auto& der1 = dynamic_cast<Energizant&>(*b);
        j1.consuma(der1);
    }
    catch (std::bad_cast& err)
    {
        std::cout << err.what() << '\n';
    }

    auto* der2 = dynamic_cast<Adidas*>(b);
    if(der2 != nullptr)
    {
        der2->folosit_de(j1);
    }
    else
    {
        std::cout << "Nu a reusit conversia cu pointer\n";
    }
    delete b;

    Echipa e2(5000, 90, "Real Madrid");

    Imprumut impr{(Echipa &) j1.getEchipa(), e2, j1, 1};
    impr.Imprumutare(1);



    std::cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
    std::cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';
    Jucator your_player;
    std::string tasta;
    do
    {
        std::cin>>tasta;
            if(tasta == "1")
                your_player.creeaza_jucator();
            else{
                if(tasta != "0") {
                    std::cout << "Input Invalid!!!\n";
                    std::cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
                    std::cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';

                }
                else return 0;
            }
    }while(tasta!= "1");

    Statistici_jucator<Jucator> j;
    j.afisStatistici();
    j.setCamp(your_player);
    Statistici_jucator<Echipa> ech((Echipa&) your_player.getEchipa());
    Statistici_jucator<int> goals(0);
    Statistici_jucator<int> assists(0);

    do {
        std::cout << "Totul este pregatit! Hai sa incepem\n";
        std::cout << "--------------------------------------------------\n";
        std::cout << "1.  Alege echipa\n";
        std::cout << "0.  Inchide jocul\n";
        std::cin >> tasta;
            if (tasta == "1") {
                int echipe_disp = 0;
                srand((unsigned int) time(nullptr));
                for (int i = 1; i < (int)Aplicatie::get_aplicatie().getVectorEchipe().size(); i++) {
                    if (rand() % 2 == 1) {
                        Aplicatie::get_aplicatie().este_valabila(true);
                        echipe_disp++;
                    }
                    else Aplicatie::get_aplicatie().este_valabila(false);
                }
                if(echipe_disp == 0)
                    Aplicatie::get_aplicatie().setEchDisp();
//              cout<<vechipedisp;
                std::cout << "Urmatoarele echipe sunt disponibile: \n";
                for (int i = 1; i < (int)Aplicatie::get_aplicatie().getVectorEchipe().size(); i++) {
                    if (Aplicatie::get_aplicatie().getEchDisp().at(i - 1)) {
                        std::cout << Aplicatie::get_aplicatie().getVectorEchipe()[i].getId() << ". "
                             << Aplicatie::get_aplicatie().getVectorEchipe()[i].getNume() << "\n";
                    }
                }
                your_player.alege_echipa(Aplicatie::get_aplicatie());
                ech.setCamp((Echipa&)j1.getEchipa());
                Item* adidasi_default = new Adidas(10,"Adidasi Starter Pack",1,1,1);
                auto* derivata = dynamic_cast<Adidas*>(adidasi_default);
                if(derivata != nullptr)
                {
                    derivata->folosit_de(j1);
                }
                else
                {
                    std::cout << "Nu a reusit conversia cu pointer\n";
                }
                delete adidasi_default;


            }
            else if(tasta == "0")
                return 0;
            else{
                std::cout<<"Input invalid!!!\n";
                rlutil::anykey();
            }

        }
    while(tasta!="1");

    int acasa = 1;
    do
    {
        rlutil::cls();
        std::cout<<"Alege o optiune dintre cele de mai jos.\n";
        std::cout<<"1. Joaca meci amical\n";
        std::cout<<"2. Antrenament\n";
        std::cout<<"3. Magazin\n";
        std::cout<<"4. Joaca in campionat.\n";
        std::cout<<"5. Inventar\n";
        std::cout<<"6. Iesi din joc\n";
        std::cin>>tasta;
            if (tasta == "1") {
                int ok = 1;
                while (tasta!="2"){
                    do{
                    rlutil::cls();
                    std::cout << "Meci amical\n";
                    ok++;
                    int i = Random::get(1, Aplicatie::get_aplicatie().getNrechipe());
                    while (i == your_player.getEchipa()->getId())
                        i = Random::get(1, Aplicatie::get_aplicatie().getNrechipe());
                    std::cout << "Urmeaza meciul impotriva celor de la " << Aplicatie::get_aplicatie().getVectorEchipe()[i].getNume()
                         << "\n";
                    std::cout << "1. Incepe meciul\n";
                    std::cout << "2. Inapoi la meniu\n";
                        std::cout<<"\nAlegere: ";
                        std::cin >> tasta;
                        std::cout<<"\n";
                    if (tasta == "1") {
                        vector_meciuri.adaugare_meci(Meci((Echipa &) your_player.getEchipa(), (Echipa &) Aplicatie::get_aplicatie().getVectorEchipe()[i],
                                     {0, 0}));
                        vector_meciuri.last_one().playmatch();
                        std::cout << "\n";
                        std::cout << "Statistici: \n";
                        std::cout << "              "<<your_player.getEchipa()->getNume() << "   -   "<<Aplicatie::get_aplicatie().getVectorEchipe()[i].getNume()<<"\n";
                        vector_meciuri.last_one().statistici();
                        std::cout << "1. Continua\n";
                        std::cout << "2. Meniu principal\n";
                        std::cin >> tasta;
                    } else {
                        std::cout<<"\nAi apasat o tasta gresita! Incearca din nou\n";
                    }
                    }while(tasta!="2");

                }

            }
            else if(tasta == "2")
            {
                do {
                    //Antrenament
                    rlutil::cls();
                    your_player.antrenament();
                    std::cout << "\n";
                    std::cout << "1. Antrenament nou";
                    std::cout << "2. Meniu Principal";
                    std::cin >> tasta;
                }while(tasta!="2");
            }
            else if(tasta == "3")
            {
                do {
                    rlutil::cls();
                    std::cout << "MAGAZIN";
                    std::cout << "\n-------------------------------------";
                    Aplicatie::get_aplicatie().afisare_consumabile();
                    std::cout << "\n-------------------------------------";
                    std::cout<<j1.getAvere();
                    std::cout<<"\nPentru a cumpara item-ul dorit, scrieti numarul corespunzator acestuia: ";
                    std::cout<<"\nITEM DORIT: ";
                    std::cin >> tasta;
                    do {
                        if (std::stoi(tasta) >= 1 and std::stoi(tasta) <= (int) Aplicatie::get_aplicatie().getMultimeConsumabile().size() ) {
                            your_player.cumpara(*Aplicatie::get_aplicatie().getMultimeConsumabile().at(std::stoi(tasta) - 1), Aplicatie::get_aplicatie());
                            tasta = "0";
                            //aici ori il adaug la colectie, ori il consum
                        } else {
                            std::cout << "\nTasta incorecta! Alege din nou!\n";
                            std::cin >> tasta;
                        }
                    }
                    while(tasta!="0");
                    std::cout<<"-------------------------------------";
                    std::cout<<"\n0. Inapoi la meniul principal.";
                    std::cout<<"\n1. Incearca din nou\n Alegere: ";
                    std::cin>>tasta;
                    std::cout<<"\n";

                }while(tasta!="0");

            }
            else if(tasta == "4")
            {
                do {
                    rlutil::cls();
                    std::cout << "Etape\n---------------------------------------";
                    Clasament::get_clasament().creare_clasament(Aplicatie::get_aplicatie());
                    vector_meciuri.joaca_campionat(Aplicatie::get_aplicatie(), your_player);
                    rlutil::cls();
                    std::cout<<Clasament::get_clasament();
                    std::cout<<"\n-----------------------------------\n";
                    Clasament::get_clasament().afisare_campioana();
                    std::cout<<"\n-----------------------------------\n";
                    std::cout<<"\nGoluri marcate: "<<goals.getCamp();
                    std::cout<<"\n-----------------------------------\n";
                    std::cout <<"\n0. Meniu principal\n";
                    std::cin>>tasta;
                }
                while(tasta!="0");
            }
            else if(tasta == "5")
            {
                do {
                    Aplicatie::get_aplicatie().afisare_consumabile();
                    std::cout<<"\n------------------------------------------------------------\n";
                    mySort<Item>(Aplicatie::get_aplicatie().getMultimeConsumabile());
                    std::cout << "\n0. Meniu principal\n";
                    std::cin>>tasta;
                }
                while(tasta!="0");
            }
            else
            {
                if(tasta!="6") {
                    std::cout<<"Input invalid!!!\n";
                    rlutil::anykey();
                }
                else acasa = 0;
            }

        }
    while(acasa!=0);

}