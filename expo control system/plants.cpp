#include <iostream>
#include "plants.h"

using namespace std;

bool Plants::PopQuiz()
{
    srand(time(NULL));

    char answer;
    int a =  1 + rand () %2;

    if(a==1)
    {
        cout << "Which one of the following is not needed by all plants?" << endl;
        cout << "A) Sun" << endl << "B) Earth" << endl << "C) Water" << endl << "D) Air" << endl; 
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
        cout << "Where do plants get their green color?" << endl;
        cout << "A) Chloroplast" << endl << "B) Mitochondria" << endl << "C) Chlorophyll" << endl << "D) Vacuole" << endl;
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
    
}

void Plants::Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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

void Plants::CalculatePoint(int money_spent, int *classPointPointer)
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

void Plants::PriceList()
{
    cout << left << setw(20) << "On Sale" << left << setw(20) << "Prices" << endl;
    cout << left << setw(20) << "________" << left << setw(20) << "________" << endl;
    cout << left << setw(20) << "1.Roses" << left << setw(20) << "$12" << endl;
    cout << left << setw(20) << "2.Cactuses" << left << setw(20) << "$8" << endl;
    cout << left << setw(20) << "3.Bamboos" << left << setw(20) << "$2" << endl;
    cout << left << setw(20) << "4.Violets" << left << setw(20) << "$15" << endl;
    cout << left << setw(20) << "5.Flower Pots" << left << setw(20) << "$23" << endl;
    cout << left << setw(20) << "6.Fertilizer" << left << setw(20) << "$31" << endl;
}

int Plants::Purchase(int choice, int n)
{
    int total{0};
    if(choice==1)
    {
        total+=(12*n);
    }

    else if(choice==2)
    {
        total+=(8*n);
    }

    else if(choice==3)
    {
        total+=(2*n);
    }

    else if(choice==4)
    {
        total+=(15*n);
    }

    else if(choice==5)
    {
        total+=(23*n);
    }

    else if(choice==6)
    {
        total+=(31*n);
    }

    else{
        total+=0;
    }

    return total;
}

void Plants::checkPurchase(int total, int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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
