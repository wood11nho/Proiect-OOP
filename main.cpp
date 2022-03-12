#include <iostream>
#include <vector>
#include <random>
using namespace std;
class Stadion;
class Echipa;
class Jucator{
    int id;
    string nume;
    string prenume;
    string nationalitate;
    int att_stats;
    int def_stats;
    int drb_stats;
    int rating = (att_stats + def_stats + drb_stats)/3;
    string pozitie;
    Echipa &echipa;
    int pret;
public:
    Jucator() :
            id(0), nume(""), prenume(""), nationalitate(""), att_stats(0), def_stats(0), drb_stats(0), rating(0), pozitie(""), echipa(echipa), pret(0) {

    }
    Jucator(const int id, const string name, const string prenume, string nationalitate , int att_stats, int def_stats, int drb_stats, string pozitie,  Echipa &echipa, int pret):
            id(id), nume(name), prenume(prenume), nationalitate(nationalitate),  att_stats(att_stats), def_stats(def_stats), drb_stats(drb_stats),pozitie(pozitie), echipa(echipa), pret(pret)
    {

    }
    Jucator(Jucator const &j1):
            id(j1.id), nume(j1.nume), prenume(j1.prenume), nationalitate(j1.nationalitate), att_stats(j1.att_stats), def_stats(j1.def_stats), drb_stats(j1.drb_stats), rating(j1.rating),pozitie(j1.pozitie), echipa(j1.echipa), pret(j1.pret)
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
        att_stats = j1.att_stats;
        def_stats = j1.def_stats;
        drb_stats = j1.drb_stats;
        rating = j1.rating;
        pozitie = j1.pozitie;
        pret = j1.pret;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Jucator &jucator) {
        os << "\nid: " << jucator.id << "\nnume: " << jucator.nume << " "<<jucator.prenume<<"\nnationalitate: " << jucator.nationalitate<<"\n attacking stats: "<<jucator.att_stats<<"\ndefending stats: "<<jucator.def_stats<<"\ndribbling stats: "<<jucator.drb_stats
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
        cout<<"\nIntrodu rating de atacant pentru jucator: ";
        is >> jucator.att_stats;
        cout<<"\nIntrodu rating de fundas pentru jucator: ";
        is >> jucator.def_stats;
        cout<<"\nIntrodu rating pentru dribbling jucatorului: ";
        is >> jucator.drb_stats;
        jucator.rating = (jucator.att_stats + jucator.drb_stats + jucator.def_stats) / 3;
        cout<<"\nIntrodu pozitia jucatorului: ";
        is >> jucator.pozitie;
        cout<<"\nIntrodu pretul jucatorului: ";
        is >> jucator.pret;
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
        std::uniform_int_distribution<std::mt19937::result_type> dist6(-5,5);
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
    void schimbare_pozitie(string poz){
        this->pozitie = poz;
    }


};
class Stadion{
private:
    int id;
    int capacitate;
    int an_const;
    string Nume;
    string Locatie;
    bool pista;
    bool nocturna;
public:

    Stadion(const int id, int capacitate, int an_const, const string &nume, const string &locatie, bool pista, bool nocturna):
            id(id), capacitate(capacitate), an_const(an_const), Nume(nume), Locatie(locatie), pista(pista), nocturna(nocturna)
    {

    }
    virtual ~Stadion() {

    }

    friend ostream &operator<<(ostream &os, const Stadion &stadion) {
        os<<"\nid: "<<stadion.id << "\ncapacitate: " << stadion.capacitate << "\nan_const: " << stadion.an_const << "\nNume: " << stadion.Nume
           << "\nLocatie: " << stadion.Locatie << "\npista: " << stadion.pista << "\nnocturna: " << stadion.nocturna<<"\n";
        return os;
    }
    void modernizare_stadion(){
        if(!nocturna)
            nocturna = true;
        if(pista)
            pista=false;
        capacitate = capacitate + 5000;
        an_const = 2022;
    }
};
class Echipa{
private:
    int id;
    int buget;
    string nume;
    Stadion stadium;
public:
    Echipa(int id, int buget, const string &nume, const Stadion &stadium) :
        id(id), buget(buget), nume(nume), stadium(stadium){

    }
    Echipa():
            id(0), buget(0), nume(""), stadium(0, 0, 0, "", "", false, false){

    }

    virtual ~Echipa() {

    }

    friend ostream &operator<<(ostream &os, const Echipa &echipa) {
        os << "id: " << echipa.id << "buget: "<<echipa.buget<<" nume: " << echipa.nume << " stadium: "<< echipa.stadium;
        os<<"\n";
        os<<"Lotul Actual: ";

        return os;
    }
};

int main() {
    Stadion s1(1, 55000, 2012, "Arena Nationala", "Bucuresti", false, true);
    Echipa empty_team(0, 0, "", {0, 0, 0, "", "", false, false});
    Jucator empty_jucator(0,"","","",0,0,0,"",empty_team,0);
    Echipa e1(1,100, "Elik Red Dogs", s1);
    Jucator j1(1,"Stoica","Elias","Romania",70,45,25,"Atacant",e1,15);
    cout<<j1;
    Jucator j2(j1);
    cout<<j2;
    Jucator j3;
    j3 = j1;
    cout<<j3;
    Jucator j4;
    cout<<"\n\n\n\n\n\n\n";
    //cin>>j4;
    //cout<<j4;
    j1.antrenament();
    cout<<j1;
    j1.antrenament();
    cout<<j1;
    j1.schimbare_pozitie("Mijlocas");
    cout<<j1;
    s1.modernizare_stadion();
    cout<<s1;
    return 0;
}