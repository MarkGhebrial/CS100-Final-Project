#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../src/ui/stringPrompt.h"
#include "../src/ui/combineYNString.h"

using namespace std;

TEST (combineYNStringTests, branchName) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("MarkTheCSGod\n"); // This is what the user types

    StringPrompt prompt("This is a test string prompt");
    std::string result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test string prompt: ");
    EXPECT_EQ(result, "MarkTheCSGod");
}
