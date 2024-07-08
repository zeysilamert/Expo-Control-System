#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "register.cpp"
#include "user.h"
#include "vipUser.h"
#include "christmas.cpp"
#include "book.cpp"
#include "plants.cpp"
#include "vintage.cpp"
#include "art.cpp"
#include "travel.cpp"
#include<bits/stdc++.h>

using namespace std;

void PrintMenu()
{
    cout << "Welcome!" << endl << "There are Christmas, Book, Vintage, Plant, Art and Travel Expos available." << endl;
}

void PurchaseControl(int *funcPointPointer, int *funcMoneyPointer, int *tempIsVip) 
{
    string expoName;
    
    PrintMenu();
    cout << "Which Expo would you like to visit? ";
    cin >> expoName;
    transform(expoName.begin(), expoName.end(), expoName.begin(), ::tolower);

    if(expoName=="book")
    {
        Book obj;
        obj.Sell(funcMoneyPointer, funcPointPointer, tempIsVip); 
        if(*funcPointPointer>=100 && *tempIsVip==0)
        {
            if(obj.PopQuiz())
            {
                *tempIsVip=1;
                cout << "You have successfully got upgraded to VIP Class." << endl;
            }
        }
    }

    else if(expoName=="plant")
    {
        Plants obj;
        obj.Sell(funcMoneyPointer, funcPointPointer, tempIsVip);

        if(*funcPointPointer>=100 && *tempIsVip==0)
        {
            if(obj.PopQuiz())
            {
                *tempIsVip=1;
                cout << "You have successfully got upgraded to VIP Class." << endl;
            }
        }
    } 

    else if(expoName=="christmas")
    {
        Christmas obj;
        obj.Sell(funcMoneyPointer, funcPointPointer, tempIsVip);

        if(*funcPointPointer>=100 && *tempIsVip==0)
        {
            if(obj.PopQuiz())
            {
                *tempIsVip=1;
                cout << "You have successfully got upgraded to VIP Class." << endl;
            }
        }
    } 

    else if(expoName=="vintage")
    {
        Vintage obj;
        obj.Sell(funcMoneyPointer, funcPointPointer, tempIsVip);

        if(*funcPointPointer>=100 && *tempIsVip==0)
        {
            if(obj.PopQuiz())
            {
                *tempIsVip=1;
                cout << "You have successfully got upgraded to VIP Class." << endl;
            }
        }
    } 

    else if(expoName=="travel")
    {
        Travel obj;
        obj.Sell(funcMoneyPointer, funcPointPointer, tempIsVip);

        if(*funcPointPointer>=100 && *tempIsVip==0)
        {
            if(obj.PopQuiz())
            {
                *tempIsVip=1;
                cout << "You have successfully got upgraded to VIP Class." << endl;
            }
        }
    } 

    else if(expoName=="art")
    {
        Art obj;
        obj.Sell(funcMoneyPointer, funcPointPointer, tempIsVip);

        if(*funcPointPointer>=100 && *tempIsVip==0)
        {
            if(obj.PopQuiz())
            {
                *tempIsVip=1;
                cout << "You have successfully got upgraded to VIP Class." << endl;
            }
        }
    } 
}

int main()
{
    int choice{0};
    int temp{0};
    string main_username, main_password;
    Register visitor; 
    User *user;

    cout << "1.Register" << endl << "2.Login"  << endl << "Select your choice: ";
    cin >> choice;

    if(choice==1)
    {
        cout << "Select an username: ";
        cin >> main_username;
        visitor.setUsername(main_username);
        
        cout << "Select a password: ";
        cin >> main_password;
        visitor.setPassword(main_password);

        visitor.setPoint(0);
        visitor.setMoney(0);
        visitor.setIsVip(0);

        ofstream file;
        file.open(visitor.getUsername() + ".txt");

        file << visitor.getUsername() << endl << visitor.getPassword() << endl << visitor.getPoint() << endl << visitor.getMoney() << endl << visitor.getIsVip();
        file.close();

        user = new User{visitor.getUsername(), visitor.getPassword(), visitor.getPoint(), visitor.getMoney(), visitor.getIsVip()};
    }

    else if(choice==2)
    {
        bool status;
        status=visitor.LoggingIn();

        while(!status)
        {
            cout << "Incorrect password or username, please try again!" << endl;
            status=visitor.LoggingIn();
        }

        cout << "Login succesful!" << endl;

        vector <string> str;
        string memberUsername, memberPassword, login_line;
        int i{0}, memberPoint, memberMoney, memberIsVip;

        ifstream file;
        file.open(visitor.getUsername() + ".txt");

        stringstream ns;

        while(getline(file, login_line))
        {
            str.push_back(login_line);
        } 

        for(size_t i=0; i<5; ++i)
        {
            if(i==0)
            {
                memberUsername = str.at(i);
            }

            if(i==1)
            {
                memberPassword = str.at(i);
            }

            else if(i==2)
            {
                ns << str.at(i) << " ";
            }

            else if(i==3)
            {
                ns << str.at(i) << " ";
            }

            else if(i==4)
            {
                ns << str.at(i);
            }
        }

        ns >> memberPoint >> memberMoney >> memberIsVip;

        if(memberIsVip==0) // check if user's points exceed the point limit, if yes upgrade user to VIP class
        {
            user = new User{memberUsername, memberPassword, memberPoint, memberMoney, memberIsVip};
        }

        else
        {
            user = new VipUser{memberUsername, memberPassword, memberPoint, memberMoney, memberIsVip};
        }    
    }

    int userPoint=user->getPoint();
    int userMoney=user->getMoney();
    int tempIsVip=user->getIsVip();

    char decision; 

    do{
        PurchaseControl(&userPoint, &userMoney, &tempIsVip);

        cout << "Would you like to visit other Expos? (y/n) ";
        cin>> decision;

    }while(decision!='n');

    cout << "Purchase was done successfully. Thank you for visiting our Expo.";

    vector <string> lines;
    string line;

    ifstream file;
    file.open(user->getUsername() + ".txt");

    while(getline(file, line)) 
    {
        lines.push_back(line);
    }

    ofstream tempFile;
    tempFile.open("temp.txt");

    for(size_t i=1; i<=5; ++i)
    {
        if(i==1)
        {
            tempFile << lines.at(0) << endl;
        }

        else if(i==2)
        {
            tempFile << lines.at(1) << endl;
        }

        else if(i==3)
        {
            tempFile << userPoint << endl;
        }

        else if(i==4)
        {
            tempFile << userMoney << endl;
        }

        else if(i==5)
        {
            tempFile << tempIsVip;
        }
    }

    tempFile.close();
    file.close();
    
    string fileName = user->getUsername() + ".txt";
    if(remove(fileName.c_str())!=0)
        cout << "Remove operation failed.";

    if(rename("temp.txt", fileName.c_str())!=0)
        cout << "Rename operation failed.";

    
}  

