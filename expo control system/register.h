#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Register{
    private:
        string username;
        string password;
        int point;
        int money;
        int isVip;

    public:
        bool LoggingIn();
        void setUsername(string u){username=u;}
        void setPassword(string p){password=p;}
        void setPoint(int pt){point=pt;}
        void setMoney(int m){money=m;}
        void setIsVip(int iv){isVip=iv;}
        string getUsername(){return username;}
        string getPassword(){return password;}
        int getPoint(){return point;}
        int getMoney(){return money;}
        int getIsVip(){return isVip;}
};
