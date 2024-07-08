#include <iostream>
#include "book.h"

using namespace std;

bool Book::PopQuiz()
{
    srand(time(NULL));

    char answer;
    int a =  1 + rand () %2;

    if(a==1)
    {
        cout << "What novel written by Oscar Wilde has to do with immortality?" << endl;
        cout << "A) The Picture of Dorian Gray" << endl << "B) The Happy Prince" << endl << "C) Salome" << endl << "D) An Ideal Husband" << endl; 
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
        cout << "In the book 'The Little Prince', why doesn't the little prince think much of adults?" << endl;
        cout << "A) Because adults are show-offs" << endl << "B) Because adults have no imagination" << endl << "C) Because adults are mean" << endl << "D) Because adults think they know everything" << endl;
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

void Book::Sell(int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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

void Book::CalculatePoint(int money_spent, int *classPointPointer)
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

void Book::PriceList()
{
    cout << left << setw(20) << "On Sale" << left << setw(20) << "Prices" << endl;
    cout << left << setw(20) << "________" << left << setw(20) << "________" << endl;
    cout << left << setw(20) << "1.Novels" << left << setw(20) << "$15" << endl;
    cout << left << setw(20) << "2.Childrens' Books" << left << setw(20) << "$10" << endl;
    cout << left << setw(20) << "3.Poems" << left << setw(20) << "$6" << endl;
    cout << left << setw(20) << "4.Comics" << left << setw(20) << "$20" << endl;
    cout << left << setw(20) << "5.Magazines" << left << setw(20) << "$10" << endl;
    cout << left << setw(20) << "6.Book Mark" << left << setw(20) << "$2" << endl;
} 

int Book::Purchase(int choice, int n)
{
    int total{0};
    if(choice==1)
    {
        total+=(15*n);
    }

    else if(choice==2)
    {
        total+=(10*n);
    }

    else if(choice==3)
    {
        total+=(6*n);
    }

    else if(choice==4)
    {
        total+=(20*n);
    }

    else if(choice==5)
    {
        total+=(10*n);
    }

    else if(choice==6)
    {
        total+=(2*n);
    }

    else{
        total+=0;
    }

    return total;
}

void Book::checkPurchase(int total, int *classMoneyPointer, int *classPointPointer, int *tempIsVip)
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
                    cout << "You didn't add money. You can look for other things in our Expo.";
                    break;
                }

                else
                {
                    cout << "Invalid decision. Please press 'y' or 'n'.";
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
                    cout << "You didn't add money. You can look for other things in our Expo.";
                    break;
                }

                else
                {
                    cout << "Invalid decision. Please press 'y' or 'n'.";
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