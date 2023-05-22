#include <gtest/gtest.h>
#include <string>
#include <fstream>

#include "../src/ui/YesOrNoPrompt.h"

using namespace std;

TEST (YesOrNoPromptTests, testIO) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("yes\n"); // This is what the user types

    YesOrNoPrompt prompt("This is a test prompt", YesOrNo::YES);
    YyeOrNo result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test prompt (Y/n): "); // Check that it printed the right thing
    EXPECT_EQ(result, YesOrNo::YES); // Check that it returned the right thing
}

TEST (YesOrNoPromptTests, testIO) {
    ostringstream out; // This will hold what the prompt prints
    istringstream in("no\n"); // This is what the user types

    YesOrNoPrompt prompt("This is a test prompt", YesOrNo::NO);
    YyeOrNo result = prompt.presentPrompt(out, in);

    EXPECT_EQ(out.str(), "This is a test prompt (Y/n): "); // Check that it printed the right thing
    EXPECT_EQ(result, YesOrNo::NO); // Check that it returned the right thing
}

TEST (YesOrNoPromptTests, testIO) {
    ostringstream out; // This will hold what the prompt prints
    string messageNotYesOrNot;
    istringstream in(messageNotYesOrNot); // This is what the user types
    if (messageNotYesOrNot != "yes\n" || messageNotYesOrNot != "no\n"){
        EXPECT_EQ(out.str(), "Invalid input"); // Check that it printed the right thing
    }
}