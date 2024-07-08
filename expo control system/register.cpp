#include <iostream>
#include "register.h"

using namespace std;

bool Register::LoggingIn()
{
    string username, password, user, pass;

    cout << "Enter username: "; 
    cin >> username;
    setUsername(username);
    cout << "Enter password: ";
    cin >> password;
    setPassword(password);

    ifstream read(username + ".txt");
    getline(read, user);
    getline(read, pass);

    if(user==username && pass==password)
    {
        return true;
    }

    else
    {
        return false;
    }
}