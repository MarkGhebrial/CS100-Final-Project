// This file will only be included once (in main.cpp), so the functions can be defined inline

#include "ui/prompts.h"

void commitWizard() {}

void mergeWizard() {} // Not implementing due to lack of time

void branchWizard() {}

void checkoutWizard() {
    // vector <string> menuPrompts; // This is going to be the vector of file names that Charlie 
    // //is working on
    // if (menuPrompts.size() < 2) {
    //     cout << "There is no other branch to checkout to." << endl;
    // }

    // MenuPrompt menuObject(menuPrompts); // We create a menu object from the vector that we recieve

    // vector<string> userSelection = menuObject.presentPrompt();  // This will present the menu so user can select which branch they want to checkout to

    // for (auto s : userSelection) {
    //     cout << s << endl;              // This couts their selection to the terminal, used for testing
    // }
    
    // Call the menu function to display the branch that the user can select from

    // If the user selects more than one branch, throw exeption
    // Todo(if we have time), make a new menu that only takes one selection from the user

    // After the user selects the branch, the menu is going to return a string vector with that branch
        // cout << "You have selected " << <branchName> << " branch." << endl;
        // cout << "Do you want to checkout to this branch?" << endl;
    // Ask the user to confirm if they want to checkout to this branch

    // create new git checkout object
}

// Not implementing functions below due to lack of time

void discardWizard() {}

void revertWizard() {}

void resetWizard() {}

void ignoreWizard() {}