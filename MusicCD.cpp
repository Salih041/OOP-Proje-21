#include "MusicCD.h"
// üye baslatici liste ile base classa erişim
MusicCD::MusicCD(std::string name_inp, double price_inp,std::string singer_inp, std::string type_inp)
    : Product(name_inp, price_inp), singer(singer_inp), type(type_inp) {}
  // protected üyelere doğrudan erişim
void MusicCD::printProperties() const {
    cout << "ID: " << ID << " Name: " << name << " Price: " << price 
         << " Singer: " << singer << " Type: " << type << endl;
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