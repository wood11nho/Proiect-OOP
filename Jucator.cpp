//
// Created by Elias Stoica on 11-Apr-22.
//

#include "Jucator.h"
#include "Energizant.h"
#include "Erori.h"
#include "Inventar.h"

Jucator::Jucator() :
        id(0), nume(""), prenume(""), nationalitate(""), varsta(16), att_stats(30), def_stats(30), drb_stats(30),echipa(
        std::make_optional<Echipa>()), pret(1), salariu(1), avere(1), fitness(100) {

}

Jucator::Jucator(const Jucator &j1) :
        id(j1.id), nume(j1.nume), prenume(j1.prenume), nationalitate(j1.nationalitate), varsta(j1.varsta), att_stats(j1.att_stats), def_stats(j1.def_stats), drb_stats(j1.drb_stats),echipa(j1.echipa), pret(j1.pret), salariu(j1.salariu), avere(j1.avere), fitness(j1.fitness)
{

}

Jucator &Jucator::operator=(const Jucator &j1) {
    id = j1.id;
    nume = j1.nume;
    prenume = j1.prenume;
    nationalitate = j1.nationalitate;
    varsta = j1.varsta;
    att_stats = j1.att_stats;
    def_stats = j1.def_stats;
    drb_stats = j1.drb_stats;
    pret = j1.pret;
    salariu = j1.salariu;
    avere = j1.avere;
    fitness = j1.fitness;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Jucator &jucator) {
    os << "\nid: " << jucator.id << "\nnume: " << jucator.nume << " "<<jucator.prenume<<"\nnationalitate: " << jucator.nationalitate<<"\nvarsta: "<<jucator.varsta<<"\nattacking stats: "<<jucator.att_stats<<"\ndefending stats: "<<jucator.def_stats<<"\ndribbling stats: "<<jucator.drb_stats
       << " \nrating: " << jucator.rating() << "\npret: "<<jucator.pret<<"\nsalariu: "<<jucator.salariu<<"\navere: "<<jucator.avere<<"\nfitness: "<<jucator.fitness<<"\n";
    return os;
}

bool Jucator::containsOnlyLetters(const std::string &str) {
    auto it = std::find_if(str.begin(), str.end(), [](char const &c) {
        return !std::isalpha(c);
    });
    return it == str.end();
}

bool Jucator::containsOnlyDigits(const std::string &str) {
    auto it = std::find_if(str.begin(), str.end(), [](char const &c) {
        return !std::isdigit(c);
    });
    return it == str.end();
}
std::istream &operator>>(std::istream &is, Jucator &jucator) {
    std::cout<<"\nIntrodu numarul jucatorului: ";
    std::string id_aux;
    do {
        try {
            is >> id_aux;
            if(!Jucator::containsOnlyDigits(id_aux) or std::stoi(id_aux) < 1 or std::stoi(id_aux) > 99) {
                throw (invalidID{"Input invalid! Alege un alt numar intre 1-99!"});
            }
            else
                jucator.id = std::stoi(id_aux);
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nIntrodu numarul jucatorului: ";
        }
    }while(!Jucator::containsOnlyDigits(id_aux) or std::stoi(id_aux) < 1 or std::stoi(id_aux) > 99);
    std::cout<<"\nIntrodu numele jucatorului: ";
    std::string nume_aux;
    do {
        try {
            is >> nume_aux;
            if(!Jucator::containsOnlyLetters(nume_aux))
                throw (invalidID{"Input invalid! Alege un nume format doar din litere!"});
            else{
                for(int i = 1 ;i < (int)nume_aux.size();i++){
                    nume_aux[i] = tolower(nume_aux[i]);
                }
                nume_aux[0] = std::toupper(nume_aux[0]);
                jucator.nume = nume_aux;

            }
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nIntrodu numele jucatorului: ";
        }
    }while(!Jucator::containsOnlyLetters(nume_aux));
    std::cout<<"\nIntrodu prenumele jucatorului: ";
    std::string prenume_aux;
    do {
        try {
            is >> prenume_aux;
            if(!Jucator::containsOnlyLetters(prenume_aux))
                throw (invalidID{"Input invalid! Alege un prenume format doar din litere!"});
            else{
                for(int i = 1 ;i < (int)prenume_aux.size();i++){
                    prenume_aux[i] = tolower(prenume_aux[i]);
                }
                prenume_aux[0] = std::toupper(prenume_aux[0]);
                jucator.prenume = prenume_aux;
            }
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nIntrodu prenumele jucatorului: ";
            is >> prenume_aux;
        }
    }while(!Jucator::containsOnlyLetters(prenume_aux));
    std::cout<<"\nIntrodu nationalitatea jucatorului: ";
    std::string nationalitate_aux;
    do {
        try {
            is >> nationalitate_aux;
            if(!Jucator::containsOnlyLetters(nationalitate_aux))
                throw (invalidID{"Input invalid! Alege o nationalitate formata doar din litere!"});
            else{
                for(int i = 1 ;i < (int)nationalitate_aux.size();i++){
                    nationalitate_aux[i] = tolower(nationalitate_aux[i]);
                }
                nationalitate_aux[0] = std::toupper(nationalitate_aux[0]);
                jucator.nationalitate = nationalitate_aux;
            }
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nIntrodu nationalitatea jucatorului: ";
            is >> nationalitate_aux;
        }
    }while(!Jucator::containsOnlyLetters(nationalitate_aux));
    jucator.varsta = 16;
    jucator.def_stats=30;
    jucator.drb_stats=30;
    jucator.att_stats=30;
    jucator.pret = 1;
    return is;
}

