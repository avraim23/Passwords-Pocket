#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;
using namespace std;
#ifndef PASSWORD_H
#define PASSWORD_H


class password
{
   public:
    int no ;
    char acc[50] , passchar[50] , email[50];
    int kok ;
    password () ;
    void create () ;
    void displayData () ;
    int retacno () ;
};

#endif // PASSWORD_H
