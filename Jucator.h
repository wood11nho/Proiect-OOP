//
// Created by Elias Stoica on 11-Apr-22.
//
#include <iostream>
#include <random>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
#ifndef OOP_JUCATOR_H
#define OOP_JUCATOR_H
#include "Echipa.h"
#include "vEchipe.h"

class Jucator {
    int id;
    string nume;
    string prenume;
    string nationalitate;
    int varsta;
    int att_stats;
    int def_stats;
    int drb_stats;
    int rating = (att_stats + def_stats + drb_stats)/3;
    string pozitie;
    optional <Echipa> echipa;
    int pret;
    int salariu;
    int avere;
public:

    Jucator():
    id(0), nume(""), prenume(""), nationalitate(""), varsta(16), att_stats(30), def_stats(30), drb_stats(30), rating(0), pozitie(""), echipa(
            make_optional<Echipa>()), pret(1), salariu(1), avere(1) {

    }
    Jucator(const int &id, const string &name, const string &prenume, const string &nationalitate , const int &varsta, const int &att_stats,const int &def_stats, const int &drb_stats,const string &pozitie, const Echipa &echipa,const  int &pret, const int &salariu, const int &avere):
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
    friend ostream &operator<<(ostream &os, const Jucator &jucator) {
        os << "\nid: " << jucator.id << "\nnume: " << jucator.nume << " "<<jucator.prenume<<"\nnationalitate: " << jucator.nationalitate<<"\nvarsta: "<<jucator.varsta<<"\nattacking stats: "<<jucator.att_stats<<"\ndefending stats: "<<jucator.def_stats<<"\ndribbling stats: "<<jucator.drb_stats
           << " \nrating: " << jucator.rating << " \npozitie: " << jucator.pozitie << "\npret: "<<jucator.pret<<"\n";
        return os;
    }
    friend istream &operator>>(istream &is, Jucator &jucator){
        cout<<"\nIntrodu ID-ul jucatorului: ";
        is >> jucator.id;
        cout<<"\nIntrodu numele jucatorului: ";
        is >> jucator.nume;
        cout<<"\nIntrodu prenumele jucatorului: ";
        is >> jucator.prenume;
        cout<<"\nIntrodu nationalitatea jucatorului: ";
        is >> jucator.nationalitate;
        jucator.varsta = 16;
        jucator.def_stats=30;
        jucator.drb_stats=30;
        jucator.att_stats=30;
        jucator.rating = (jucator.att_stats + jucator.drb_stats + jucator.def_stats) / 3;
        jucator.pozitie = "Mijlocas";
        jucator.pret = 1;
        return is;
    }

    const optional<Echipa> &getEchipa() const{
        return echipa;
    }

    void setEchipa(const optional<Echipa> &echipa1){
        echipa = echipa1;
    }

    static void creeaza_jucator(Jucator your_player){
        cin>>your_player;
        cout<<"Felicitari! Arunca o privire peste profilul jucatorului tau!\n";
        cout<<your_player;

    }
    void alege_echipa(vEchipe& v1){
        cout<<"Apasa tasta corespunzatoare echipei dorite, pentru a semna contractul!\n";
        int optiune;
        cout<<"Vreau la echipa: ";
        cin>>optiune;
        this->echipa = v1.getVectorEchipe()[optiune];
        cout<<"\n";
        cout<<"FELICITARI!! Tocmai ai semnat un contract valabil pe un an cu "<< v1.getVectorEchipe()[optiune].getNume()<<"\n";

    }
    void antrenament(){
        cout<<"Jucatorul a ajuns la antrenament! Ce tip de antrenament doriti?\n";
        cout<<"1. Suturi la poarta\n";
        cout<<"2. Pase si centrari\n";
        cout<<"3. Dribbling-uri\n";
        int alegere = 0;
        cout<<"Alegerea dumneavoastra  --->  ";
        cin>>alegere;
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<int> dist6(-5,5);
        int rezultat = dist6(rng);
        if(alegere == 1)
        {
            if(rezultat < 0)
            {
                cout<<"Din pacate, nu a fost cel mai bun antrenament, tocmai ai pierdut "<<rezultat<<" puncte. Incearca data viitoare!\n";
                att_stats = att_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
            if(rezultat == 0)
            {
                cout<<"Si cu bune, si cu rele, ai ajuns pe 0. Nicio diferenta astazi!";
            }
            if(rezultat > 0)
            {
                cout<<"Bineee de tot astazi, ai evoluat cu "<<rezultat<<" puncte. Tine-o tot asa!";
                att_stats = att_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
        }
        else if(alegere == 2)
        {
            if(rezultat < 0)
            {
                cout<<"Din pacate, nu a fost cel mai bun antrenament, tocmai ai pierdut "<<rezultat<<" puncte. Incearca data viitoare!\n";
                def_stats = def_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
            if(rezultat == 0)
            {
                cout<<"Si cu bune, si cu rele, ai ajuns pe 0. Nicio diferenta astazi!";
            }
            if(rezultat > 0)
            {
                cout<<"Bineee de tot astazi, ai evoluat cu "<<rezultat<<" puncte. Tine-o tot asa!";
                def_stats = def_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
        }
        else if(alegere == 3)
        {
            if(rezultat < 0)
            {
                cout<<"Din pacate, nu a fost cel mai bun antrenament, tocmai ai pierdut "<<rezultat<<" puncte. Incearca data viitoare!\n";
                drb_stats = drb_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
            if(rezultat == 0)
            {
                cout<<"Si cu bune, si cu rele, ai ajuns pe 0. Nicio diferenta astazi!";
            }
            if(rezultat > 0)
            {
                cout<<"Bineee de tot astazi, ai evoluat cu "<<rezultat<<" puncte. Tine-o tot asa!";
                drb_stats = drb_stats + rezultat;
                rating = (att_stats + def_stats + drb_stats) / 3;
            }
        }
    }
    void schimbare_pozitie(const string &poz){
        this->pozitie = poz;
    }
};


#endif //OOP_JUCATOR_H
