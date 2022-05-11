//
// Created by Elias Stoica on 08-May-22.
//

#ifndef OOP_ADIDAS_H
#define OOP_ADIDAS_H

#include "Items.h"

class Adidas:public Items {
    int att_upgrade;
    int def_upgrade;
    int drb_upgrade;
public:
    Adidas(int pret, const std::string &nume, int attUpgrade, int defUpgrade, int drbUpgrade);
};


#endif //OOP_ADIDAS_H
