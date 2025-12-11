#include <string>
#include "Payment.h"

using namespace std;

class Check: public Payment
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