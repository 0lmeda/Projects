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
