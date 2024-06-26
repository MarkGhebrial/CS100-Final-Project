#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "../src/ui/YesOrNoPrompt.h"

using namespace std;

TEST (YesOrNoPromptTests, testYes) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("yes\n"); // This is what the user types

    YesOrNoPrompt prompt("This is a test prompt", YesOrNo::YES);
    YesOrNo result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test prompt (Y/n): "); // Check that it printed the right thing
    EXPECT_EQ(result, YesOrNo::YES); // Check that it returned the right thing
}

TEST (YesOrNoPromptTests, testNo) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("no\n"); // This is what the user types

    YesOrNoPrompt prompt("This is a test prompt", YesOrNo::NO);
    YesOrNo result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test prompt (y/N): "); // Check that it printed the right thing
    EXPECT_EQ(result, YesOrNo::NO); // Check that it returned the right thing
}

// Check that the user is prompted again if they enter invalid input
TEST (YesOrNoPromptTests, testInvalidInput) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("dfjsafdsa\ny\n"); // This is what the user types

    YesOrNoPrompt prompt("This is a test prompt", YesOrNo::NO);
    YesOrNo result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test prompt (y/N): Invalid input\nThis is a test prompt (y/N): ");
    EXPECT_EQ(result, YesOrNo::YES);
}

TEST (YesOrNoPromptTests, testDefaultYes) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("\n"); // This is what the user types

    YesOrNoPrompt prompt("This is a test prompt", YesOrNo::YES);
    YesOrNo result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test prompt (Y/n): ");
    EXPECT_EQ(result, YesOrNo::YES);
}

TEST (YesOrNoPromptTests, testDefaultNo) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("\n"); // This is what the user types

    YesOrNoPrompt prompt("This is a test prompt", YesOrNo::NO);
    YesOrNo result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test prompt (y/N): ");
    EXPECT_EQ(result, YesOrNo::NO);
}