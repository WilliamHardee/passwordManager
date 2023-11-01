#include <iostream>
#include <map>
#include <array>

using namespace std;

class Account {
    public:
        string name;
        string password;
    
    private: 
        map<string, array<string, 2>> listOfPasswords;


    public:
        Account(string AccName, string AccPassword) {
            name = AccName;
            password = AccPassword;
        }

        Account() = default;

        string getName(){
            return name;
        }

        string getPassWord() {
            return password;
        }

        void setName(string newName){
            name = newName;
        }

        void setPassword(string newPassword){
            password = newPassword;
        }

        void addPassword(string site, string username, string pws) {
            listOfPasswords[site][0] = username;
            listOfPasswords[site][1] = pws;

        }

        array<string, 2> getSiteCred(string site) {
            if(listOfPasswords.find(site) != listOfPasswords.end()) {
                return listOfPasswords[site];
            }
            return {"",""};
        }
};