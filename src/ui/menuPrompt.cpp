#include "menuPrompt.h"

#include "conio.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void MenuPrompt::printMenu(){
    clrscr();
    cout << "Menu prompt:" << endl;

    for (int i = 0; i < menuItems.size(); i++) {
        cout << "  [ ] " << menuItems.at(i) << endl;
    }

    //Sets user cursor inside []
    gotoxy(xOffsetCols,yOffsetLines);

    //Should I list out how to use the menu in the terminal like movement with arrows, 
    //selection with space and enter to quit the program
}

vector<string> MenuPrompt::presentPrompt(){
    printMenu();

    vector<bool> userSelection(menuItems.size());

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
            if (row > menuItems.size() - 1) {
                row = menuItems.size() - 1;
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

    assert(userSelection.size() == menuItems.size());

    vector<string> out;
    // Append all selected items to the return vector
    for (int i = 0; i < menuItems.size(); ++i) {
        if (userSelection.at(i)) {
            out.push_back(menuItems.at(i));
        }
    }

    return out;
}
