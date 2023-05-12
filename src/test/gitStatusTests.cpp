#include <gtest/gtest.h>

#include <string>
using std::string;

#include "../git/gitStatus.h"

TEST(GitStatusParseTests, oneLine) {
    string gitOutput = " M CMakeLists.txt\n";
    GitStatusResult parsedResult(gitOutput);

    EXPECT_EQ(parsedResult.unstagedChanges.at(0), "CMakeLists.txt");
    // Staged and unstaged changes should be empty
    EXPECT_EQ(parsedResult.stagedChanges.size(), 0);
    EXPECT_EQ(parsedResult.untrackedChanges.size(), 0);
}

TEST(GitStatusParseTests, multiline) {
    string gitOutput = " M .gitignore\n M CMakeLists.txt\n M src/git/gitStatus.cpp\nAD src/test/gitTests.cpp\n?? src/test/gitStatusTests.cpp\n?? src/test/tests.cpp\n";
    GitStatusResult parsedResult(gitOutput);

    EXPECT_EQ(parsedResult.unstagedChanges.size(), 4);
    EXPECT_EQ(parsedResult.unstagedChanges.at(0), ".gitignore");
    EXPECT_EQ(parsedResult.unstagedChanges.at(1), "CMakeLists.txt");
    EXPECT_EQ(parsedResult.unstagedChanges.at(2), "src/git/gitStatus.cpp");
    EXPECT_EQ(parsedResult.unstagedChanges.at(3), "src/test/gitTests.cpp");

    EXPECT_EQ(parsedResult.stagedChanges.size(), 1);
    EXPECT_EQ(parsedResult.stagedChanges.at(0), "src/test/gitTests.cpp");

    EXPECT_EQ(parsedResult.untrackedChanges.size(), 2);
    EXPECT_EQ(parsedResult.untrackedChanges.at(0), "src/test/gitStatusTests.cpp");
    EXPECT_EQ(parsedResult.untrackedChanges.at(1), "src/test/tests.cpp");
}

TEST(GitStatusParseTests, emptyString) {
    string gitOutput = "";
    GitStatusResult parsedResult(gitOutput);

    EXPECT_TRUE(parsedResult.unstagedChanges.empty());
    EXPECT_TRUE(parsedResult.stagedChanges.empty());
    EXPECT_TRUE(parsedResult.untrackedChanges.empty());
}