#ifndef _STRING_PROMPT_H_
#define _STRING_PROMPT_H_

#include <string>

class StringPrompt {
    public:
		StringPrompt();
		StringPrompt(std::string prompt);
        presentPrompt(std::ostream& out, std::istream& in);

    private:
		std::string prompt;
};

#endif

