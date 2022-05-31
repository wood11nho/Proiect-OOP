//
// Created by Elias Stoica on 30-May-22.
//

#ifndef OOP_CLASAMENT_H
#define OOP_CLASAMENT_H


#include <ostream>
#include <map>
#include "Echipa.h"
#include "vEchipe.h"


class Clasament {
private:
    std::vector<std::pair<Echipa,int>> punctaj;
    Echipa campioana;
    Clasament() = default;
public:
    Clasament(const Clasament&) = delete;

    Clasament& operator=(const Clasament&) = delete;

    static Clasament& get_clasament();

    void setPunctaj(const Echipa &e1, int nr_puncte);

    friend std::ostream &operator<<(std::ostream &os, const Clasament &clasament) {
        clasament.get_clasament().sortare();
        return os;
    }

    void creare_clasament(const vEchipe &v1);

    void afisare_campioana(){
        std::cout<<"\nFELICITARI ECHIPEI "<<campioana.getNume()<<" PENTRU CASTIGAREA CAMPIONATULUI!!!\n";
    }

    void setCampioana(const Echipa &campioana_);

    void sortare()
    {
        // Declare a multimap
        std::multimap<int, Echipa, std::greater<int>> MM;

        // Insert every (key-value) pairs from
        // map M to multimap MM as (value-key)
        // pairs
        for (auto& it : Clasament::get_clasament().punctaj) {
            MM.insert({ it.second, it.first });
        }

        auto camp = MM.begin();
        setCampioana(camp->second);
        // Print the multimap
        int ok = 0;
        for (auto& it : MM) {
            if(!it.second.getNume().empty()) {
                ok++;
                std::cout <<ok<<". " << it.second.getNume() << ' ' << it.first << "\n";
            }
        }
    }
};


#endif //OOP_CLASAMENT_H
