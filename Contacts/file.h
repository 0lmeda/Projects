
bool checkFile(const string filename){
    ifstream FS(filename);

    return FS.good();


}

bool createFile(const string filename){
    ofstream FS(filename);

    if(FS){
        return true;
    }else{
        return false;
    }
}

