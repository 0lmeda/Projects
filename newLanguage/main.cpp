#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


const string filename = "main.cin";
vector<string> varNames;
vector<string> varValues;


void setVar(string name, string value){
    for(int i = 0; i< varNames.size(); i++){
        if(varNames[i] == name){
            varValues[i] = value;
            return;
        }
    }
    varNames.push_back(name);
    varValues.push_back(value);
}

string getVar(string name){
    for(int i = 0; i<varNames.size(); i++){
        if(varNames[i] == name){
            return varValues[i];
        }
    }
    return name;
}


void readLine(string line){
    int i = 0;
    while (i < line.size() && line[i] == ' ') {
        i++;
    }
    line = line.substr(i);

    //Find if theres any variable in the line
    int variablePosition = line.find("var");

    if(variablePosition != -1){
        string remaining = line.substr(variablePosition + 4); // skips "var "

        int equalPosition = remaining.find('=');

        if(equalPosition != -1){
            string var = remaining.substr(0, equalPosition);
            string val = remaining.substr(equalPosition+1);
            while (var[0] == ' ') var = var.substr(1);
            while (var[var.size() - 1] == ' ') var = var.substr(0, var.size() - 1);
            while (val[0] == ' ') val = val.substr(1);
            while (val[val.size() - 1] == ' ') val = val.substr(0, val.size() - 1);
    
            setVar(var,val);
        }
    }

    


    if(line.substr(0,5) == "print"){
        string value = line.substr(6);
        cout<< getVar(value)<<endl;
    }
}






int main(){
    string line;
    ifstream fs(filename);    

    while(getline(fs, line)){
        readLine(line);
    }

    return 0;
}