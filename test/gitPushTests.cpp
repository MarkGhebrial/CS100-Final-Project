#include <gtest/gtest.h>

#include <string>
using std::string;

#include "../src/git/gitPush.h"
#include "../src/git/gitError.h"

TEST(GitPushTests, oneLine)
{
    GitPush olPush = GitPush();

    string output = "error";
    EXPECT_THROW(olPush.checkForErrors(output), std::exception);

    output = "fatal";
    EXPECT_THROW(olPush.checkForErrors(output), std::exception);
}

TEST(GitPushTests, multiline)
{
    GitPush mlPush = GitPush();

    string output = "\nfatal";
    EXPECT_THROW(mlPush.checkForErrors(output), std::exception);
}