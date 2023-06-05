#include <gtest/gtest.h>

#include <string>
using std::string;

#include "../src/git/gitPush.h"

TEST(GitPushTests, oneLine)
{
    GitPush olPush = GitPush();

    string output = "   error   File failed to push";
    EXPECT_THROW(olPush.checkForErrors(output), string*);

    output = " fatal: File failed to push !";
    EXPECT_THROW(olPush.checkForErrors(output), string*);
}

TEST(GitPushTests, multiline)
{
    GitPush mlPush = GitPush();

    string output = " fatal      master -> master (fetch first)\n error: failed to push some refs to 'https://github.com/YUGGUG/NEW-CODE.git'";
    EXPECT_THROW(mlPush.checkForErrors(output), string*);
}