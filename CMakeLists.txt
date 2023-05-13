cmake_minimum_required(VERSION 3.14)
project(gitbuddy)

add_executable(gb
    src/main.cpp
    src/git/gitCommand.cpp
    src/git/gitStatus.cpp

    src/ui/TerminalPrompt.cpp
    src/ui/YesOrNoPrompt.cpp
)

add_executable(test
    src/test/tests.cpp
    src/test/gitStatusTests.cpp
    src/git/gitCommand.cpp
    src/git/gitStatus.cpp
)
target_link_libraries(
  test
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