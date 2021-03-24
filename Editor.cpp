//
//Creates by Jessica Fliker 19/3/2021
//

#include "Editor.h"
#include <iostream>
#include <string>
using namespace std;

Editor::Editor(){}
Editor::Editor(string s):ed(s){}
Editor::~Editor(){}

void Editor::loop(){
    
    string str = "";
    
    while(getline(cin,str)){
        char c = str.at(0);
        switch(c){
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':{
                this->ed.changeCurrLine(stoi(str));
                break;
            }
            case '+':{
                this->ed.linesForwards(stoi(str.substr(1,str.size()-1)));
                break;
            }
            case '-':{
                this->ed.linesBackwards(stoi(str.substr(1,str.size()-1)));
                break;
            }
            case '$':{
                this->ed.last();
                break;
            }
            case 'a':{
                this->ed.addAfter();
                break;
            }
            case 'i':{
                this->ed.addBefore();
                break;
            }
            case 'c':{
                this->ed.changeCurr();
                break;
            }
            case 'd':{
                this->ed.deleteCurr();
                break;
            }
            case '/':{
                this->ed.search(str.substr(1,str.size()-2));
                break;
            }
            case 's':{
                this->ed.replaceTxt(str.substr(2,str.size()-3));
                break;
            }
            case 'j':{
                this->ed.combine();
                break;
            }
            case 'w':{
                this->ed.write(str.substr(2,str.size()-1));
                break;
            }
            case 'q': return;
        }
    }
    
}