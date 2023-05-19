#ifndef _STRING_PROMPT_H_
#define _STRING_PROMPT_H_

#include <string>

class StringPrompt {
    public:
        StringPrompt(std::string prompt, YesOrNo defaultOption);

        /// std::YesOrNO prompt
	/// commit message
	//Enter a commit message (leave blank to edit it in vim):
	//Sync changes with remote? (Y/n):
        
	/// branch name
	// Create or delete a branch? (C/d):
	//Enter branch name:
	//Checkout to the new branch? (Y/n):

        StringPrompt presentPrompt(std::ostream& out, std::istream& in);
        getString();

    private:
	std::YesOrNO prompt;
        YesOrNo defaultOption;
};

#endif

