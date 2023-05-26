#ifndef _MENU_SELECTION_H_
#define _MENU_SELECTION_H_

// #include "conio.h"
#include <iostream>
#include <vector>

using namespace std;

class Menu {
    private:
        const int yOffsetLines = 2;
        const int xOffsetCols = 4;
        int row = 0;
        //helper function for select options that displays menu
        void generateMenu(const vector <string>&);

    public:
        //modifies the bool vector that you pass in
        void selectOptions(const vector <string>&, vector <bool>&); 
};

#endif