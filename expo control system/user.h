#pragma once
#include <iostream>
#include <string>
#include "register.h"

using namespace std;

class User{
    
    public:
        User();
        User(string name, string pass, int pt, int m, int iv): username{name}, password{pass}, point{pt}, money{m}, isVip{iv} {}
        void setMoney(int m){money=m;}
        int getMoney(){return money;}
        int getPoint(){return point;}
        string getUsername(){return username;}
        int getIsVip(){return isVip;}

    protected:
        string username;
        string password;
        int point; 
        int money; 
        int isVip;
};
