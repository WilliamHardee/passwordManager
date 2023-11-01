#ifndef Account_HPP__
#define Account_HPP__
#include <array>
#include <map>
#include <iostream>

using namespace std;
class Account{
    private:
        map<string, array<string, 2>> listOfPasswords;
    
    public:
        string name;
        string password;
        Account(string AccName, string AccPassword);
        Account();
        string getName();
        string getPassWord();
        void setName(string newName);
        void setPassword(string newPassword);
        void addPassword(string site, string username, string pws);
        array<string, 2> getSiteCred(string site);
};

#endif