#ifndef _COMBINE_YN_STRING__H_
#define _COMBINE_YN_STRING__H_

#include <iostream>
#include <string>
#include "YesOrNoPrompt.h"
#include "YesOrNoPrompt.h"

class combineYNString {
    public:
		combineYNString(std::string prompt);
        std::string presentPrompt(std::ostream& out, std::istream& in);

    private:
		std::string prompt;
};

#endif