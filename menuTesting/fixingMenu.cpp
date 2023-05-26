#include "conio.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    //User passes in a vector and it returns a menu that will provide all the choices that the user chooses
    vector <string> menuPrompts;
    int row = 0;

    menuPrompts.push_back("Prompt 1");
    menuPrompts.push_back("Prompt 2");
    menuPrompts.push_back("Prompt 3");
    menuPrompts.push_back("Prompt 4");
    menuPrompts.push_back("Prompt 5");
    menuPrompts.push_back("Prompt 6");
    menuPrompts.push_back("Prompt 7");
    menuPrompts.push_back("Prompt 8");
    
    vector <bool> userSelection(menuPrompts.size());

    clrscr();
    cout << "Menu prompt:" << endl;
    const int yOffsetLines = 2;
    const int xOffsetCols = 4;

//What should it do if I get sent an empty vector
//What should it do if I get sent a vector of a different type

    for (int i = 0; i < menuPrompts.size(); i++) {
        cout << "  [ ] " << menuPrompts.at(i) << endl;
    }
 
    gotoxy(xOffsetCols,yOffsetLines);
    char input = getch();

    //This function checks the user input to see if they enter space or enter
    //If the hit space, we will check the box, if they hit enter, we exit the program
    while (input != 10) {
        if (input == 65) {      //up
            row -= 1;
            if (row < 0) {
                row = 0;
            }
            gotoxy(xOffsetCols,row + yOffsetLines);
        }
        else if (input == 66) {     //down
            row += 1;
            if (row > menuPrompts.size() - 1) {
                row = menuPrompts.size() - 1;
            }
            gotoxy(xOffsetCols,row + yOffsetLines);
        }
        else if (input == 32) { //space
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

    vector <string> menuSelectionResult;

    for (int i = 0; i < menuPrompts.size(); i++) {
        if (userSelection.at(i) == true) {
            menuSelectionResult.push_back(menuPrompts.at(i));
        }
    }

    for (int i = 0; i < menuSelectionResult.size(); i++) {
        cout << menuSelectionResult.at(i) << endl;
    }

    return 0;
}