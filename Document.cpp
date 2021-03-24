//
// Created by Jessuca Fliker 19/3/2021
//
#include <iostream>
#include <fstream>
#include "Document.h"


using namespace std;

Document::Document(){
    this->CurrLine = 0;
    cout << "default" << endl;
}

Document::Document(string file){
    std::ifstream inFile(file);
    std::string line;
    while(getline(inFile, line)){
        document.push_back(line);
    }
    this->CurrLine = document.size()-1;
    cout << "file uploaded" << endl;
}

Document::~Document(){}

void Document::changeCurrLine(int newL){
    this->CurrLine = newL-1;
    cout << "new line:" << this->CurrLine+1 << endl;
}

void Document::linesForwards(int x){
    this->CurrLine = this->CurrLine + x;
    cout << "new line:" << this->CurrLine+1 << endl;
}

void Document::linesBackwards(int x){
    this->CurrLine = this->CurrLine - x;
    cout << "new line:" << this->CurrLine+1 << endl;
}

void Document::last(){
    this->CurrLine = document.size()-1;
    cout << "new line:" << this->CurrLine+1 << endl;
}

void Document::addAfter(){
    string str = "";
    while(getline(cin,str)){
        if(str.compare(".") == 0) break;
        if(this->document.size() == 0) this->document.push_back(str);
        else this-> document.insert(this->document.begin() + this->CurrLine, str);
        this->CurrLine++;
    }
    cout << "new line:" << this->CurrLine+1 << endl;
}

void Document::addBefore(){
    string str = "";
    while(getline(cin,str)){
        if(str.compare(".") == 0) break;
        if(this->document.size() == 0) this->document.push_back(str);
        else this-> document.insert(this->document.begin() + this->CurrLine, str);
        this->CurrLine++;
    }
    cout << "new line:" << this->CurrLine+1 << endl;

}

void Document::search(string s){
    for(auto i = this->document.begin() +this->CurrLine ; i != this->document.end(); ++i){
        string str = *i;
        auto check = str.find(s);
        if(check != string::npos){
            cout << *i << endl;
            this->CurrLine = distance(this->document.begin(), i);
            cout << "new line:" << this->CurrLine+1 << endl;
            return;
        }
    }
    for(auto i = this->document.begin(); i != this->document.begin() + this->CurrLine; ++i){
        string str = *i;
        auto check = str.find(s);
        if(check != string::npos){
            cout << *i << endl;
            this->CurrLine = distance(this->document.begin(), i);
            cout << "new line:" << this->CurrLine+1 << endl;
            return;
        }
    }
    this->CurrLine = 1;
}

void Document::replaceTxt(string s){
    string old = s.substr(0,s.find("/"));
    cout << "old" << old << endl;
    string newOne = s.substr(s.find("/")+1, s.size() - 1);
    cout << "new" << newOne << endl;
    this->document.at(CurrLine).replace(this->document.at(CurrLine).find(old), old.size(), newOne); 
}

void Document::combine(){
    string s = "";
    document[CurrLine].append(document[CurrLine+1]);
    this->document.erase(this->document.begin() + this->CurrLine+1);
}

void Document::write(string fileName){
    std::ofstream outFile(fileName);
    for(const auto &e : document) outFile << e << endl;
}

void Document::changeCurr(){
    this->document.erase(this->document.begin() + this->CurrLine);
    addAfter();
    cout << "line:" << this->CurrLine +1 << endl;
}

void Document::deleteCurr(){
    this->document.erase(this->document.begin()-1 + this->CurrLine--);
        cout << "line:" << this->CurrLine +1 << endl;

}



