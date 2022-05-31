//
// Created by Elias Stoica on 31-May-22.
//

#ifndef OOP_ENERGIZANT_FACTORY_H
#define OOP_ENERGIZANT_FACTORY_H

#include "Energizant.h"

class Energizant_factory {
public:
    static Energizant energ_skill();
    static Energizant energ_fitness();
    static Energizant energ_full();
};


#endif //OOP_ENERGIZANT_FACTORY_H
