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
//      2. Enter commit message : String :: Sync changes with remote : YES :: Apply changes : YES
//          (a. No sync, No apply; b. No sync, Yes apply, still allow applying)


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

    //Enter Branch Name : Empty String                                        
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

///Scenario Test 13
//Created Branch : NO :: Enter Branch Name : String :: Sync changes with remote : YES
//Since the branch is not created, it doesn't proceed to the next part.
//* Next part - Enter Branch Name : String :: Sync changes with remote : YES
TEST (combineYNStringTests, ScenarioTest13) {
    //Created Branch : NO
    ostringstream out;
    istringstream in("no\nMarkTheCSGod\nyes\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::NO);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (y/N): ");
    EXPECT_EQ(result1, YesOrNo::NO);
}

///Scenario Test 14
//Created Branch : NO :: Enter Branch Name : Empty String :: Sync changes with remote : YES
//Empty String - The user entered an enter as the second input
//Since the branch is not created, it doesn't proceed to the next part.
//* Next part - Enter Branch Name : String :: Sync changes with remote : YES
TEST (combineYNStringTests, ScenarioTest14) {
    //Created Branch : NO
    ostringstream out;
    istringstream in("no\n\nyes\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::NO);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (y/N): ");
    EXPECT_EQ(result1, YesOrNo::NO);
}

///Scenario Test 15
//Created Branch : NO :: Enter Branch Name : String :: Sync changes with remote : NO
//Since the branch is not created, it doesn't proceed to the next part.
//* Next part - Enter Branch Name : String :: Sync changes with remote : NO
TEST (combineYNStringTests, ScenarioTest15) {
    //Created Branch : NO
    ostringstream out;
    istringstream in("no\nMarkTheCSGod\nno\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::NO);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (y/N): ");
    EXPECT_EQ(result1, YesOrNo::NO);
}

///Scenario Test 16
//Created Branch : NO :: Enter Branch Name : Empty String :: Sync changes with remote : NO
//Empty String - The user entered an enter as the second input
//Since the branch is not created, it doesn't proceed to the next part.
//* Next part - Enter Branch Name : String :: Sync changes with remote : NO
TEST (combineYNStringTests, ScenarioTest16) {
    //Created Branch : NO
    ostringstream out;
    istringstream in("no\n\nno\n");

    YesOrNoPrompt prompt1("Create Branch?", YesOrNo::NO);
    YesOrNo result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Create Branch? (y/N): ");
    EXPECT_EQ(result1, YesOrNo::NO);
}

///Scenario Test 17
//Enter commit message : String :: Sync changes with remote : YES :: Apply changes : YES
TEST (combineYNStringTests, ScenarioTest17) {
    //Enter commit message : String
    ostringstream out;          
    istringstream in("ModestMark\nyes\nyes\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "ModestMark");  

    //Sync changes with remote : YES 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::YES);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): ");
    EXPECT_EQ(result2, YesOrNo::YES);

    //Apply changes : YES
    YesOrNoPrompt prompt3("Apply changes?", YesOrNo::YES);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): Apply changes? (Y/n): ");
    EXPECT_EQ(result3, YesOrNo::YES);
}

///Scenario Test 18
//Enter commit message : Empty String :: Sync changes with remote : YES :: Apply changes : YES
//Empty String - The user entered an enter as the first input
TEST (combineYNStringTests, ScenarioTest18) {
    //Enter commit message : Empty String
    ostringstream out;          
    istringstream in("\nyes\nyes\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "");  

    //Sync changes with remote : YES 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::YES);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): ");
    EXPECT_EQ(result2, YesOrNo::YES);

    //Apply changes : YES
    YesOrNoPrompt prompt3("Apply changes?", YesOrNo::YES);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): Apply changes? (Y/n): ");
    EXPECT_EQ(result3, YesOrNo::YES);
}

///Scenario Test 19
//Enter commit message : String :: Sync changes with remote : NO :: Apply changes : YES
//Testing a. (a. No sync, No apply; b. No sync, Yes apply, still allow applying)
TEST (combineYNStringTests, ScenarioTest19) {
    //Enter commit message : String
    ostringstream out;          
    istringstream in("ModestMark\nno\nyes\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "ModestMark");  

    //Sync changes with remote : NO
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result2, YesOrNo::NO);
}

