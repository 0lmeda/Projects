

class Contacts{
    private:

        string phoneNumber;
        string contactName;
        vector <string> contactName;
        string email;
    
    public:
/*     string getAllContacts(const string filename){
        ifstream(filename);


     
    } */


    void makeContact(){
        cout<<"Enter a name: ";
        cin>>contactName;
        cout<<"Phone Number: ";
        cin>>phoneNumber;
        cout<<"Enter e-mail: ";
        cin>>email;
    }

};