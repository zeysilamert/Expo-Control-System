#include <iostream>
#include "vintage.h"

using namespace std;

bool Vintage::PopQuiz()
{
    srand(time(NULL));

    char answer;
    int a =  1 + rand () %2;

    if(a==1)
    {
        cout << "Who made the first phonograph?" << endl;
        cout << "A) Alexander Graham Bell" << endl << "B) Thomas Edison" << endl << "C) Nikola Tesla" << endl << "D) Wright Brothers" << endl; 
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

    else 
    {
        cout << "What instrument did Charlie Chaplin play?" << endl;
        cout << "A) Piano" << endl << "B) Guitar" << endl << "C) Flute" << endl << "D) Violin" << endl;
        cout << "Answer: ";
        cin >> answer;

        if(toupper(answer)=='D')
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

void Vintage::Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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

void Vintage::CalculatePoint(int money_spent, int *classPointPointer)
{
    if(money_spent>=15 && money_spent<=20)
    {
        *classPointPointer+=5;
    }

    else if(money_spent>20 && money_spent<=25)
    {
        *classPointPointer+=10;
    }

    else if(money_spent>30 && money_spent<=35)
    {
        *classPointPointer+=15;
    }

    else if(money_spent>40 && money_spent<=45)
    {
        *classPointPointer+=20;
    }

    else if(money_spent>45)
    {
        *classPointPointer+=25;
    }

    cout << "Your current point is: " << *classPointPointer << endl;
}

void Vintage::PriceList()
{
    cout << left << setw(20) << "On Sale" << left << setw(20) << "Prices" << endl;
    cout << left << setw(20) << "________" << left << setw(20) << "________" << endl;
    cout << left << setw(20) << "1.Records" << left << setw(20) << "$15" << endl;
    cout << left << setw(20) << "2.Radios" << left << setw(20) << "$25" << endl;
    cout << left << setw(20) << "3.Vintage Clothes" << left << setw(20) << "$45" << endl;
    cout << left << setw(20) << "4.Vintage Bags" << left << setw(20) << "$45" << endl;
    cout << left << setw(20) << "5.Analog Cameras" << left << setw(20) << "$35" << endl;
    cout << left << setw(20) << "6.Accessories" << left << setw(20) << "$20" << endl;
}

int Vintage::Purchase(int choice, int n)
{
    int total{0};
    if(choice==1)
    {
        total+=(15*n);
    }

    else if(choice==2)
    {
        total+=(25*n);
    }

    else if(choice==3)
    {
        total+=(45*n);
    }

    else if(choice==4)
    {
        total+=(45*n);
    }

    else if(choice==5)
    {
        total+=(35*n);
    }

    else if(choice==6)
    {
        total+=(20*n);
    }

    else{
        total+=0;
    }

    return total;
}

void Vintage::checkPurchase(int total, int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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