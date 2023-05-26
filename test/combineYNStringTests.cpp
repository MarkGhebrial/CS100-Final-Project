#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../src/ui/stringPrompt.h"
#include "../src/ui/YesOrNoPrompt.h"

using namespace std;

///Scenarios Tests
//Created Branch : YES :: Enter Branch Name : String
//Enter commit message : String :: Sync changes with remote : YES

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

///Scenario Test 1
//Created Branch : YES :: Enter Branch Name : String
TEST (combineYNStringTests, ScenarioTest1) {
    //Created Branch : YES
    ostringstream out;
    istringstream in("yes\nMarkTheCSGod\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::YES);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): ");
    EXPECT_EQ(result1, YesOrNo::YES);

    //Enter Branch Name : String                                        
    StringPrompt prompt2("Enter Branch Name: ");
    std::string result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : ");
    EXPECT_EQ(result2, "MarkTheCSGod");
}

///Scenario Test 2
//Enter commit message : String :: Sync changes with remote : YES
TEST (combineYNStringTests, ScenarioTest2) {
    //Enter commit message : String
    ostringstream out;          
    istringstream in("MarkTheCSGod\nyes\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "MarkTheCSGod");  

    //Sync changes with remote : YES 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::YES);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): ");
    EXPECT_EQ(result2, YesOrNo::YES);
}