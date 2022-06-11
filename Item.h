//
// Created by Elias Stoica on 08-May-22.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H
#include <string>
#include <ostream>
#include <memory>
class Jucator;

class Item {
protected:
    int pret;
    std::string nume;

    virtual void afisare(std::ostream &os) const = 0;

public:

    virtual void folosit_de(Jucator& j) = 0;

    Item(int pret, const std::string &nume);

    Item(const Item& other);
    virtual ~Item();

    friend std::ostream &operator<<(std::ostream &os, const Item &items);

    Item& operator=(const Item& other);

    virtual std::shared_ptr<Item> clone() const = 0;

    int getPret() const;

    bool operator<(const Item &rhs) const;

    bool operator>(const Item &rhs) const;

    bool operator<=(const Item &rhs) const;

    bool operator>=(const Item &rhs) const;
};


#endif //OOP_ITEM_H
