#include "Editor.h"
#include <iostream>

int main(int argc, char* argv[]){
    switch(argc){
        case 1:{
            Editor editor;
            editor.loop();
            return 0;
        }
        case 2:{
            Editor editor(argv[1]);
            editor.loop();
            return 0;
        }
    }
}