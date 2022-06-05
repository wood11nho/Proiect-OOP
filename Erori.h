//
// Created by Elias Stoica on 03-May-22.
//

#ifndef OOP_ERORI_H
#define OOP_ERORI_H

#include <stdexcept>

class invalidInput:public std::runtime_error {
public:
    explicit invalidInput(const std::string& arg);
};
class invalidID:public invalidInput{
public:
    explicit invalidID(const std::string& arg);
};
class invalidPurchase:public invalidInput{
public:
    explicit invalidPurchase(const std::string& arg);
};
class invalidStat:public invalidInput{
public:
    explicit invalidStat(const std::string& arg);
};
class invalidBuget:public invalidInput{
public:
    explicit invalidBuget(const std::string& arg);
};
class invalidName:public invalidInput{
public:
    explicit invalidName(const std::string& arg);
};


#endif //OOP_ERORI_H
