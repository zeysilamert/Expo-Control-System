#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "expo.h"

using namespace std;

class Book: public Expo{
    public:
        bool PopQuiz();
        void PriceList();
        void CalculatePoint(int money_spent, int *classPointPointer);
        void checkPurchase(int total, int *classMoneyPointer, int *classPointPointer, int *tempIsVip);
        int Purchase(int choice, int n);
        void Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip);
        void addMoney(int amount, int *classMoneyPointer){*classMoneyPointer+=amount;}
};