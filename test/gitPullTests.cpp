#include <gtest/gtest.h>

#include <string>
using std::string;

#include "../src/git/gitPull.h"

TEST(GitPullTests, oneLine)
{
    GitPull olPull = GitPull();

    string output = "error";
    EXPECT_THROW(olPull.checkForErrors(output), std::exception);

    output = "fatal";
    EXPECT_THROW(olPull.checkForErrors(output), std::exception);
}