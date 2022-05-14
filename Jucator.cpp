//
// Created by Elias Stoica on 11-Apr-22.
//

#include "Jucator.h"
#include "Energizant.h"
#include "Adidas.h"

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

std::ostream &operator<<(ostream &os, const Jucator &jucator) {
    os << "\nid: " << jucator.id << "\nnume: " << jucator.nume << " "<<jucator.prenume<<"\nnationalitate: " << jucator.nationalitate<<"\nvarsta: "<<jucator.varsta<<"\nattacking stats: "<<jucator.att_stats<<"\ndefending stats: "<<jucator.def_stats<<"\ndribbling stats: "<<jucator.drb_stats
       << " \nrating: " << jucator.rating() << "\npret: "<<jucator.pret<<"\nsalariu: "<<jucator.salariu<<"\navere: "<<jucator.avere<<"\nfitness: "<<jucator.fitness<<"\n";
    return os;
}

bool Jucator::containsOnlyLetters(const string &str) {
    auto it = std::find_if(str.begin(), str.end(), [](char const &c) {
        return !std::isalpha(c);
    });
    return it == str.end();
}

std::istream &operator>>(istream &is, Jucator &jucator) {
    std::cout<<"\nIntrodu numarul jucatorului: ";
    do {
        try {
            is >> jucator.id;
            if(jucator.id < 1 or jucator.id > 99)
                throw (invalidID{"Input invalid! Alege un alt numar intre 1-99!"});
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nIntrodu numarul jucatorului: ";
        }
    }while(jucator.id<1 or jucator.id>99);
    std::cout<<"\nIntrodu numele jucatorului: ";
    do {
        try {
            is >> jucator.nume;
            if(!Jucator::containsOnlyLetters(jucator.nume))
                throw (invalidID{"Input invalid! Alege un nume format doar din litere!"});
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nIntrodu numele jucatorului: ";
        }
    }while(!Jucator::containsOnlyLetters(jucator.nume));
    std::cout<<"\nIntrodu prenumele jucatorului: ";
    do {
        try {
            is >> jucator.prenume;
            if(!Jucator::containsOnlyLetters(jucator.prenume))
                throw (invalidID{"Input invalid! Alege un prenume format doar din litere!"});
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nIntrodu prenumele jucatorului: ";
        }
    }while(!Jucator::containsOnlyLetters(jucator.prenume));
    std::cout<<"\nIntrodu nationalitatea jucatorului: ";
    do {
        try {
            is >> jucator.nationalitate;
            if(!Jucator::containsOnlyLetters(jucator.nationalitate))
                throw (invalidID{"Input invalid! Alege o nationalitate formata doar din litere!"});
        }
        catch (std::exception &err) {
            std::cout << err.what() << '\n';
            rlutil::anykey();
            std::cout<<"\nIntrodu nationalitatea jucatorului: ";
        }
    }while(!Jucator::containsOnlyLetters(jucator.nationalitate));
    jucator.varsta = 16;
    jucator.def_stats=30;
    jucator.drb_stats=30;
    jucator.att_stats=30;
    jucator.pret = 1;
    return is;
}

const std::optional<Echipa> &Jucator::getEchipa() const {
    return echipa;
}

void Jucator::setEchipa(const optional<Echipa> &echipa1) {
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

void Jucator::upgrade_stats_energizant(const Energizant &e) {
    this->att_stats += e.getSkillBoost();
    this->drb_stats += e.getSkillBoost();
    this->def_stats += e.getSkillBoost();
    this->fitness = e.getFitnessBoost();
}

void Jucator::upgrade_stats_adidas(const Adidas &a) {
    this->att_stats += a.getAttUpgrade();
    this->drb_stats += a.getDrbUpgrade();
    this->def_stats += a.getDefUpgrade();
}





