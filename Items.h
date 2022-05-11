//
// Created by Elias Stoica on 08-May-22.
//

#ifndef OOP_ITEMS_H
#define OOP_ITEMS_H
#include <string>
#include <ostream>

class Items {
protected:
    int pret;
    std::string nume;
public:
    Items(int pret, const std::string &nume);

    Items(const Items& other);
    virtual ~Items();

    friend std::ostream &operator<<(std::ostream &os, const Items &items);

    Items& operator=(const Items& other);


};


#endif //OOP_ITEMS_H
