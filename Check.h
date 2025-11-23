#include <string>

using namespace std;

class Check
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