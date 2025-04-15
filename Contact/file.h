bool checkFile(const string filename){
    ifstream FS (filename);
    return FS.good();

}

bool createFile(const string filename){
    ofstream FS (filename);
    
    if(FS){
        return true;
    }else{
        return false;
    }
}

vector <string> loadContacts(const string filename){
    ifstream FS (filename);
    string line;
    vector <string> list;
    while(getline(FS, line)){
        
        list.push_back(line);
        
    }

    return list;
}

void saveContact(const string file, string n, string p, string e){
    //ios::app, allows to write text withouth deleting existing text
    ofstream FS (file, ios::app);

    FS<<"\n"<<n<<' '<<p<<' '<<e;


}