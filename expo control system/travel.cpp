#include <iostream>
#include "travel.h"

using namespace std;

bool Travel::PopQuiz()
{
    srand(time(NULL));

    char answer;
    int a =  1 + rand () %2;

    if(a==1)
    {
        cout << "What is the capital city of Australia?" << endl;
        cout << "A) Canberra" << endl << "B) Sydney" << endl << "C) Melbourne" << endl << "D) New York" << endl; 
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
        cout << "What is the most popular language in the world?" << endl;
        cout << "A) English" << endl << "B) German" << endl << "C) Spanish" << endl << "D) Chinese" << endl;
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


void Travel::CalculatePoint(int money_spent, int *classPointPointer)
{
    if(money_spent>=40 && money_spent<=60)
    {
        *classPointPointer+=5;
    }

    else if(money_spent>60 && money_spent<=70)
    {
        *classPointPointer+=10;
    }

    else if(money_spent>70 && money_spent<=120)
    {
        *classPointPointer+=15;
    }

    else if(money_spent>120 && money_spent<=200)
    {
        *classPointPointer+=20;
    }

    else if(money_spent>200)
    {
        *classPointPointer+=25;
    }

    cout << "Your current point is: " << *classPointPointer << endl;
}

void Travel::PriceList()
{
    cout << left << setw(20) << "On Sale" << left << setw(20) << "Prices" << endl;
    cout << left << setw(20) << "________" << left << setw(20) << "________" << endl;
    cout << left << setw(20) << "1.Tour Tickets" << left << setw(20) << "$200" << endl;
    cout << left << setw(20) << "2.Suitcases" << left << setw(20) << "$70" << endl;
    cout << left << setw(20) << "3.Surfing Boards" << left << setw(20) << "$117" << endl;
    cout << left << setw(20) << "4.Snowboard" << left << setw(20) << "$80" << endl;
    cout << left << setw(20) << "5.Train tickets" << left << setw(20) << "$40" << endl;
    cout << left << setw(20) << "6.Plane Tickets" << left << setw(20) << "$80" << endl;

}

void Travel::Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
{
    char decision{'y'};
    char addDecision;
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

int Travel::Purchase(int choice, int n)
{
    int total{0};
    if(choice==1)
    {
        total+=(200*n);
    }

    else if(choice==2)
    {
        total+=(70*n);
    }

    else if(choice==3)
    {
        total+=(117*n);
    }

    else if(choice==4)
    {
        total+=(80*n);
    }

    else if(choice==5)
    {
        total+=(40*n);
    }

    else if(choice==6)
    {
        total+=(80*n);
    }

    else{
        total+=0;
    }

    return total;
}

void Travel::checkPurchase(int total, int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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