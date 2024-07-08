#pragma once
#include <iostream>
#include <string>
#include "user.h"

using namespace std;

class VipUser: public User{
    public:
        VipUser();
        VipUser(string name, string pass, int pt, int m, int iv) : User(name,pass,pt,m,iv) {}
};

