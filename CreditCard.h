/*
    Enes Kılıç - 11.12.2025
*/

#include <string>
#include "Payment.h"        // Miras alacağı için Payment header dosyası dahil edildi.

using namespace std;

class CreditCard: public Payment        // Payment class'ından public olarak miras alınıyor.
{
    private:
    long number;
    string type;
    string expDate;

    public:
    void performPayment();
    long getNumber();
    void setNumber(long n);
    string getType();
    void setType(string t);
    string getExpDate();
    void setExpDate(string e);
};
