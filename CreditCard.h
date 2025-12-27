/*
    Enes Kılıç - 11.12.2025
*/

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <string>
#include "Payment.h" // Miras alacağı için Payment header dosyası dahil edildi.

using namespace std;

class CreditCard : public Payment // Payment class'ından public olarak miras alınıyor.
{
private:
    long number;
    string type;
    string expDate;

public:
    CreditCard(double amount, long number, const string& type, const string &expDate);

    void performPayment() override;

    long getNumber() const;
    void setNumber(long n);

    string getType() const;
    void setType(const string& t);
    
    string getExpDate() const;
    void setExpDate(const string& e);
};

#endif