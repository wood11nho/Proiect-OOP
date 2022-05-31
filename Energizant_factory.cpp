//
// Created by Elias Stoica on 31-May-22.
//

#include "Energizant_factory.h"


Energizant Energizant_factory::energ_fitness() {return Energizant(0,"Energizant Fitness",100,0);}
Energizant Energizant_factory::energ_full() {return Energizant(0, "Energizant Complet", 100, 10);}
Energizant Energizant_factory::energ_skill() {return Energizant(0, "Energizant Skill", 0, 10);}