//
// Created by Elias Stoica on 05-May-22.
//

#ifndef OOP_ECHIPE_DISPONIBILE_H
#define OOP_ECHIPE_DISPONIBILE_H
#include <vector>
using namespace std;

class Echipe_disponibile {

    vector<bool> EchDisp;
public:
    Echipe_disponibile(const vector<bool> &echDisp);
    virtual ~Echipe_disponibile() {

    }
    void este_valabila(bool ok);

    [[nodiscard]] const vector<bool> &getEchDisp() const;

    void setEchDisp(const vector<bool> &echDisp);
};


#endif //OOP_ECHIPE_DISPONIBILE_H
