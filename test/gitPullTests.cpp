#include <gtest/gtest.h>

#include <string>
using std::string;

#include "../src/git/gitPull.h"

TEST(GitPullTests, oneLine)
{
    GitPull olPull = GitPull();

    string output = "error: failed to pull!";
    EXPECT_THROW(olPull.checkForErrors(output), string*);

    output = "  error: failed to pull!";
    EXPECT_THROW(olPull.checkForErrors(output), string*);
}