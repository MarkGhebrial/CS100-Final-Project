#ifndef _STRING_PROMPT_H_
#define _STRING_PROMPT_H_

#include <string>
#include <sstream>
#include <cstdio>

//template <typename sstring>
class StringPrompt {
    public:
		  StringPrompt(std::string prompt);
      //sstring //testing the tests
      presentPrompt(std::ostream& out, std::istream& in);

    private:
		  std::string prompt;
};

#endif

