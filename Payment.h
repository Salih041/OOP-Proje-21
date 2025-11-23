#include <string>
using namespace std;

class Payment
{
    private:
    double amount;

    public:
    double getAmount();
    void setAmount(double amount);
    void performPayment();
};