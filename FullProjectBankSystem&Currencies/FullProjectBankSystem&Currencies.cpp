#include <iostream>
#include "clsLogin.h"

using namespace std;


int main()
{
    while (true)
    {
        if (!clsLogin::ShowLoginScreen())
        {
            break;
        }
    }

    return 0;
}

