//Libraries used 
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

//Conecting local libraries
#include "encryption.h"
#include "database.h"

//Defining name of the file where the passwords will be located
const string filename = "pswd.txt";

//Function to encrypt the password
string encryptPassword() {
    string password, key;
    cout << "Insert the password: ";
    cin >> password;
    cout << endl << "Insert the key: ";
    cin >> key;
    string newPassword = encrypt(password, key);

    return newPassword;
}

//Function to decrypt the password
string decryptPassword(int index){
    vector <string> passwords = splitIntoTwo(filename, 1);
    string key;
    cout<<"Insert the key: ";
    cin>>key;
    string decryptedPassword = encrypt(passwords[index], key);

    return decryptedPassword;
} 


int main() {
    char option;
    //Variables
    int menu;
    bool dataBase;
    string password;
    string userTag;
    vector <string> tags;
    int index;

    
    //Check if the file existed, if it doesn't, it will make the file
    if(checkDataBase(filename)){
        dataBase = true;
    }else{
        if(createDataBase(filename)){
            dataBase = true;
        }
        else{
            dataBase = false;
        }
    }

    // Print a line of '#' characters
    for (int i = 0; i < 20; i++) {
        cout << '#';
    }
    
    //Menu
    do {
        cout << endl << "Welcome to encryption" << endl;
        cout << endl << "Menu: " << endl
             << "1. Encrypt a password" << endl
             << "2. Decrypt a password" << endl
             << "Choose one: ";
        cin >> menu;
        switch (menu) {
            case 1:
                password = encryptPassword();
                cout<<"Insert a tag for the password (Ex. IG): ";
                cin>>userTag;
                saveInDataBase(filename, password, userTag);
                break;
            case 2:
                
                cout<<"Enter the tag of the password: ";
                cin>>userTag;
                tags = splitIntoTwo(filename, 0);
                index  = findTag(tags, userTag);
                if(index!=-1){
                    password = decryptPassword(index);
                    cout<<"This is ur password "<<password<<endl;
                }else{
                    cout<<"The tag is not in file."<<endl;
                }

                
                break;
                default:
                cout << "Invalid option! Try again." << endl;
        }

        cout << "Do you want to run the program again? Y/y or N/n" << endl;
        cin >> option;
    } while (option != 'n' && option != 'N');  

    return 0;
}
