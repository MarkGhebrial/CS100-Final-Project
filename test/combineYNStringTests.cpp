#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../src/ui/stringPrompt.h"
#include "../src/ui/combineYNString.h"

using namespace std;

///Scenarios Tests
//Created Branch : YES : Enter Branch Name : String
//Enter commit message : String : Sync changes with remote : YES

/*
TEST (stringPromptTests, testSingleWordInput) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("MarkTheCSGod\n"); // This is what the user types

    StringPrompt prompt("This is a test string prompt");
    std::string result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test string prompt: ");
    EXPECT_EQ(result, "MarkTheCSGod");
}

TEST (YesOrNoPromptTests, testYes) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("yes\n"); // This is what the user types

    YesOrNoPrompt prompt("This is a test prompt", YesOrNo::YES);
    YesOrNo result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test prompt (Y/n): "); // Check that it printed the right thing
    EXPECT_EQ(result, YesOrNo::YES); // Check that it returned the right thing
}
*/