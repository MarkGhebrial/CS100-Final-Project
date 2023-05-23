#include <gtest/gtest.h>
#include <string>
#include <fstream>

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

    EXPECT_EQ(out.str(), "This is a test prompt (Y/n): "); // Check that it printed the right thing
    EXPECT_EQ(result, YesOrNo::NO); // Check that it returned the right thing
}

TEST (YesOrNoPromptTests, testInvalid) {
    ostringstream out; // This will hold what the prompt prints
    string messageNotYesOrNot;
    istringstream in(messageNotYesOrNot); // This is what the user types
    out << messageNotYesOrNot;
    if (messageNotYesOrNot != "yes\n" || messageNotYesOrNot != "no\n"){
        EXPECT_EQ(out.str(), "Invalid input"); // Check that it printed the right thing
    }
}
