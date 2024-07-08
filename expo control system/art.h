#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "expo.h"

class Art: public Expo{
    public:
        bool PopQuiz();
        void PriceList();
        int Purchase(int choice, int n);
        void CalculatePoint(int money_spent, int *classPointPointer);
        void checkPurchase(int total, int *classMoneyPointer, int *classPointPointer, int *tempIsVip);
        void Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip);
        void addMoney(int amount, int *classMoneyPointer){*classMoneyPointer+=amount;}
};