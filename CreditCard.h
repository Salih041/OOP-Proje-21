#include <string>
#include "Payment.h"

using namespace std;

class CreditCard: public Payment
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
