#include "stringPrompt.h"
#include "../git/gitCommand.h"
#include <string>
#include <fstream>
using namespace std;

StringPrompt(){
    str = "";
}

StringPrompt::StringPrompt(string prompt) :
    prompt(prompt)
{}

StringPrompt::presentPrompt(std::ostream& out, std::istream& in) {
    // Print the prompt
    out << prompt;
    // Get string input from the user
    string message;
    in.getline(cin, message);

    return presentPrompt(out, in);
}
