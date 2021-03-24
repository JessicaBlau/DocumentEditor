//
// Created by Jessica Fliker 3/19/2021
//

#pragma once
#include "Document.h"
#include <string>

class Editor{
    private:
        Document ed;
    public:
        Editor();
        Editor(string);
        ~Editor();
        void loop();
};