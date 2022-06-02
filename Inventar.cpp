////
//// Created by Elias Stoica on 15-May-22.
////
//
//#include "Inventar.h"
//
//Inventar::Inventar(const std::vector<std::shared_ptr<Item>> &colectie) : Colectie(colectie) {}
//
////std::ostream &operator<<(std::ostream &os, const Inventar &inventar) {
////    os << "\n-------------------------------------\n";
////    int contor = 1;
////    for(const std::shared_ptr<Item>& i: inventar.Colectie){
////        os<<contor<<".";
////        os<< *i<<'\n';
////        contor++;
////
////    }
////    return os;
////}
//
////void Inventar::addItem(std::shared_ptr<Item> pulledItem) {
////    this->Colectie.push_back(pulledItem);
////}
//
////const std::vector<std::shared_ptr<Item>> &Inventar::getColectie() const {
////    return Colectie;
////}
