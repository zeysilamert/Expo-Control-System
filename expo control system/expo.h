#pragma once 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Expo {
    protected:
        virtual bool PopQuiz()=0;
        virtual void PriceList()=0;
        virtual void CalculatePoint(int money_spent, int *classPointPointer)=0;
        virtual int Purchase(int choice, int n)=0;
        virtual void checkPurchase(int total, int *classMoneyPointer, int *classPointPointer,  int *tempIsVip)=0;
        virtual void addMoney(int amount, int *classMoneyPointer)=0;
        virtual void Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip)=0;
};


