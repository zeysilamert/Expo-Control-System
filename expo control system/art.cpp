#include <iostream>
#include "art.h"

using namespace std;

bool Art::PopQuiz()
{
    srand(time(NULL));

    char answer;
    int a =  1 + rand () %2;

    if(a==1)
    {
        cout << "Which artist does the painting 'The Scream' belongs to?" << endl;
        cout << "A) Vincent Van Gogh" << endl << "B) Picasso" << endl << "C) Munch" << endl << "D) Leonardo da Vinci" << endl; 
        cout << "Answer: ";
        cin >> answer;

        
        if(toupper(answer)=='C')
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
        cout << "How many paintings did Vincent Van Gogh sell when he was still alive?" << endl;
        cout << "A) 1" << endl << "B) 43" << endl << "C) 57" << endl << "D) 23" << endl;
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
    
}

void Art::Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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

void Art::CalculatePoint(int money_spent, int *classPointPointer)
{
    if(money_spent>=15 && money_spent<=25)
    {
        *classPointPointer+=5;
    }

    else if(money_spent>25 && money_spent<=35)
    {
        *classPointPointer+=10;
    }

    else if(money_spent>35 && money_spent<=45)
    {
        *classPointPointer+=15;
    }

    else if(money_spent>45)
    {
        *classPointPointer+=20;
    }

    cout << "Your current point is: " << *classPointPointer << endl;
}

void Art::PriceList()
{
    cout << left << setw(20) << "On Sale" << left << setw(20) << "Prices" << endl;
    cout << left << setw(20) << "________" << left << setw(20) << "________" << endl;
    cout << left << setw(20) << "1.Paintings" << left << setw(20) << "$45" << endl;
    cout << left << setw(20) << "2.Canvases" << left << setw(20) << "$15" << endl;
    cout << left << setw(20) << "3.Brushes" << left << setw(20) << "$15" << endl;
    cout << left << setw(20) << "4.Paints" << left << setw(20) << "$20" << endl;
    cout << left << setw(20) << "5.Figurines" << left << setw(20) << "$30" << endl;
    cout << left << setw(20) << "6.Mini Sculptures" << left << setw(20) << "$45" << endl;
}

int Art::Purchase(int choice, int n)
{
    int total{0};
    if(choice==1)
    {
        total+=(45*n);
    }

    else if(choice==2)
    {
        total+=(15*n);
    }

    else if(choice==3)
    {
        total+=(15*n);
    }

    else if(choice==4)
    {
        total+=(20*n);
    }

    else if(choice==5)
    {
        total+=(30*n);
    }

    else if(choice==6)
    {
        total+=(45*n);
    }

    else{
        total+=0;
    }

    return total;
}

void Art::checkPurchase(int total, int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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