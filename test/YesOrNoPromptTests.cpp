#include <gtest/gtest.h>
#include <string>
#include <fstream>

#include "../src/ui/YesOrNoPrompt.h"

using namespace std;

TEST (YesOrNoPromptTests, inputY){
    istream gitInput = "Y";
    YesOrNo parsedResult(gitInput);
    EXPECT_EQ(parsedResult.presentPrompt(), "YES");
}

TEST (YesOrNoPromptTests, inputN){
    string gitOutput = "N";
    YesOrNo parsedResult(gitOutput);
    EXPECT_EQ(parsedResult.presentPrompt(), "NO");
}

TEST (YesOrNoPromptTests, inputNotYN){
    string gitOutput = "a";
    YesOrNo parsedResult(gitOutput);
    EXPECT_EQ(parsedResult.presentPrompt(), "Invalid input");
}

//YesOrNo ... (out / in), fstream