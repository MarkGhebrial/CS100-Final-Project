#include "conio.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    //User passes in a vector and I return a menu that will provide all the choices that the user chooses
    vector <string> menuPrompts;
   
    int xPosition = 0;
    int yPosition = 0;

    menuPrompts.push_back("Prompt 1");
    menuPrompts.push_back("Prompt 2");
    menuPrompts.push_back("Prompt 3");
    menuPrompts.push_back("Prompt 4");

    vector <bool> userSelection(menuPrompts.size());

    clrscr();
    cout << "Menu prompt:" << endl;

//What should it do if I get sent an empty vector
//What should it do if I get sent a vector of a different type

    for (int i = 0; i < menuPrompts.size(); i++) {
        cout << "  [ ] " << menuPrompts.at(i) << endl;
    }
 
    gotoxy(4,2);
    char input = getch();

    //This function checks the user input to see if they enter space or enter
    //If the hit space, we will check the box, if they hit enter, we exit the program
    while (input != 10) {
        if (input == 65) {
            xPosition = wherex();
            yPosition = wherey();
            if (yPosition > 2) {
                gotoxy(xPosition, yPosition - 1);
            }
        }
        else if (input == 66) {
            xPosition = wherex();
            yPosition = wherey();
            if (yPosition <= menuPrompts.size()) {
                gotoxy(xPosition, yPosition + 1);
            }
        }

        if (input == 32) { //space
            yPosition = wherey();
            if (userSelection.at(yPosition - 2) == false) {
                userSelection.at(yPosition - 2) = true;
                cout << "X";
            }
            else {
                userSelection.at(yPosition - 2) = false;
                cout << " ";
            }
            
            gotoxy(4,yPosition);       
        }
        input = getch();
    }
    clrscr();

    for (int i = 0; i < userSelection.size(); i++) {
        cout << userSelection.at(i) << endl;
    }

    return 0;
}