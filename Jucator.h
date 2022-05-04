//
// Created by Elias Stoica on 11-Apr-22.
//
#include <iostream>
#include <random>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "rlutil.h"
#ifndef OOP_JUCATOR_H
#define OOP_JUCATOR_H
#include "Echipa.h"
#include "vEchipe.h"
#include "Erori.h"

class Jucator {
    int id;
    std::string nume;
    std::string prenume;
    std::string nationalitate;
    int varsta;
    int att_stats;
    int def_stats;
    int drb_stats;
    int rating = (att_stats + def_stats + drb_stats)/3;
    std::string pozitie;
    std::optional <Echipa> echipa;
    int pret;
    int salariu;
    int avere;
public:

    Jucator():
    id(0), nume(""), prenume(""), nationalitate(""), varsta(16), att_stats(30), def_stats(30), drb_stats(30), rating(0), pozitie(""), echipa(
            std::make_optional<Echipa>()), pret(1), salariu(1), avere(1) {

    }
    Jucator(const int &id, const std::string &name, const std::string &prenume, const std::string &nationalitate , const int &varsta, const int &att_stats,const int &def_stats, const int &drb_stats,const std::string &pozitie, const Echipa &echipa,const  int &pret, const int &salariu, const int &avere):
            id(id), nume(name), prenume(prenume), nationalitate(nationalitate),  varsta(varsta), att_stats(att_stats), def_stats(def_stats), drb_stats(drb_stats),pozitie(pozitie), echipa(echipa), pret(pret), salariu(salariu), avere(avere)
    {

    }
    Jucator(Jucator const &j1):
            id(j1.id), nume(j1.nume), prenume(j1.prenume), nationalitate(j1.nationalitate), varsta(j1.varsta), att_stats(j1.att_stats), def_stats(j1.def_stats), drb_stats(j1.drb_stats), rating(j1.rating),pozitie(j1.pozitie), echipa(j1.echipa), pret(j1.pret), salariu(j1.salariu), avere(j1.avere)
    {

    }
    ~Jucator() {
        //destructor jucator
    }
    Jucator& operator=(const Jucator& j1){
        id = j1.id;
        nume = j1.nume;
        prenume = j1.prenume;
        nationalitate = j1.nationalitate;
        varsta = j1.varsta;
        att_stats = j1.att_stats;
        def_stats = j1.def_stats;
        drb_stats = j1.drb_stats;
        rating = j1.rating;
        pozitie = j1.pozitie;
        pret = j1.pret;
        salariu = j1.salariu;
        avere = j1.avere;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const Jucator &jucator) {
        os << "\nid: " << jucator.id << "\nnume: " << jucator.nume << " "<<jucator.prenume<<"\nnationalitate: " << jucator.nationalitate<<"\nvarsta: "<<jucator.varsta<<"\nattacking stats: "<<jucator.att_stats<<"\ndefending stats: "<<jucator.def_stats<<"\ndribbling stats: "<<jucator.drb_stats
           << " \nrating: " << jucator.rating << " \npozitie: " << jucator.pozitie << "\npret: "<<jucator.pret<<"\n";
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Jucator &jucator){
        std::cout<<"\nIntrodu ID-ul jucatorului: ";
        do {
            try {
                is >> jucator.id;
                if(jucator.id < 1 or jucator.id > 99)
                    throw (invalidID{"Input invalid! Alege un alt numar intre 1-99!"});
            }
            catch (std::exception &err) {
                std::cout << err.what() << '\n';
                rlutil::anykey();
                std::cout<<"\nIntrodu ID-ul jucatorului: ";
            }
        }while(jucator.id<1 or jucator.id>99);
        std::cout<<"\nIntrodu numele jucatorului: ";
        do {
            try {
                is >> jucator.nume;
                if(!containsOnlyLetters(jucator.nume))
                    throw (invalidID{"Input invalid! Alege un nume format doar din litere!"});
            }
            catch (std::exception &err) {
                std::cout << err.what() << '\n';
                rlutil::anykey();
                std::cout<<"\nIntrodu numele jucatorului: ";
            }
        }while(!containsOnlyLetters(jucator.nume));
        std::cout<<"\nIntrodu prenumele jucatorului: ";
        do {
            try {
                is >> jucator.prenume;
                if(!containsOnlyLetters(jucator.prenume))
                    throw (invalidID{"Input invalid! Alege un prenume format doar din litere!"});
            }
            catch (std::exception &err) {
                std::cout << err.what() << '\n';
                rlutil::anykey();
                std::cout<<"\nIntrodu prenumele jucatorului: ";
            }
        }while(!containsOnlyLetters(jucator.prenume));
        std::cout<<"\nIntrodu nationalitatea jucatorului: ";
        do {
            try {
                is >> jucator.nationalitate;
                if(!containsOnlyLetters(jucator.nationalitate))
                    throw (invalidID{"Input invalid! Alege o nationalitate formata doar din litere!"});
            }
            catch (std::exception &err) {
                std::cout << err.what() << '\n';
                rlutil::anykey();
                std::cout<<"\nIntrodu nationalitatea jucatorului: ";
            }
        }while(!containsOnlyLetters(jucator.nationalitate));
        jucator.varsta = 16;
        jucator.def_stats=30;
        jucator.drb_stats=30;
        jucator.att_stats=30;
        jucator.rating = (jucator.att_stats + jucator.drb_stats + jucator.def_stats) / 3;
        jucator.pozitie = "Mijlocas";
        jucator.pret = 1;
        return is;
    }

