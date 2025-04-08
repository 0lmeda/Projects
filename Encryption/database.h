//Check if the file exists
bool checkDataBase(string filename){
    ifstream file(filename);
    return file.good();
}

//Create the file
bool createDataBase(string filename){
    ofstream file(filename, ios::app);

    if(file){
        return true;
    }
    else{
        return false;
    }
}

//Save a password with a tag
void saveInDataBase(string filename, string password, string tag){
    ofstream outfile(filename, ios::app);
    if(outfile) {
        outfile << tag << '-' <<password << endl;
        outfile.close();
        cout<<"Completely saved to "<<filename<<endl;
    }
}

//Split the tag and password
vector <string> splitIntoTwo(string filename, int option){
    vector <string > tags, passwords;

    ifstream FS (filename);

    string line, temp;
    int i;
    
    while (getline(FS , line))
    {
        temp = "";
        i = 0;
        for(char c: line){
            if(c == '-'){
                tags.push_back(temp);
                
                temp = "";
                i++;
            }
            else{
                temp += c;
            }
        }
        passwords.push_back(temp);
    }
    
    if(option == 0){
        return tags;
    }
    else{
        return passwords;
    }

}

//Find the tag
int findTag(vector <string> tags, string userTag){
    for (size_t i = 0; i < tags.size(); ++i) {
        if (userTag == tags[i]) {
            return i; 
        }
    }
    //If it doesn't exist in the file, it'll return a -1
    return -1; 



}



