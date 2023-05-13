#include "YesOrNoPrompt.h"

using std::string;
using std::flush;
using std::endl;

YesOrNoPrompt::YesOrNoPrompt(string prompt, YesOrNo defaultOption) :
    prompt(prompt),
    defaultOption(defaultOption)
{}

TerminalPromptResult YesOrNoPrompt::presentPrompt(std::ostream& out, std::istream& in) {
    TerminalPromptResult result;
    result.type = TerminalPromptResultType::YES_OR_NO;

    // Print the prompt
    out << prompt;
    if (defaultOption == YesOrNo::YES) out << " (Y/n): " << flush;
    else out << " (y/N): " << flush;

    // Get input from the user
    char input;
    in.get(input);

    // If the input is empty, 
    if (input == '\n') {
        result.yesOrNo = defaultOption;
        return result;
    }

    if (input == 'Y' or input == 'y') {
        result.yesOrNo = YesOrNo::YES;
        return result;
    }
    if (input == 'N' or input == 'n') {
        result.yesOrNo = YesOrNo::NO;
        return result;
    }

    // Retry if the input is invalid
    out << "Invalid input" << endl;
    return presentPrompt(out, in);
}