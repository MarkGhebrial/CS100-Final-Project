#include "stringPrompt.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

StringPrompt::StringPrompt(string prompt) :
    prompt(prompt)
{}

StringPrompt::presentPrompt(std::ostream& out, std::istream& in) {
    // Print the prompt
    out << prompt;
    // Get string input from the user
    string message;
    in.getline(cin, message);

    return message;
}
