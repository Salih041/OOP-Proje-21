/*
    Enes Kılıç - 11.12.2025
*/

#ifndef CHECK_H
#define CHECK_H

#include <string>
#include "Payment.h"        // Miras alacağı için Payment header dosyası dahil edildi.

using namespace std;

class Check: public Payment     // Payment class'ından public olarak miras alınıyor.
{
    private:
    string name;
    string bankID;

    public:
    Check(double amount, const string& name, const string& bankID);

    void performPayment() override;

    string getName() const;
    void setName(const string& n);

    string getBankID() const;
    void setBankID(const string& b);
};

#endif