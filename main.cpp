#include "rlutil.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Echipa.h"
#include "Jucator.h"
#include "vEchipe.h"
#include "Transfer.h"
#include "Imprumut.h"
#include "Meci.h"
#include "Echipe_disponibile.h"
#include "Item.h"
#include "Adidas.h"
#include "Energizant.h"
#include "Inventar.h"
#include "Campionat.h"
#include "Clasament.h"
#include <memory>
#include <fstream>



int Adidas::nradidasi=0;
int Energizant::nrenerg=0;
int Echipa::id1 = 0;

int main() {

    std::ifstream f1("C:\\Users\\Elias Stoica\\Documents\\GitHub\\Proiect-OOP\\echipe.in");
    Echipa empty_team(0, 0, "");
//    Jucator empty_jucator1;
//    cout<<empty_jucator1;
    Jucator empty_jucator(0,"","","",16,30,30,30,empty_team,1, 1, 1, 99);

    vEchipe vector_echipe(std::vector<Echipa> {});
    Campionat vector_meciuri(std::vector<Meci> {});
    vector_echipe.adaugare_echipa(empty_team);
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
        std::cout<<ovr<<" "<<buget<<" "<<nume<<"\n";
        vector_echipe.adaugare_echipa({buget,ovr,nume});
    }

    std::cout<<vector_echipe;

    Jucator j1(1,"Stoica","Elias","Romania",19,70,45,50,empty_team,15, 10, 25, 99);
    Adidas a1(15, "Adidas Nemezis", 3, 1, 1);
    Adidas a2(15, "Nike Tiempo", 1, 3, 1);
    Adidas a3(15, "Puma One", 1, 1, 3);
    Adidas a4(30, "Adidas Predator", 6, 2, 2);
    Adidas a5(30, "Nike Mercurial", 2, 6, 2);
    Adidas a6(30, "Puma Future", 2, 2, 6);
    Adidas a7(100, "Nike Mercurial Superfly x Cristiano Ronaldo", 15, 5, 10);
    Adidas a8(100, "Adidas x Speedflow Messi Unparalleled", 10, 5, 15);
    Energizant nrg1(5, "NRG Classic", 100, 1);
    Energizant nrg2(30, "NRG Bronze", 100, 2);
    Energizant nrg3(70, "NRG Silver", 100, 3);
    Energizant nrg4(125, "NRG Gold", 100, 4);

    std::cout<<Energizant::getNrenerg()<<"  energizante \n"<<Adidas::getNradidasi()<<"  adidasi\n";

    Inventar inventar_player(std::vector<std::shared_ptr<Item>> {});

    Inventar multime_consumabile(std::vector<std::shared_ptr<Item>> {});
    multime_consumabile.addItem(nrg1.clone());
    multime_consumabile.addItem(nrg2.clone());
    multime_consumabile.addItem(nrg3.clone());
    multime_consumabile.addItem(nrg4.clone());
    multime_consumabile.addItem(a1.clone());
    multime_consumabile.addItem(a2.clone());
    multime_consumabile.addItem(a3.clone());
    multime_consumabile.addItem(a4.clone());
    multime_consumabile.addItem(a5.clone());
    multime_consumabile.addItem(a6.clone());
    multime_consumabile.addItem(a7.clone());
    multime_consumabile.addItem(a8.clone());

//    cout<<multime_consumabile;


