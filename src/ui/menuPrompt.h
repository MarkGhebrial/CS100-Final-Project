#ifndef _MENU_SELECTION_H_
#define _MENU_SELECTION_H_

#include <iostream>
#include <vector>

enum SingleOrMultiSelection {
    SINGLE,
    MULTI
};

class MenuPrompt {
    private:
        std::vector<std::string> menuItems;
        std::string prompt;

        SingleOrMultiSelection selectionOption;
        const int xOffsetCols = 4;
        int yOffsetLines = 0;
        int row = 0;
        //helper function for select options that displays menu
        void printMenu();

    public:
        void setMenuOffset();
        MenuPrompt(std::string prompt, std::vector<std::string> menuItems, SingleOrMultiSelection selectionOption) {
            this->menuItems = menuItems;
            this->selectionOption = selectionOption;
            this->prompt = prompt;
        };

        /// Presents the menu to the user and returns their choices
        std::vector<std::string> presentPrompt(); 
};

#endif