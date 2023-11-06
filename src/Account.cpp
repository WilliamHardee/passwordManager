#include <iostream>
#include <map>
#include <array>
#include "../include/Account.hpp"
using namespace std;
 
   
Account::Account(string AccName, string AccPassword) {
    name = AccName;
    password = AccPassword;
}

Account::Account() = default;

void Account::setName(string newName){
    name = newName;
}

void Account::setPassword(string newPassword){
    password = newPassword;
}

void Account::addPassword(string site, string username, string pws) {
    listOfPasswords[site][0] = username;
    listOfPasswords[site][1] = pws;
}

array<string, 2> Account::getSiteCred(string site) {
    if(listOfPasswords.find(site) != listOfPasswords.end()) {
        return listOfPasswords[site];
    }
    return {"",""};
}