///Scenario Test 20
//Enter commit message : Empty String :: Sync changes with remote : NO :: Apply changes : YES
//Testing a. (a. No sync, No apply; b. No sync, Yes apply, still allow applying)
//Empty String - The user entered an enter as the first input
TEST (combineYNStringTests, ScenarioTest20) {
    //Enter commit message : Empty String
    ostringstream out;          
    istringstream in("\nno\nyes\n");                  

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

///Scenario Test 21
//Enter commit message : String :: Sync changes with remote : NO :: Apply changes : NO
//Testing a. (a. No sync, No apply; b. No sync, Yes apply, still allow applying)
TEST (combineYNStringTests, ScenarioTest21) {
    //Enter commit message : String
    ostringstream out;          
    istringstream in("ModestMark\nno\nno\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "ModestMark");  

    //Sync changes with remote : NO
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result2, YesOrNo::NO);
}

///Scenario Test 22
//Enter commit message : Empty String :: Sync changes with remote : NO :: Apply changes : NO
//Testing a. (a. No sync, No apply; b. No sync, Yes apply, still allow applying)
//Empty String - The user entered an enter as the first input
TEST (combineYNStringTests, ScenarioTest22) {
    //Enter commit message : Empty String
    ostringstream out;          
    istringstream in("\nno\nno\n");                  

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

///Scenario Test 23
//Enter commit message : String :: Sync changes with remote : NO :: Apply changes : YES
//Testing b. (a. No sync, No apply; b. No sync, Yes apply, still allow applying)
TEST (combineYNStringTests, ScenarioTest23) {
    //Enter commit message : String
    ostringstream out;          
    istringstream in("ModestMark\nno\nyes\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "ModestMark");  

    //Sync changes with remote : NO 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result2, YesOrNo::NO);

    //Apply changes : YES
    YesOrNoPrompt prompt3("Apply changes?", YesOrNo::YES);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): Apply changes? (Y/n): ");
    EXPECT_EQ(result3, YesOrNo::YES);
}

///Scenario Test 24
//Enter commit message : Empty String :: Sync changes with remote : NO :: Apply changes : YES
//Testing b. (a. No sync, No apply; b. No sync, Yes apply, still allow applying)
//Empty String - The user entered an enter as the first input
TEST (combineYNStringTests, ScenarioTest24) {
    //Enter commit message : Empty String
    ostringstream out;          
    istringstream in("\nno\nyes\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "");  

    //Sync changes with remote : NO 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result2, YesOrNo::NO);

    //Apply changes : YES
    YesOrNoPrompt prompt3("Apply changes?", YesOrNo::YES);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): Apply changes? (Y/n): ");
    EXPECT_EQ(result3, YesOrNo::YES);
}

///Scenario Test 25
//Enter commit message : String :: Sync changes with remote : NO :: Apply changes : NO
//Testing b. (a. No sync, No apply; b. No sync, Yes apply, still allow applying)
TEST (combineYNStringTests, ScenarioTest25) {
    //Enter commit message : String
    ostringstream out;          
    istringstream in("ModestMark\nno\nno\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "ModestMark");  

    //Sync changes with remote : NO 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result2, YesOrNo::NO);

    //Apply changes : NO
    YesOrNoPrompt prompt3("Apply changes?", YesOrNo::NO);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): Apply changes? (y/N): ");
    EXPECT_EQ(result3, YesOrNo::NO);
}

///Scenario Test 26
//Enter commit message : Empty String :: Sync changes with remote : NO :: Apply changes : NO
//Testing b. (a. No sync, No apply; b. No sync, Yes apply, still allow applying)
//Empty String - The user entered an enter as the first input
TEST (combineYNStringTests, ScenarioTest26) {
    //Enter commit message : Empty String
    ostringstream out;          
    istringstream in("\nno\nno\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "");  

    //Sync changes with remote : NO 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::NO);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): ");
    EXPECT_EQ(result2, YesOrNo::NO);

    //Apply changes : YES
    YesOrNoPrompt prompt3("Apply changes?", YesOrNo::NO);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (y/N): Apply changes? (y/N): ");
    EXPECT_EQ(result3, YesOrNo::NO);
}

///Scenario Test 27
//Enter commit message : String :: Sync changes with remote : YES :: Apply changes : NO
TEST (combineYNStringTests, ScenarioTest27) {
    //Enter commit message : String
    ostringstream out;          
    istringstream in("ModestMark\nyes\nno\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "ModestMark");  

    //Sync changes with remote : YES 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::YES);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): ");
    EXPECT_EQ(result2, YesOrNo::YES);

    //Apply changes : NO
    YesOrNoPrompt prompt3("Apply changes?", YesOrNo::NO);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): Apply changes? (y/N): ");
    EXPECT_EQ(result3, YesOrNo::NO);
}

///Scenario Test 28
//Enter commit message : Empty String :: Sync changes with remote : YES :: Apply changes : NO
//Empty String - The user entered an enter as the first input
TEST (combineYNStringTests, ScenarioTest28) {
    //Enter commit message : Empty String
    ostringstream out;          
    istringstream in("\nyes\nno\n");                  

    StringPrompt prompt1("Enter commit message: ");
    std::string result1 = prompt1.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : ");
    EXPECT_EQ(result1, "");  

    //Sync changes with remote : YES 
    YesOrNoPrompt prompt2("Sync changes with remote?", YesOrNo::YES);
    YesOrNo result2 = prompt2.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): ");
    EXPECT_EQ(result2, YesOrNo::YES);

    //Apply changes : NO
    YesOrNoPrompt prompt3("Apply changes?", YesOrNo::NO);
    YesOrNo result3 = prompt3.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "Enter commit message: : Sync changes with remote? (Y/n): Apply changes? (y/N): ");
    EXPECT_EQ(result3, YesOrNo::NO);
}
