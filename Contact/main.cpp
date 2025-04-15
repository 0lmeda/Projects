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
        cout<<"Menu \n"<<"1. Show Contacts\n2. Create a new contact\n3. Find A contact\n0. Exit\n";
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
        else if(option == 3){
            string targetName;
            int index = -1;
            cout<<"Enter the name that the person you want to find: ";
            cin>>targetName;

            for(int i = 0 ; i<contactsFrom.size(); i++){

                if(contactsFrom[i].name == targetName){
                    index = i;
                    break;
                }
         

            }

            if(index == -1){
                cout<<targetName<<" doesn't exist in the list";

            }
            else{
                contactsFrom[index].display();
            }

            cout<<endl;
        }

    }while(option !=0);
    return 0;
}