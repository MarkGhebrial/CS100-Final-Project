#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../src/ui/stringPrompt.h"
#include "../src/ui/YesOrNoPrompt.h"

using namespace std;

//Descriptions of combineYNStringTests.cpp -
///// Two main Scenarios -
////    1. Create Branch / Branch Name  
////    2. Enter commit message / Sync changes with remote
///// Variables - YES/NO from YesOrNoPrompt; String/Empty String from StringPrompt
///    Two variables Tests -
//      1. Created Branch : YES :: Enter Branch Name : String
//      2. Enter commit message : String :: Sync changes with remote : YES
///    Three variables Tests -
//      1. Created Branch : YES :: Enter Branch Name : String :: Sync changes with remote : YES


///Scenario Test 1
//Created Branch : NO :X: Enter Branch Name : String
//Check if YesOrNoPrompt is in effect in combineYNStringTests.cpp
//and doesn't proceed to the *next part with second input.
//* Next part - Enter Branch Name : String
TEST (combineYNStringTests, ScenarioTest1) {
    //Created Branch : NO
    ostringstream out;
    istringstream in("no\nMarkTheCSGod\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::NO);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (y/N): ");
    EXPECT_EQ(result1, YesOrNo::NO);
}

///Scenario Test 2
//Created Branch : NO :X: Enter Branch Name : Empty String
//Check if YesOrNoPrompt is in effect in combineYNStringTests.cpp
//and doesn't proceed to the *next part with second input.
//* Next part - Enter Branch Name : Empty String
//Empty String - The user entered an enter as the second input
TEST (combineYNStringTests, ScenarioTest2) {
    //Created Branch : NO
    ostringstream out;
    istringstream in("no\n\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::NO);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (y/N): ");
    EXPECT_EQ(result1, YesOrNo::NO);
}

///Scenario Test 3
//Created Branch : YES :: Enter Branch Name : String
TEST (combineYNStringTests, ScenarioTest3) {
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

///Scenario Test 4
//Created Branch : YES :: Enter Branch Name : Empty String 
//Empty String - The user entered an enter as the second input
TEST (combineYNStringTests, ScenarioTest4) {
    //Created Branch : YES
    ostringstream out;
    istringstream in("yes\n\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::YES);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): ");
    EXPECT_EQ(result1, YesOrNo::YES);

    //Enter Branch Name : Empty String                                        
    StringPrompt prompt2("Enter Branch Name: ");
    std::string result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : ");
    EXPECT_EQ(result2, "");
}

///Scenario Test 5
//Enter commit message : String :: Sync changes with remote : YES
TEST (combineYNStringTests, ScenarioTest5) {
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

///Scenario Test 6
//Enter commit message : Empty String :: Sync changes with remote : YES
//Empty String - The user entered an enter as the first input
TEST (combineYNStringTests, ScenarioTest6) {
    //Enter commit message : Empty String
    ostringstream out;          
    istringstream in("\nyes\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "");  

    //Sync changes with remote : YES 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::YES);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): ");
    EXPECT_EQ(result2, YesOrNo::YES);
}

///Scenario Test 7
//Enter commit message : String :: Sync changes with remote : NO
TEST (combineYNStringTests, ScenarioTest7) {
    //Enter commit message : String
    ostringstream out;          
    istringstream in("MarkTheCSGod\nno\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "MarkTheCSGod");  

    //Sync changes with remote : NO 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result2, YesOrNo::NO);
}

///Scenario Test 8
//Enter commit message : Empty String :: Sync changes with remote : NO
//Empty String - The user entered an enter as the first input
TEST (combineYNStringTests, ScenarioTest8) {
    //Enter commit message : Empty String
    ostringstream out;          
    istringstream in("\nno\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "");  

    //Sync changes with remote : NO 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result2, YesOrNo::NO);
}

/*****
/////Adding a third variable of the scenarios to test
*****/

///Scenario Test 9
//Created Branch : YES :: Enter Branch Name : String :: Sync changes with remote : YES
TEST (combineYNStringTests, ScenarioTest9) {
    //Created Branch : YES
    ostringstream out;
    istringstream in("yes\nMarkIsBeingModest\nyes\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::YES);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): ");
    EXPECT_EQ(result1, YesOrNo::YES);

    //Enter Branch Name : String                                        
    StringPrompt prompt2("Enter Branch Name: ");
    std::string result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : ");
    EXPECT_EQ(result2, "MarkIsBeingModest");

    //Sync changes with remote : YES 
    YesOrNoPrompt prompt3("Sync changes with remote?", YesOrNo::YES);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : Sync changes with remote? (Y/n): ");
    EXPECT_EQ(result3, YesOrNo::YES);
}


///Scenario Test 10
//Created Branch : YES :: Enter Branch Name : Empty String :: Sync changes with remote : YES
//Empty String - The user entered an enter as the second input
TEST (combineYNStringTests, ScenarioTest10) {
    //Created Branch : YES
    ostringstream out;
    istringstream in("yes\n\nyes\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::YES);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): ");
    EXPECT_EQ(result1, YesOrNo::YES);

    //Enter Branch Name : Empty String                                        
    StringPrompt prompt2("Enter Branch Name: ");
    std::string result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : ");
    EXPECT_EQ(result2, "");

    //Sync changes with remote : YES 
    YesOrNoPrompt prompt3("Sync changes with remote?", YesOrNo::YES);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : Sync changes with remote? (Y/n): ");
    EXPECT_EQ(result3, YesOrNo::YES);
}

///Scenario Test 11
//Created Branch : YES :: Enter Branch Name : String :: Sync changes with remote : NO
TEST (combineYNStringTests, ScenarioTest11) {
    //Created Branch : YES
    ostringstream out;
    istringstream in("yes\nMarkIsBeingModest\nno\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::YES);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): ");
    EXPECT_EQ(result1, YesOrNo::YES);

    //Enter Branch Name : String                                        
    StringPrompt prompt2("Enter Branch Name: ");
    std::string result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : ");
    EXPECT_EQ(result2, "MarkIsBeingModest");

    //Sync changes with remote : NO 
    YesOrNoPrompt prompt3("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result3, YesOrNo::NO);
}


///Scenario Test 12
//Created Branch : YES :: Enter Branch Name : Empty String :: Sync changes with remote : NO
//Empty String - The user entered an enter as the second input
TEST (combineYNStringTests, ScenarioTest12) {
    //Created Branch : YES
    ostringstream out;
    istringstream in("yes\n\nno\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::YES);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): ");
    EXPECT_EQ(result1, YesOrNo::YES);

    //Enter Branch Name : String                                        
    StringPrompt prompt2("Enter Branch Name: ");
    std::string result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : ");
    EXPECT_EQ(result2, "");

    //Sync changes with remote : NO 
    YesOrNoPrompt prompt3("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (Y/n): Enter Branch Name: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result3, YesOrNo::NO);
}
