#include "stringPrompt.h"
#include <string>
#include <iostream>

using namespace std;

StringPrompt::StringPrompt(string prompt) :
    prompt(prompt)
{}

std::string StringPrompt::presentPrompt(std::ostream& out, std::istream& in) {
    // Print the prompt
    out << prompt;
    // Get string input from the user
    string message;
    in.getline(cin, message);
    out << message;
    return presentPrompt(out, in);
}
