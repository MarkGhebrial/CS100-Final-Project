#include <gtest/gtest.h>
#include "../src/ui/stringPrompt.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

TEST (stringPromptTests, testInputTillNewlineEntered) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("Mark is not a CS god\n"); // This is what the user types

    StringPrompt prompt("This is a test string prompt");
    std::string result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test string prompt: ");
    EXPECT_EQ(result, "Mark is not a CS god");
}
