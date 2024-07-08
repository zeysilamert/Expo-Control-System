#include <iostream>
#include "christmas.h"

using namespace std;

bool Christmas::PopQuiz()
{
    srand(time(NULL));

    char answer;
    int a =  1 + rand () %2;

    if(a==1)
    {
        cout << "Which country started the tradition of putting up a Christmas tree?" << endl;
        cout << "A) Germany" << endl << "B) USA" << endl << "C) France" << endl << "D) Norway" << endl; 
        cout << "Answer: ";
        cin >> answer;

        
        if(toupper(answer)=='A')
        {
            cout << "Your answer is correct. Congrats!" << endl;
            return true;
        }

        else
        {
            cout << "Your answer is incorrect. Try again later." << endl;
            return false;
        }
    }

    else 
    {
        cout << "In the movie Home Alone, where are the McCallisters going on vacation when they leave Kevin behind?" << endl;
        cout << "A) Alaska" << endl << "B) Paris" << endl << "C) New York" << endl << "D) Madrid" << endl;
        cout << "Answer: ";
        cin >> answer;

        if(toupper(answer)=='B')
        {
            cout << "Your answer is correct. Congrats!" << endl;
            return true;
        }

        else
        {
            cout << "Your answer is incorrect. Try again later." << endl;
            return false;
        }
    }
    
}


void Christmas::Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
{
    char decision{'y'};
    int choice, n, totalPrice{0};

    PriceList();
    do{
        cout << "What would you like to buy? ";
        cin >> choice;
        cout << "How many would you like to buy? ";
        cin >> n;
        totalPrice=Purchase(choice, n);
        checkPurchase(totalPrice, classMoneyPointer, classPointPointer, tempIsVip);
        cout << "Would you like to continue your purchase? (y/n) ";
        cin >> decision;
    }while(decision!='n');
}

void Christmas::CalculatePoint(int money_spent, int *classPointPointer)
{
    if(money_spent>0 && money_spent<=10)
    {
        *classPointPointer+=5;
    }

    else if(money_spent>10 && money_spent<=20)
    {
        *classPointPointer+=10;
    }

    else if(money_spent>20 && money_spent<=30)
    {
        *classPointPointer+=15;
    }

    else if(money_spent>30 && money_spent<=40)
    {
        *classPointPointer+=20;
    }

    else if(money_spent>40)
    {
        *classPointPointer+=25;
    }

    cout << "Your current point is: " << *classPointPointer << endl;
}

void Christmas::PriceList()
{
    cout << left << setw(20) << "On Sale" << left << setw(20) << "Prices" << endl;
    cout << left << setw(20) << "________" << left << setw(20) << "________" << endl;
    cout << left << setw(20) << "1.Cups" << left << setw(20) << "$4" << endl;
    cout << left << setw(20) << "2.Puzzle" << left << setw(20) << "$6" << endl;
    cout << left << setw(20) << "3.Christmas Hat" << left << setw(20) << "$6" << endl;
    cout << left << setw(20) << "4.Christmas Socks" << left << setw(20) << "$5" << endl;
    cout << left << setw(20) << "5.Snow Globes" << left << setw(20) << "$10" << endl;
    cout << left << setw(20) << "6.Christmas Tree" << left << setw(20) << "$50" << endl;
}

int Christmas::Purchase(int choice, int n)
{
    int total{0};
    if(choice==1)
    {
        total+=(4*n);
    }

    else if(choice==2)
    {
        total+=(6*n);
    }

    else if(choice==3)
    {
        total+=(6*n);
    }

    else if(choice==4)
    {
        total+=(5*n);
    }

    else if(choice==5)
    {
        total+=(10*n);
    }

    else if(choice==6)
    {
        total+=(50*n);
    }

    else{
        total+=0;
    }

    return total;
}

void Christmas::checkPurchase(int total, int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
{
    char decision;
    int amount{0};

    if(*tempIsVip==0)
    {
        if(total> *classMoneyPointer)
        {
            cout << "You don't have enough money to purchase." << endl << "Your current money: " << *classMoneyPointer << endl;
        
            while(true)
            {
                cout << "Would you like to add money? (y/n) ";
                cin >> decision;

                if(decision=='y')
                {
                    cout << "Enter the amount you want to add: ";
                    cin >> amount;
                    addMoney(amount, classMoneyPointer);
                    cout << "You've successfully added money. Your current money: " << *classMoneyPointer << endl;
                    break;
                }

                else if(decision=='n')
                {
                    cout << "You didn't add money. You can look for other things in our Expo." << endl;
                    break;
                }

                else
                {
                    cout << "Invalid decision. Please press 'y' or 'n'." << endl;
                }
            }
        }

        else
        {
            *classMoneyPointer-=total;
            cout << "Purchase is successful." << endl << "Money left: " << *classMoneyPointer << endl;
            CalculatePoint(total, classPointPointer);
        }
    }
    
    else
    {
        if(total*0.8 > *classMoneyPointer)
        {
            cout << "You don't have enough money to purchase." << endl << "Your current money: " << *classMoneyPointer << endl;
        
            while(true)
            {
                cout << "Would you like to add money? (y/n) ";
                cin >> decision;

                if(decision=='y')
                {
                    cout << "Enter the amount you want to add: ";
                    cin >> amount;
                    addMoney(amount, classMoneyPointer);
                    cout << "You've successfully added money. Your current money: " << *classMoneyPointer << endl;
                    break;
                }

                else if(decision=='n')
                {
                    cout << "You didn't add money. You can look for other things in our Expo." << endl;
                    break;
                }

                else
                {
                    cout << "Invalid decision. Please press 'y' or 'n'." << endl;
                }
            }
        }

        else
        {
            *classMoneyPointer-=total*0.8;
            cout << "Purchase is successful." << endl << "Money left: " << *classMoneyPointer << endl;
            CalculatePoint(total, classPointPointer);
        }
    }
}