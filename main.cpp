#include "password.h"
string generatePassword(int length)
{
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    srand(time(0));
    string password = "";
    for (int i = 0; i < length; i++) {
        int index = rand() % characters.length();
        password += characters[index];
    }
    return password;
}
void creator ()
{
    password c;
    ifstream inFile;
    inFile.open("file.dat",ios::binary);
    if(!inFile)
    {
        cout<<"You Will Enter The 1st Password : ";
        goto cre ;
    }
    cout << "Your Current List : " << endl ;
    cout<<"\n\n\t                          PASSWORDS LIST" << endl ;
     cout<<"==================================================================================="<< endl;
    cout<<"NO.                Account                      Email                      Password" << endl ;
    cout<<"===================================================================================" << endl;
    while(inFile.read(reinterpret_cast<char *> (&c), sizeof(password)))
    {
        c.displayData() ;
    }
    inFile.close();
    cre :
    password ac;
    ofstream outFile;
    outFile.open("file.dat",ios::binary|ios::app);
    ac.create() ;
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(password));
    outFile.close();
    cout << "\n Password Added "  << endl ;
}

void display_specific_password ( void )
{
    cout << "\nPasswords You Saved : " << endl ;
    password c;
    ifstream inFile;
    inFile.open("file.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File Can't Be Found !!";
        return ;
    }
    while(inFile.read(reinterpret_cast<char *> (&c), sizeof(password)))
    {
        cout << "\t" << c.no << ". " << c.acc << "." << endl ;
    }
    cout << "Which One You Want To Display ? :" ;
    password ox ;
    int o = 0 ;
    cin >> o ;
    inFile.close() ;
    ifstream File;
    File.open("file.dat",ios::binary);
    while(File.read(reinterpret_cast<char *> (&ox), sizeof(password)))
    {
        if (ox.retacno()== o )
        {
            cout << endl ;
            cout<<"==================================================================================="<< endl;
            cout<<"NO.                Account                      Email                      Password" << endl ;
            cout<<"===================================================================================" << endl;
            ox.displayData() ;
        }
    }
}

void display_all_passwords ( void )
{
    password ac;
    ifstream inFile;
    inFile.open("file.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t                          PASSWORDS LIST" << endl ;
    cout<<"==================================================================================="<< endl;
    cout<<"NO.                Account                      Email                      Password" << endl ;
    cout<<"===================================================================================" << endl;
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(password)))
    {
        ac.displayData() ;
        cout << endl  ;
    }
    inFile.close();
}
void deletor (int n)
{
    password ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("file.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File Could Not Be Opened !! Press Any Key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(password)))
    {
        if(ac.retacno()!= n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(password));
        }
    }
    inFile.close();
    outFile.close();
    remove("file.dat");
    rename("Temp.dat","file.dat");
    cout<<"\n\n\tPassword Deleted ..";
}
void editor (int x )
{
    password ac;
    ifstream inFile;
    ofstream outFile;
    outFile.open("Temp.dat",ios::binary);
    inFile.open("file.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File Could Not Be Opened !! Press Any Key...";
        return;
    }
    inFile.seekg(0,ios::beg);
    loop :
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(password)))
    {
        if(ac.retacno()== x)
        {
            char ne[30] ;
            cout << "Enter Your New Password : " ;
            cin.ignore() ;
            cin.get(ne , 30 ) ;
            strcpy(ac.passchar , ne ) ;
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(password));
            goto loop ;
        }
        outFile.write(reinterpret_cast<char *> (&ac), sizeof(password));
    }
    inFile.close();
    outFile.close();
    remove("file.dat");
    rename("Temp.dat","file.dat");
    cout<<"\n\n\tPassword Updated ..";
}
int main()
{
    password p ;
    int pass = 0 ;
    char k ;
    cout << "HELLO MY FRIEND , PLEASE ENTER THE PASSWORD : " ;
    cin >> pass ;
    if ( pass == p.kok )
    {
        system("cls") ;
        int cho = 0 ;
        password xx ;
        cout << "----------------------WELCOME TO YOUR SAFE ZONE---------------------- " << endl ;
        cout << "----------------------YOUR PASSWORDS' POCKET----------------------" << endl << endl << endl ;
        Main :
        cout << "WHAT DO YOU WANT TO DO ? " << endl ;
        cout << "1.Add New Password." << endl ;
        cout << "2.Remove Password." << endl ;
        cout << "3.Edit Password." << endl ;
        cout << "4.Display Specific Password." << endl ;
        cout << "5.Display All Passwords." << endl ;
        cout << "6.Generate Password." << endl ;
        cout << "7.Exit." << endl << endl  << endl ;
        cout << "Enter Your Choice : " ;
        cin >> cho ;
        switch ( cho )
        {
        case 1 :
            {
                creator () ;
            cout << "\nDone ? (y/n)" ;
            cin >> k ;
            system ("cls") ;
            goto Main ;
            break ;
            }
        case 2 :
            {
            display_all_passwords() ;
            cout << endl ;
            int s ;
            cout << "Enter The Account Which U Want to Delete It's Password : " ;
            cin >> s ;
            deletor(s) ;
            cout << "\nDone ? (y/n) " ;
            cin >> k ;
            system ("cls") ;
            goto Main ;
            break ;
            }
       case 3 :
           {
           display_all_passwords() ;
           cout << "Which Password U Want To Edit : " ;
           int x ;
           cin >> x ;
           editor(x) ;
           cout << "\nDone ? (y/n) " ;
           cin >> k ;
            system ("cls") ;
            goto Main ;
            break ;
           }
       case 4 :
            {
            display_specific_password() ;
            cout << "\nDone ? (y/n)" ;
            cin >> k ;
            system ("cls") ;
            goto Main ;
            break ;
            }
       case 5 :
           {
            display_all_passwords() ;
            cout << "\nDone ? (y/n) " ;
            cin >> k ;
            system ("cls") ;
            goto Main ;
            break ;
           }
           case 6 :
            {
            int length ;
            cout << "Enter password length: " ;
            cin >> length ;
            string password = generatePassword(length) ;
            cout << "Generated password: " << password << endl ;
            cout << "\nDone ? (y/n) " ;
            cin >> k ;
            system ("cls") ;
            goto Main ;
            break ;
            }
       case 7 :
            {
                exit(0) ;
            }
        }
    }
    else
    {
        cout << "!!!INCORRECT PASSWORD , BYE BYE " << endl ;
        return 0 ;
    }
}
