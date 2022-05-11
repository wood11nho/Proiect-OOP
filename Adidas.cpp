//
// Created by Elias Stoica on 08-May-22.
//

#include "Adidas.h"


Adidas::Adidas(int pret, const std::string &nume, int attUpgrade, int defUpgrade, int drbUpgrade) : Items(pret, nume),
                                                                                                    att_upgrade(
                                                                                                            attUpgrade),
                                                                                                    def_upgrade(
                                                                                                            defUpgrade),
                                                                                                    drb_upgrade(
                                                                                                            drbUpgrade) {}