    const std::optional<Echipa> &getEchipa() const{
        return echipa;
    }

    void setEchipa(const std::optional<Echipa> &echipa1){
        echipa = echipa1;
    }

    static void creeaza_jucator(Jucator your_player){
        std::cin>>your_player;
        std::cout<<"Felicitari! Arunca o privire peste profilul jucatorului tau!\n";
        std::cout<<your_player;

    }
    static bool containsOnlyLetters(std::string const &str) {
        auto it = std::find_if(str.begin(), str.end(), [](char const &c) {
            return !std::isalpha(c);
        });
        return it == str.end();
    }
    void alege_echipa(const vEchipe& v1){
        std::cout<<"Apasa tasta corespunzatoare echipei dorite, pentru a semna contractul!\n";
        int optiune;
        std::cout<<"Vreau la echipa: ";
        std::cin>>optiune;
        this->echipa = v1.getVectorEchipe()[optiune];
        std::cout<<"\n";
        std::cout<<"FELICITARI!! Tocmai ai semnat un contract valabil pe un an cu "<< v1.getVectorEchipe()[optiune].getNume()<<"\n";

    }
    void antrenament(){
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
        if(alegere == 1)
        {
            if(rezultat < 0)
            {
                std::cout<<"Din pacate, nu a fost cel mai bun antrenament, tocmai ai pierdut "<<rezultat<<" puncte. Incearca data viitoare!\n";
                att_stats = att_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
            if(rezultat == 0)
            {
                std::cout<<"Si cu bune, si cu rele, ai ajuns pe 0. Nicio diferenta astazi!";
            }
            if(rezultat > 0)
            {
                std::cout<<"Bineee de tot astazi, ai evoluat cu "<<rezultat<<" puncte. Tine-o tot asa!";
                att_stats = att_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
        }
        else if(alegere == 2)
        {
            if(rezultat < 0)
            {
                std::cout<<"Din pacate, nu a fost cel mai bun antrenament, tocmai ai pierdut "<<rezultat<<" puncte. Incearca data viitoare!\n";
                def_stats = def_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
            if(rezultat == 0)
            {
                std::cout<<"Si cu bune, si cu rele, ai ajuns pe 0. Nicio diferenta astazi!";
            }
            if(rezultat > 0)
            {
                std::cout<<"Bineee de tot astazi, ai evoluat cu "<<rezultat<<" puncte. Tine-o tot asa!";
                def_stats = def_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
        }
        else if(alegere == 3)
        {
            if(rezultat < 0)
            {
                std::cout<<"Din pacate, nu a fost cel mai bun antrenament, tocmai ai pierdut "<<rezultat<<" puncte. Incearca data viitoare!\n";
                drb_stats = drb_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
            if(rezultat == 0)
            {
                std::cout<<"Si cu bune, si cu rele, ai ajuns pe 0. Nicio diferenta astazi!";
            }
            if(rezultat > 0)
            {
                std::cout<<"Bineee de tot astazi, ai evoluat cu "<<rezultat<<" puncte. Tine-o tot asa!";
                drb_stats = drb_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
        }
    }
    void schimbare_pozitie(const std::string &poz){
        this->pozitie = poz;
    }
};


#endif //OOP_JUCATOR_H
