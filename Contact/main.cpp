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


    contactList = loadContacts(filename);
    contactsFrom = convertToContacts(contactList);
    
        for (int i = 0; i < contactsFrom.size(); i++) {
            contactsFrom[i].display();
        }
    
    return 0;
}