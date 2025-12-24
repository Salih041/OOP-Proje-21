/*
    Emre Karaaydın 21.12.25
*/


#ifndef MUSICCD_H
#define MUSICCD_H

#include "Product.h"

class MusicCD : public Product {
private:
    std::string singer;
    std::string type;

public:
    MusicCD(string name_inp, double price_inp, string singer_inp, string type_inp);

    void printProperties() const override; //get fonksiyonları const tanımlandı. base classtaki virtual metodu override edildi
    const std::string &getSinger() const;  //bellek maliyetinden kaçınmak için referans ile iletildi
    const std::string &getType() const;    //bellek maliyetinden kaçınmak için referans ile iletildi

    void setSinger(const std::string& singer_inp); //set fonksiyonları. bellek maliyetinden kaçınmak için referans ile iletildi
    void setType(const std::string& type_inp);
};

#endif