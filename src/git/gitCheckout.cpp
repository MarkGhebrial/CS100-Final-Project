#include "gitCheckout.h"
#include "gitError.h"

#include <string>

using std::string;

GitCheckout::GitCheckout(string branchName) : GitCommand("checkout " + branchName) { }

void GitCheckout::run()
{
    string output = runCommand();
}