#include <gtest/gtest.h>
#include "../src/ui/stringPrompt.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//No input (empty string input, enter), return empty string
TEST (stringPromptTests, testNoInput) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("\n"); // This is what the user types

    StringPrompt prompt("This is a test string prompt");
    std::string result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test string prompt: ");
    EXPECT_EQ(result, "");
}

//Check if input is in effect
TEST (stringPromptTests, testSingleWordInput) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("MarkTheCSGod\n"); // This is what the user types

    StringPrompt prompt("This is a test string prompt");
    std::string result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test string prompt: ");
    EXPECT_EQ(result, "MarkTheCSGod");
}

//Check if input and getline is in effect
TEST (stringPromptTests, testMultipleWordsInput) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("Mark is THE CS god\n"); // This is what the user types

    StringPrompt prompt("This is a test string prompt");
    std::string result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test string prompt: ");
    EXPECT_EQ(result, "Mark is THE CS god");
}
