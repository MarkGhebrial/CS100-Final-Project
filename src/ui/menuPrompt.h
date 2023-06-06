#ifndef _MENU_SELECTION_H_
#define _MENU_SELECTION_H_

#include <iostream>
#include <vector>

class MenuPrompt {
    private:
        std::vector<std::string> menuItems;

        const int xOffsetCols = 4;
        int yOffsetLines = 0;
        int row = 0;
        //helper function for select options that displays menu
        void printMenu();

    public:
        void setMenuOffset();
        MenuPrompt(std::vector<std::string> menuItems) { this->menuItems = menuItems; };

        /// Presents the menu to the user and returns their choices
        std::vector<std::string> presentPrompt(); 
};

#endif