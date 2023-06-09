#include "ui/menuPrompt.h"
#include <iostream>
#include <vector>

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
  
    MenuPrompt menuObject("Select and item:", menuPrompts, SINGLE);

    vector<string> userSelection = menuObject.presentPrompt();

    for (auto s : userSelection) {
        cout << s << endl;
    }

    return 0;
}