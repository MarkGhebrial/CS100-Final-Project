#include <gtest/gtest.h>
#include "../src/stringPrompt/stringPrompt.h"
#include <string>
#include <fstream>
using namespace std;

TEST (stringPromptTests, testInputTillNewline) {
    ostringstream out; // This will hold what the prompt prints
    string message;
    istringstream in(message); // This is what the user types
    out << message;
    EXPECT_EQ(out.str(), message); // Check that it printed the right thing
}

TEST (stringPromptTests, testInputNewlineOnly) {
    ostringstream out; // This will hold what the prompt prints
    string message = "\n";
    istringstream in(message); // This is what the user types
    out << message;
    EXPECT_EQ(out.str(), ""); // Check that it printed the right thing
}