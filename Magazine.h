#ifndef _MAGAZINE_H_
#define _MAGAZINE_H_
#include "Product.h"
class  Magazine : public Product {

private:
int issue;
std::string type;

public:
Magazine(std::string name_inp, double price_inp, int issue_inp, std::string type_inp);

void printProperties() const override;
int getIssue() const;               // Get fonksiyonları const tanımlandı. properties base class üzerinden override edildi
const std::string& getType() const; // bellek maliyetinden kaçınmak için referans ile iletildi

void setIssue(int issue_inp);       // Set fonksiyonları
void setType(const std::string &type_inp); // bellek maliyetinden kaçınmak için referans ile iletildi

};
#endif

