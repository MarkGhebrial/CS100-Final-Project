#include "conio.h"
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

void Menu::generateMenu(const vector <string>& menuPrompts){
    clrscr();
    cout << "Menu prompt:" << endl;

    for (int i = 0; i < menuPrompts.size(); i++) {
        cout << "  [ ] " << menuPrompts.at(i) << endl;
    }

    //Sets user cursor inside []
    gotoxy(xOffsetCols,yOffsetLines);

    //Should I list out how to use the menu in the terminal like movement with arrows, 
    //selection with space and enter to quit the program
}

void Menu::selectOptions(const vector <string> &menuPrompts, vector <bool>& userSelection){
    generateMenu(menuPrompts);
    char input = getch();
    while (input != 10) {
        if (input == 65) {   // move cursor up with up arrow
            row -= 1;
            if (row < 0) {
                row = 0;
            }
            gotoxy(xOffsetCols,row + yOffsetLines);
        }
        else if (input == 66) {     // move cursor down with down arrow
            row += 1;
            if (row > menuPrompts.size() - 1) {
                row = menuPrompts.size() - 1;
            }
            gotoxy(xOffsetCols,row + yOffsetLines);
        }
        else if (input == 32) { // user selection with space
            if (userSelection.at(row) == false) {
                userSelection.at(row) = true;
                cout << "X";
            }
            else {
                userSelection.at(row) = false;
                cout << " ";
            }
            gotoxy(xOffsetCols,row + yOffsetLines);       
        }
        input = getch();
    }
    clrscr();
}


 
    
    