#include "gitCommand.h"

#include <exception>

#include <iostream>
using std::cout;
using std::endl;


#include <stdio.h>

int BUFF_SIZE = 1000;

GitCommand::GitCommand(string command) {
    this->command = "git " + command;
}

string GitCommand::run() {
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