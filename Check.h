/*
    Enes Kılıç - 11.12.2025
*/

#include <string>
#include "Payment.h"        // Miras alacağı için Payment header dosyası dahil edildi.

using namespace std;

class Check: public Payment     // Payment class'ından public olarak miras alınıyor.
{
    private:
    string name;
    string bankID;

    public:
    void performPayment();
    string getName();
    void setName(string n);
    string getBankID();
    void setBankID(string b);
};