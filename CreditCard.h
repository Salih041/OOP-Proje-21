#include <string>

using namespace std;

class CreditCard
{
    private:
    long number;
    string type;
    string expDate;

    public:
    void performPayment();
    long getNumber();
    void setNumber(long number);
    string getType();
    void setType(string type);
    string getExpDate();
    void setExpDate(string expDate);
};