//
// Created by Elias Stoica on 11-Apr-22.
//

#include <iostream>
#include <random>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
#ifndef OOP_TRANSFER_H
#define OOP_TRANSFER_H
#include "Echipa.h"
#include "Jucator.h"

class Transfer {

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

    friend std::ostream &operator<<(std::ostream &os, const Transfer &transfer) {
        os << "De la echipa: " << transfer.e1 << " la echipa: " << transfer.e2 << " se transfera jucatorul: " << transfer.j;
        return os;
    }

    virtual ~Transfer() {

    }
    void Transferare(){
        this->j.setEchipa(e2);
    }
};


#endif //OOP_TRANSFER_H
