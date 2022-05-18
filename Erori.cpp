//
// Created by Elias Stoica on 03-May-22.
//

#include "Erori.h"


invalidInput::invalidInput(const std::string &arg) : std::runtime_error{arg} {}
invalidID::invalidID(const std::string &arg) : invalidInput{arg} {}
invalidPurchase::invalidPurchase(const std::string &arg) : invalidInput{arg} {}
invalidStat::invalidStat(const std::string &arg) :invalidInput{arg}{}
