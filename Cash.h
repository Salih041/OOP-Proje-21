#include <iostream>
#include "Payment.h"


class Cash: public Payment
{
    public:
    void performPayment();
};