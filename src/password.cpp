#include "Password.h"

password::password()
{
    time_t now = time(0);
    tm* local_time = localtime(&now);
    int hour = local_time->tm_hour;
    int minute = local_time->tm_min;
    kok = ((hour*100)+ minute) + 2370000 ;
}
void password::create ()
{
    cout << "\n Enter PassWord Number : " ;
    cin >> no ;
    cout << "\n Enter The Site Or The Place Where This PassWord Will be Used : " ;
    cin.ignore() ;
    cin.getline(acc,50) ;
    cout << "\n Enter The Email: " ;
    cin.getline(email,50) ;
    cout << " Enter The PassWord : " ;
    cin.getline(passchar,50) ;
}
void password::displayData ()
{
    cout << no << "                " << acc << "                " << email << "                " << passchar << endl ;
}
int password::retacno ()
{
     return no ;
}
