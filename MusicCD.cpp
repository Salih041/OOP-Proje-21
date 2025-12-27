/*
    Emre Karaaydın 21.12.25
*/

#include "MusicCD.h"
// üye baslatici liste ile base classa erişim
MusicCD::MusicCD(std::string name_inp, double price_inp,std::string singer_inp, std::string type_inp)
    : Product(name_inp, price_inp), singer(singer_inp), type(type_inp) {}

void MusicCD::printProperties() const {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "ID        : " << getID() << endl;
    std::cout << "Name      : " << getName() << std::endl;
    std::cout << "Price     : " << getPrice() << " TL" << std::endl;
    std::cout << "Singer    : " << singer << std::endl;
    std::cout << "Type      : " << type << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

const std::string& MusicCD::getSinger() const {
    return singer;
}

void MusicCD::setSinger(const std::string& singer_inp) {
    singer = singer_inp;
}

const std::string& MusicCD::getType() const {
    return type;
}

void MusicCD::setType(const std::string& type_inp) {
    type = type_inp;
}