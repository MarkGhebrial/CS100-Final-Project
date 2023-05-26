#include "menuSelection.h"
#include <iostream>
#include <vector>
// #include "menuSelection.cpp"

using namespace std;

int main(){
    vector <string> menuPrompts;

    menuPrompts.push_back("Prompt 1");
    menuPrompts.push_back("Prompt 2");
    menuPrompts.push_back("Prompt 3");
    menuPrompts.push_back("Prompt 4");
    menuPrompts.push_back("Prompt 5");
    menuPrompts.push_back("Prompt 6");
    menuPrompts.push_back("Prompt 7");
    menuPrompts.push_back("Prompt 8");

    vector <bool> userSelection(menuPrompts.size());

    Menu menuObject;

    menuObject.selectOptions(menuPrompts, userSelection);

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