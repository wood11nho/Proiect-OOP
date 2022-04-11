#include <iostream>
#include <random>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class Echipa;
class Meci;
vector<Echipa> Echipe;
vector<Meci> Meciuri;
class Echipa{
private:
    int id;
    int buget;
    int rating;
    string nume;
public:
    Echipa(int id, int buget, int rating, const string &nume) :
        id(id), buget(buget), rating(rating), nume(nume){

    }
    Echipa():
            id(0), buget(0), rating(0), nume(""){

    }

    virtual ~Echipa() {

    }

    const string &getNume() const {
        return nume;
    }

    int getId() const {
        return id;
    }

    int getRating() const {
        return rating;
    }

    friend ostream &operator<<(ostream &os, const Echipa &echipa) {
        os << "id: " << echipa.id << "\nbuget: "<<echipa.buget<<"\nnume: " << echipa.nume<<"\nrating: "<<echipa.rating;
        os<<"\n";
        os<<"Lotul Actual: ";

        return os;
    }
};
class Jucator{
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

    Jucator();
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

    const optional<Echipa> &getEchipa() const;

    void setEchipa(const optional<Echipa> &echipa);

    static void creeaza_jucator(Jucator your_player){
        cin>>your_player;
        cout<<"Felicitari! Arunca o privire peste profilul jucatorului tau!\n";
        cout<<your_player;

    }
    void alege_echipa(){
        cout<<"Apasa tasta corespunzatoare echipei dorite, pentru a semna contractul!\n";
        int optiune;
        cout<<"Vreau la echipa: ";
        cin>>optiune;
        this->echipa = Echipe[optiune];
        cout<<"\n";
        cout<<"FELICITARI!! Tocmai ai semnat un contract valabil pe un an cu "<< Echipe[optiune].getNume()<<"\n";

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
Jucator::Jucator() :
        id(0), nume(""), prenume(""), nationalitate(""), varsta(16), att_stats(30), def_stats(30), drb_stats(30), rating(0), pozitie(""), echipa(
        make_optional<Echipa>()), pret(1), salariu(1), avere(1) {

}

const optional<Echipa> &Jucator::getEchipa() const {
    return echipa;
}

void Jucator::setEchipa(const optional<Echipa> &echipa1) {
    Jucator::echipa = echipa1;

}

class Meci{
    Echipa& team1;
    Echipa& team2;
    std::pair<int, int> scor{0, 0};
    char rezultat;
public:
    Meci(Echipa &team1, Echipa &team2, const pair<int, int> &scor, char rezultat)
            : team1(team1), team2(team2), scor(scor), rezultat(rezultat) {}

    virtual ~Meci() {

    }

    friend ostream &operator<<(ostream &os, const Meci &meci) {
        os << "team1: " << meci.team1 << " team2: " << meci.team2 << " scor: " << meci.scor.first<<" - "<<meci.scor.second << " rezultat: "
           << meci.rezultat;
        return os;
    }
    Meci& operator=(const Meci& other){
        team1 = other.team1;
        team2 = other.team2;
        scor = other.scor;
        rezultat = other.rezultat;
        return *this;
    }
    void playmatch(){
        int rating1 = team1.getRating();
        int rating2 = team2.getRating();
        std::vector<int> sanse;
        sanse.push_back(35);
        sanse.push_back(30);
        sanse.push_back(35);
        int dif = rating1 - rating2;
        if(dif > 0){
            while(dif!=0)
            {
                sanse[0]+=3;
                sanse[1]-=2;
                sanse[2]-=1;
                dif-=1;
        }
        }
        else
        {
            while(dif!=0)
            {
                sanse[0]-=1;
                sanse[1]-=2;
                sanse[2]+=3;
                dif+=1;
            }
        }
        int ocazii1 = abs(sanse[0] - sanse[1]);
        int ocazii2 = abs(sanse[2] - sanse[1]);
        for(int i = 1; i<=ocazii1;i++)
            scor.first += (rand() % 2);
        for(int i = 1; i<=ocazii2;i++)
            scor.second += (rand() % 2);
        system("cls");
        cout<<"Meciul s-a terminat!\n";
        cout<<"REZULTAT FINAL: \n";
        cout<<team1.getNume()<<" "<<scor.first<<" - "<<team2.getNume()<<" "<<scor.second;
    }

};
class Transfer{
protected:
    Echipa& e1;
    Echipa& e2;
    Jucator& j;
public:
    Transfer(Echipa &e1, Echipa &e2, Jucator &j) : e1(e1), e2(e2), j(j) {}
    Transfer(const Transfer& other):
    e1(other.e1), e2(other.e2), j(other.j)
    {}
    Transfer& operator=(const Transfer& other){
        e1 = other.e1;
        e2 = other.e2;
        j = other.j;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Transfer &transfer) {
        os << "De la echipa: " << transfer.e1 << " la echipa: " << transfer.e2 << " se transfera jucatorul: " << transfer.j;
        return os;
    }

    virtual ~Transfer() {

    }
    void Transferare(){
        this->j.setEchipa(e2);
    }
};
class Imprumut:public Transfer{
    int durata;
public:
    Imprumut(Echipa &e1, Echipa &e2, Jucator &j, int durata) : Transfer(e1, e2, j), durata(durata) {}
    void Imprumutare(int durata_imprumut){
        this->j.setEchipa(e2);
        this->durata = durata_imprumut;
    }
};
int main() {
    Echipa empty_team(0, 0, 0, "");
    Jucator empty_jucator(0,"","","",16,30,30,30,"",empty_team,1, 1, 1);
    Echipa e1(1,50, 64,"Dinamo Bucuresti");
    Echipa e2(2, 150, 69, "Steaua Bucuresti");
    Echipa e3(3, 75, 64, "Rapid Bucuresti");
    Echipa e4(4, 125, 69, "CFR Cluj");
    Echipa e5(5, 100, 65, "Farul Constanta");
    Echipa e6(6, 125, 68, "Universitatea Craiova");
    Echipe.push_back(empty_team);
    Echipe.push_back(e1);
    Echipe.push_back(e2);
    Echipe.push_back(e3);
    Echipe.push_back(e4);
    Echipe.push_back(e5);
    Echipe.push_back(e6);
    cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
    cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';
    int tasta = 0;
    cin>>tasta;
    Jucator your_player;
    if(tasta == 1)
        Jucator::creeaza_jucator(your_player);
    else return 0;
    cout<<"Totul este pregatit! Hai sa incepem\n";
    cout<<"--------------------------------------------------\n";
    cout<<"1.  Alege echipa\n";
    cout<<"0.  Inchide jocul\n";
    cin>>tasta;
    if (tasta == 1) {
        bool v[7];
        srand ( (unsigned int)time(nullptr) );
        for (int i = 1; i <= 6; i++) {
            if (rand()%2 == 1)
                v[i] = true;
            else v[i] = false;
        }
        cout << "Urmatoarele echipe sunt disponibile: \n";
        for (int i = 1; i <= 6; i++) {
            if (v[i]) {
                cout << Echipe[i].getId() << ". " << Echipe[i].getNume() << "\n";
            }
        }
        your_player.alege_echipa();
    }
    else
        return 0;
    cout<<"Totul este pregatit! Hai sa organizam niste meciuri de pregatire inainte de sezonul regulat!\n";
    cout<<"1. Joaca meci\n";
    cout<<"0. Inchide jocul.\n";
    cin>>tasta;
    if(tasta!=0) {
        int ok = 0;
        while (tasta != 0)
        {
            system("cls");
            cout<<"Etapa "<<ok<<"\n";
            int i = rand() % 6 + 1;
            while(i==your_player.getEchipa()->getId())
                i = rand() % 6 + 1;
            cout<<"Urmeaza meciul impotriva celor de la "<<Echipe[i].getNume()<<"\n";
            cout<<"1. Incepe meciul\n";
            cout<<"2. Vizualizeaza echipa\n";
            cin>>tasta;
            if(tasta == 1) {
                char rezultat = 'X';
                Meciuri.push_back(Meci((Echipa &) your_player.getEchipa(), Echipe[i], {0, 0}, rezultat));
                Meciuri.back().playmatch();
                cout<<"\n";
                cout<<" ------------------------------------------------ \n";
                cout<<"1. Continua\n";
                cout<<"2. Vezi Statistici\n";
                cin>>tasta;
            }
            else
                return 0;
        }

    }
    else {
        cout<<"Va asteptam data urmatoare sa continuam joaca!";
    }
    Jucator j3;
    cin>>j3;
    Jucator j1(1,"Stoica","Elias","Romania",19,70,45,50,"Atacant",e1,15, 10, 25);
    cout<<j1;
    j1.schimbare_pozitie("Mijlocas");
    j1.antrenament();

    return 0;
}