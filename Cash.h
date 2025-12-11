/*
    Enes Kılıç - 11.12.2025
*/

#include <iostream>
#include "Payment.h"        // Miras alacağı için Payment header dosyası dahil edildi.


class Cash: public Payment      // Payment class'ından public olarak miras alınıyor.
{
    public:
    void performPayment();
};