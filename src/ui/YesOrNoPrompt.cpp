#include "YesOrNoPrompt.h"

#include <iostream>
using std::flush;
using std::endl;

using std::string;

YesOrNoPrompt::YesOrNoPrompt(string prompt, YesOrNo defaultOption) :
    prompt(prompt),
    defaultOption(defaultOption)
{}

YesOrNo YesOrNoPrompt::presentPrompt(std::ostream& out, std::istream& in) {
    // Print the prompt
    out << prompt;
    if (defaultOption == YesOrNo::YES) out << " (Y/n): " << flush;
    else out << " (y/N): " << flush;

    // Get input from the user
    string line;
    getline(in, line);

    if (line.size() == 0) {
        return defaultOption;
    }

    char input = line[0];

    // If the user just presses enter
    if (input == '\n') {
        return defaultOption;
    }

    if (input == 'Y' or input == 'y') {
        return YesOrNo::YES;
    }
    if (input == 'N' or input == 'n') {
        return YesOrNo::NO;
    }

    // Retry if the input is invalid
    out << "Invalid input" << endl;
    return presentPrompt(out, in);
}