#ifndef _YES_OR_NO_PROMPT_H_
#define _YES_OR_NO_PROMPT_H_

#include <string>

/// Enumerates "Yes" and "No"
enum YesOrNo {
    YES,
    NO
};

class YesOrNoPrompt {
    public:
        YesOrNoPrompt(std::string prompt, YesOrNo defaultOption);

        /// @brief Presents a yes or no prompt to the user
        /// @return Their choice
        YesOrNo presentPrompt(std::ostream& out, std::istream& in);

    private:
        std::string prompt;
        YesOrNo defaultOption;
};

#endif