const std::optional<Echipa> &Jucator::getEchipa(){
    return echipa;
}

void Jucator::setEchipa(const std::optional<Echipa> &echipa1) {
    echipa = echipa1;
}

void Jucator::creeaza_jucator() {
    std::cin>>*this;
    std::cout<<"Felicitari! Arunca o privire peste profilul jucatorului tau!\n";
    std::cout<<*this;

}



void Jucator::alege_echipa(const vEchipe &v1, const Echipe_disponibile &v2) {
    std::cout<<"Apasa tasta corespunzatoare echipei dorite, pentru a semna contractul!\n";
    int optiune;
    std::cout<<"Vreau la echipa: ";
    do {
        try {
            std::cin >> optiune;
            if(optiune < 1 or optiune > int(v1.getVectorEchipe().size()) or !v2.getEchDisp().at(optiune - 1))
                throw (invalidID{"Input invalid! Alege o tasta care desemneaza una dintre echipele de mai sus!"});
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nVreau la echipa: ";
        }
    }while(optiune < 1 or optiune > int(v1.getVectorEchipe().size()) or !v2.getEchDisp().at(optiune - 1));
    this->echipa = v1.getVectorEchipe()[optiune];
    std::cout<<"\n";
    std::cout<<"FELICITARI!! Tocmai ai semnat un contract valabil pe un an cu "<< v1.getVectorEchipe()[optiune].getNume()<<"\n";

}

void Jucator::antrenament() {
    std::cout<<"Jucatorul a ajuns la antrenament! Ce tip de antrenament doriti?\n";
    std::cout<<"1. Suturi la poarta\n";
    std::cout<<"2. Pase si centrari\n";
    std::cout<<"3. Dribbling-uri\n";
    int alegere = 0;
    std::cout<<"Alegerea dumneavoastra  --->  ";
    std::cin>>alegere;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist6(-5,5);
    int rezultat = dist6(rng);
    if(rezultat < 0)
        std::cout<<"Din pacate, nu a fost cel mai bun antrenament, tocmai ai pierdut "<<rezultat<<" puncte. Incearca data viitoare!\n";
    else if(rezultat == 0)
        std::cout<<"Si cu bune, si cu rele, ai ajuns pe 0. Nicio diferenta astazi!";
    else
        std::cout<<"Bineee de tot astazi, ai evoluat cu "<<rezultat<<" puncte. Tine-o tot asa!";
    if(alegere == 1)
    {
        att_stats = att_stats + rezultat;
    }
    else if(alegere == 2)
    {
        def_stats = def_stats + rezultat;
    }
    else if(alegere == 3)
    {
        drb_stats = drb_stats + rezultat;
    }
}

void Jucator::consuma(Item& item){
    item.folosit_de(*this);
}

void Jucator::cumpara(Item& item, Inventar& inv){

    try {
            if (this->avere > item.getPret()) {
                std::cout << "\nAi achizitionat urmatorul produs: ";
                std::cout << item << "\n";
                std::cout << "\n-------------------------------------";
                std::cout << "\n1.Adauga-l la colectie";
                std::cout << "\n2.Consuma-l acum\n";
                this->avere -= item.getPret();
                std::cout << "\nAlegere: ";
                int tasta = 0;
                std::cin >> tasta;
                if (tasta == 1) {
                    std::cout << "\nProdusul a fost adaugat la colectie!\n";
                    inv.addItem(item.clone());
                    std::cout << "\n"<<inv;
                } else if (tasta == 2) {
                    std::cout<<"\nAi consumat produsul!\n";

                    this->consuma(item);
                } else {
                    throw (invalidInput{"Input invalid!!!"});
                }
            } else {
                throw (invalidPurchase("Nu ai suficienti bani."));
            }
        }
        catch (std::exception &err){
            std::cout<<err.what()<<"\n";
            rlutil::anykey();
            rlutil::cls();
        }
}
//
//int Jucator::getAvere() const {
//    return avere;
//}

int Jucator::getAttStats() const {
    return att_stats;
}

int Jucator::getDefStats() const {
    return def_stats;
}

int Jucator::getDrbStats() const {
    return drb_stats;
}

void Jucator::setAttStats(int attStats) {
    att_stats = attStats;
}

void Jucator::setDefStats(int defStats) {
    def_stats = defStats;
}

void Jucator::setDrbStats(int drbStats) {
    drb_stats = drbStats;
}
//
//void Jucator::setAvere(int avere_) {
//    avere = avere_;
//}

void Jucator::setFitness(int fitness_) {
    Jucator::fitness = fitness_;
}





