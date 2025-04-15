#include <iostream>
#include <vector>
#include <fstream>


using namespace std;


#include "file.h"
#include "classes.h"

const string filename = "contacts.txt";



int main(){
    vector <string> contactList;
    vector <Contacts> contactsFrom;

    if(!checkFile(filename)){
        if(createFile(filename)){
            cout<<"It has been created sucessfully"<<endl;
        }
        else{
            cout<<"Error 1101: Failed in create the file";
        }
    }


    // contactList = loadContacts(filename);
    // contactsFrom = convertToContacts(contactList);
    

    
    int option;

    do{
        contactList = loadContacts(filename);
        contactsFrom = convertToContacts(contactList);
        cout<<"Menu \n"<<"1. Show Contacts\n2. Create a new contact\n0. Exit\n";
        cin>>option;

        if(option == 1){
            for (int i = 0; i < contactsFrom.size(); i++) {
                contactsFrom[i].display();
            }
        }else if(option == 2){
            string name, phoneNumber, email;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter phone Number: ";
            cin>>phoneNumber;
            cout<<"Enter email: ";
            cin>>email;

            saveContact(filename, name,phoneNumber,email);
        }

    }while(option !=0);
    return 0;
}