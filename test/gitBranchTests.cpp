#include <gtest/gtest.h>

#include <string>
#include <vector>
using std::string;

#include "../src/git/gitDeleteBranch.h"
#include "../src/git/gitListBranches.h"
#include "../src/git/gitNewBranch.h"

/// Tests that a branch can be created and deleted
TEST(GitBranchTests, branchProcess)
{
    GitNewBranch createBranch = GitNewBranch("TestBranch");

    createBranch.run();

    GitListBranches listBranches = GitListBranches();

    std::vector<string> branchVector = listBranches.run();
    bool inBranchList = false;
    for (string branchName : branchVector)
    {
        if (branchName == "TestBranch")
        {
            inBranchList = true;
        }
    }

    EXPECT_TRUE(inBranchList);

    GitDeleteBranch deleteBranch = GitDeleteBranch("TestBranch");
    deleteBranch.run();
    branchVector = listBranches.run();
    inBranchList = false;
    for (string branchName : branchVector)
    {
        if (branchName == "TestBranch")
        {
            inBranchList = true;
        }
    }

    EXPECT_FALSE(inBranchList);
}