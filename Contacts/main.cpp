#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

#include "classes.h"
#include "file.h"

const string filename = "contacts.txt";

int main(){


    if(!checkFile(filename)){
        if(createFile(filename)){
            cout<<"The file has been created correclty"<<endl;
        }else{
            cout<<"There's an error with the creation of the file.";
        }
        
    }
    
    int option;

    Contacts contact;


    do{

        cout<<"Menu: "<<endl<<"1. Check Contacts"<<endl<<"2. Make a new Contact"<<endl<<"0. To exit"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"In progress.";    
        break;
        case 2:
            contact.makeContact();
        break;
        default:
            break;
        }

    }while(option != 0);




    return 0;
}