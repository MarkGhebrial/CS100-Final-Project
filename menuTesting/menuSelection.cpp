#include "conio.h"
#include <iostream>
#include <vector>

using namespace std;

class Menu {
    private:

    public:
     //User passes in a vector of prompts and it creates a menu
    generateMenu(vector <string>); 

};

Menu::generateMenu(vector <string> menuPrompts){
    clrscr();
    cout << "Menu prompt:" << endl;

//What should it do if it get sent an empty vector?
//What should it do if it get sent a vector of a different type?

    for (int i = 0; i < menuPrompts.size(); i++) {
        cout << "  [ ] " << menuPrompts.at(i) << endl;
    }
    //Sets user cursor inside []
    gotoxy(4,2);
}


   


 
    
    char input = getch();

    //This function checks the user input to see if they enter space or enter
    //If the hit space, we will check the box, if they hit enter, we exit the program
    while (input != 10) {
        if (input == 32) { //space
            wherey()
            //If it is already selected, deselect it
            if () {
                
            }


            cursorLocY = wherey();
            cout << "X";
            gotoxy(4,cursorLocY);
        //needs to be modified since it moves cursor one to right
        }
        input = getch();
    }
    clrscr();
