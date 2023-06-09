cmake_minimum_required(VERSION 3.14)
project(gitbuddy)

add_executable(gb
    src/main.cpp
    src/git/gitAdd.cpp
    src/git/gitCommand.cpp
    src/git/gitCommit.cpp
    src/git/gitDeleteBranch.cpp
    src/git/gitListBranches.cpp
    src/git/gitNewBranch.cpp
    src/git/gitPull.cpp
    src/git/gitPush.cpp
    src/git/gitStatus.cpp
    src/git/gitListBranches.cpp
    src/git/gitNewBranch.cpp
    src/git/gitDeleteBranch.cpp
    src/git/gitCheckout.cpp
    src/ui/stringPrompt.cpp
    src/ui/YesOrNoPrompt.cpp
    src/ui/menuPrompt.cpp
)

add_executable(menuTest
    src/menuPromptTest.cpp
    src/ui/menuPrompt.cpp
)

add_executable(tests
    test/tests.cpp
    test/gitBranchTests.cpp
    test/gitPullTests.cpp
    test/gitPushTests.cpp
    test/gitStatusTests.cpp
    test/YesOrNoPromptTests.cpp
    test/StringPromptTests.cpp
    test/combineYNStringTests.cpp
    src/ui/YesOrNoPrompt.cpp
    src/ui/stringPrompt.cpp
    src/git/gitCommand.cpp
    src/git/gitCommit.cpp
    src/git/gitDeleteBranch.cpp
    src/git/gitListBranches.cpp
    src/git/gitNewBranch.cpp
    src/git/gitPull.cpp
    src/git/gitPush.cpp
    src/git/gitStatus.cpp
)
target_link_libraries(
  tests
  GTest::gtest_main
)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)
