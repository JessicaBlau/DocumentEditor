//
// Crested by Jessica Fliker 3/19/2021
//

#pragma once 
#include <vector>
#include <string>


using namespace std;

class Document{
    private:
        vector<string> document;
        int CurrLine;
    public:
        Document();
        Document(string);
        ~Document();

        void changeCurrLine(int);// example 3
        void linesForwards(int);// example +2
        void linesBackwards(int);// example -2
        void last();// example $
        void addAfter();// example a
        void addBefore();// example i
        void changeCurr();// example c
        void deleteCurr();// example d
        void search(string);// example /txt/
        void replaceTxt(string);// example s/oldtxt/newtxt
        void combine();// example j
        void write(string);// w file
};