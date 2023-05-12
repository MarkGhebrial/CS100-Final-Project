#include <iostream>
using std::cout;
using std::endl;

#include "git/gitCommand.h"

int main() {
    std::cout << "Hello, world!" << std::endl;

    GitCommand cmd = GitCommand("status -s");
    cout << cmd.run() << endl;
}