
class Contacts{
    private:
    string name;
    string phoneNumber;
    string email;

    public:
    Contacts(string n, string p, string e){
        name = n;
        phoneNumber = p;
        email = e;

        
    }

    void display()  {
        string correctView;
        int i = 0;
        for(char c: phoneNumber){
            if(i == 3 || i == 6){
                correctView+='-';
            }
            correctView += c;
            i++;
        }

        cout << "Name: " << name << ", Phone: " << correctView << ", Email: " << email << endl;
    }

};




 vector <Contacts> convertToContacts(vector <string> list){
    vector<Contacts> contacts;
    string temp, line;
    string n,p,e;
    int index = 0;;


    for(int i = 0; i<list.size(); i++){
        line = list[i];
        for(char c: line){
            if(c == ' '){
                switch (index)
                {
                case 0:
                n = temp;
                index++;
                temp ="";
                break;
                case 1:
                p = temp;
                index++;
                temp ="";
                break;
                case 2:
                e = temp;
                index++;
                temp ="";
                break;

                }
            }
            else{
                temp+= c;
            }

            
        }
        e = temp;
        index  = 0;
        temp ="";

        Contacts contact(n,p,e);
        contacts.push_back(contact);
    }
    return contacts;
}