#include <gtest/gtest.h>
#include "../src/ui/stringPrompt.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

TEST (stringPromptTests, testInputTillNewlineEntered) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("MarkTheCSGod\n"); // This is what the user types

    StringPrompt prompt("This is a test string prompt");
    std::string result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test string prompt: ");
    EXPECT_EQ(in.str(), "MarkTheCSGod\n");
    EXPECT_EQ(result, "This is a test string prompt: MarkTheCSGod\n");
}
