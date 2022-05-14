//
// Created by Elias Stoica on 08-May-22.
//

#ifndef OOP_ADIDAS_H
#define OOP_ADIDAS_H

#include <memory>
#include <ostream>
#include "Items.h"

class Adidas:public Items {
    int att_upgrade;
    int def_upgrade;
    int drb_upgrade;
public:
    Adidas(int pret, const std::string &nume, int attUpgrade, int defUpgrade, int drbUpgrade);

    virtual ~Adidas();

    std::shared_ptr<Items> clone() const override;

    void afisare(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, const Adidas &adidas);
    Adidas& operator=(const Adidas& a1);

    void consuma_item(Jucator& j) override;

    void cumpara_item(Jucator& j) override;

    int getAttUpgrade() const;

    int getDefUpgrade() const;

    int getDrbUpgrade() const;
};


#endif //OOP_ADIDAS_H
