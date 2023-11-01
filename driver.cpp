#include "Account.hpp"
#include <iostream>
#include <list>
#include <map>

void signUp(map<string, Account> &, string , string); 
Account* signIn(map<string, Account>, string , string); 

using namespace std;

int main() {

    string username;
    string password;
    map<string, Account> accounts;
    int choice = 0;
    Account* currentAcc;

 
    while(choice != 1 && choice != 2 && choice != 3) {
        cout << "Would you like to login (1) or sign up (2) or quit (3): ";
        cin >> choice;
        if(choice == 2) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            signUp(accounts, username, password);
            cout << "Account succesfully created!\n";
        }
        if(choice == 1) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            currentAcc = signIn(accounts, username, password);
            if(currentAcc != nullptr) {
                string site;
                string siteUser;
                string sitePws;
                int credChoice = 0;
                while(credChoice != 1 && credChoice!=2 && credChoice != 3) {
                    cout << "Would you like to add site credentials (1) or get site credentials (2) or sign out (3): ";
                    cin >> credChoice;
                    if(credChoice == 1) {
                        cout << "Input site name: ";
                        cin >> site;
                        cout << "Input site username: ";
                        cin >> siteUser;
                        cout << "Input site password: ";
                        cin >> sitePws;
                        currentAcc->addPassword(site, siteUser, sitePws);
                    }
                    if(credChoice == 2) {
                        array<string, 2> cred;
                        cout << "Input site name: ";
                        cin >> site;
                        cred = currentAcc->getSiteCred(site);
                        cout << "Username: ";
                        cout << cred[0];
                        cout << "\nPassword: ";
                        cout << cred[1];
                        cout << "\n";
                    }
                    if(credChoice == 3) {
                         break;
                    }
                    credChoice = 0;
                }
            }
        }
        if(choice == 3) {
            break;
        }  
        choice = 0;
    }
} 

void signUp(map<string, Account> &accountList, string username, string password) {
    Account newAccount = Account(username, password);
    accountList[username] = newAccount;
}

Account* signIn(map<string, Account> accountList, string username, string password) {
    Account tempAccount;
    if(accountList.find(username) != accountList.end()){
        tempAccount = accountList[username];
        if(tempAccount.getPassWord() == password) {
            cout << "Signed in as: ";
            cout << username;
            cout << "\n";
            return &accountList[username];
        }
    }
    cout <<"Account not found \n";
    return nullptr;

};