//    cout<<vector_echipe<<"\n";

    Item* b = new Energizant(555,"Red Bull", 99, 10);
    try
    {
        [[maybe_unused]]auto& der1 = dynamic_cast<Energizant&>(*b);
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

    j1.cumpara(nrg1, inventar_player);
    j1.consuma(nrg1);
    std::cout<<j1;

    Echipa e2(5000, 90, "Real Madrid");

    Imprumut impr{(Echipa &) j1.getEchipa(), e2, j1, 1};
    impr.Imprumutare(1);

    std::cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
    std::cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';
    Jucator your_player;
    int tasta = 0;
    do
    {
        std::cin>>tasta;
        try {
            if(tasta == 1)
                your_player.creeaza_jucator();
            else{
                if(tasta!=0)
                    throw (invalidInput{"Input invalid!!!"});
                else return 0;
            }
        }
        catch(std::exception &err){
            std::cout<<err.what() << '\n';
            rlutil::anykey();
            rlutil::cls();
            std::cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
            std::cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';
        }
    }while(tasta!=1);
    do {
        std::cout << "Totul este pregatit! Hai sa incepem\n";
        std::cout << "--------------------------------------------------\n";
        std::cout << "1.  Alege echipa\n";
        std::cout << "0.  Inchide jocul\n";
        std::cin >> tasta;
        try {
            if (tasta == 1) {
                std::vector<bool> v2;
                int echipe_disp = 0;
                Echipe_disponibile vechipedisp(v2);
                srand((unsigned int) time(nullptr));
                for (int i = 1; i < (int)vector_echipe.getVectorEchipe().size(); i++) {
                    if (rand() % 2 == 1) {
                        vechipedisp.este_valabila(true);
                        echipe_disp++;
                    }
                    else vechipedisp.este_valabila(false);
                }
                if(echipe_disp == 0)
                    vechipedisp.setEchDisp();
//              cout<<vechipedisp;
                std::cout << "Urmatoarele echipe sunt disponibile: \n";
                for (int i = 1; i < (int)vector_echipe.getVectorEchipe().size(); i++) {
                    if (vechipedisp.getEchDisp().at(i - 1)) {
                        std::cout << vector_echipe.getVectorEchipe()[i].getId() << ". "
                             << vector_echipe.getVectorEchipe()[i].getNume() << "\n";
                    }
                }
                your_player.alege_echipa(vector_echipe, vechipedisp);
            }
            else if(tasta == 0)
                return 0;
            else{
                throw(invalidInput("Input invalid!!!"));
            }
        }
        catch(std::exception &err){
            std::cout<<err.what() << '\n';
            rlutil::anykey();
        }


    }while(tasta!=1);
    int acasa = 1;
    do
    {
        rlutil::cls();
        std::cout<<"Alege o optiune dintre cele de mai jos.\n";
        std::cout<<"1. Joaca meci amical\n";
        std::cout<<"2. Antrenament\n";
        std::cout<<"3. Magazin\n";
        std::cout<<"4. Joaca in campionat.\n";
        std::cout<<"5. Iesi din joc\n";
        std::cin>>tasta;
        try {

            if (tasta == 1) {

                int ok = 1;
                while (tasta != 2) {
                    rlutil::cls();
                    std::cout << "Meci amical\n";
                    ok++;
                    int i = rand() % 6 + 1;
                    while (i == your_player.getEchipa()->getId())
                        i = rand() % 6 + 1;
                    std::cout << "Urmeaza meciul impotriva celor de la " << vector_echipe.getVectorEchipe()[i].getNume()
                         << "\n";
                    std::cout << "1. Incepe meciul\n";
                    do{
                        std::cout<<"\nAlegere: ";
                    std::cin >> tasta;
                        std::cout<<"\n";
                    if (tasta == 1) {
                        vector_meciuri.adaugare_meci(Meci((Echipa &) your_player.getEchipa(), (Echipa &) vector_echipe.getVectorEchipe()[i],
                                     {0, 0}));
                        vector_meciuri.last_one().playmatch();
                        std::cout << "\n";
                        std::cout << "Statistici: \n";
                        std::cout << "              "<<your_player.getEchipa()->getNume() << "   -   "<<vector_echipe.getVectorEchipe()[i].getNume()<<"\n";
                        vector_meciuri.last_one().statistici();
                        std::cout << "1. Continua\n";
                        std::cout << "2. Meniu principal\n";
                        std::cin >> tasta;
                    } else {
                        std::cout<<"\nAi apasat o tasta gresita! Incearca din nou\n";
                    }
                    }while(tasta!=1);

                }

            }
            else if(tasta == 2)
            {
                do {
                    //Antrenament
                    rlutil::cls();
                    your_player.antrenament();
                    std::cout << "\n";
                    std::cout << "1. Antrenament nou";
                    std::cout << "2. Meniu Principal";
                    std::cin >> tasta;
                }while(tasta!=2);
            }
            else if(tasta == 3)
            {
                do {
                    rlutil::cls();
                    std::cout << "MAGAZIN";
                    std::cout << "\n-------------------------------------";
                    std::cout<<multime_consumabile;
                    std::cout<<"\nPentru a cumpara item-ul dorit, scrieti numarul corespunzator acestuia: ";
                    std::cout<<"\nITEM DORIT: ";
                    std::cin >> tasta;
                    do {
                        if (tasta >= 1 and tasta <= (int) multime_consumabile.getColectie().size() ) {
                            your_player.cumpara(*multime_consumabile.getColectie().at(tasta - 1), inventar_player);
                            tasta = 0;
                            //aici ori il adaug la colectie, ori il consum
                        } else {
                            std::cout << "\nTasta incorecta! Alege din nou!\n";
                            std::cin >> tasta;
                        }
                    }
                    while(tasta!=0);
                    std::cout<<"-------------------------------------";
                    std::cout<<"\n0. Inapoi la meniul principal.";
                    std::cout<<"\n1. Incearca din nou\n Alegere: ";
                    std::cin>>tasta;
                    std::cout<<"\n";

                }while(tasta!=0);

            }
            else if(tasta == 4)
            {
                do {
                    rlutil::cls();
                    std::cout << "Campionat\n---------------------------------------";
                    Clasament::get_clasament().creare_clasament(vector_echipe);
                    vector_meciuri.joaca_campionat(vector_echipe);
                    rlutil::cls();
                    std::cout<<Clasament::get_clasament();
                    std::cout<<"\n-----------------------------------\n";
                    Clasament::get_clasament().afisare_campioana();
                    std::cout << "\n0. Meniu principal\n";
                    std::cin>>tasta;
                }
                while(tasta!=0);
            }
            else
            {
                if(tasta!=0)
                    throw (invalidInput{"Input invalid!!!"});
                else acasa = 0;
            }
        }
        catch(std::exception &err){
            std::cout<<err.what() << '\n';
            rlutil::anykey();
        }
    }
    while(acasa!=0);

}