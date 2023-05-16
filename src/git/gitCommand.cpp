#include "gitCommand.h"

#include <stdio.h>
#include <exception>
#include <stdexcept>

using std::string;

GitCommand::GitCommand(string command) {
    this->command = "git " + command;
}

string GitCommand::runCommand() {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(command.c_str(), "r");
    if (pipe == nullptr) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}