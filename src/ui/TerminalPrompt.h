#ifndef _TERMINAL_PROMPT_H_
#define _TERMINAL_PROMPT_H_

#include <vector>
#include <string>
#include <iostream>

/////////////////////////////////////////////
//                                         //
//    DEFINE RESULT TYPES HERE             //
//                                         //
/////////////////////////////////////////////

/// Enumerates "Yes" and "No"
enum YesOrNo {
    YES,
    NO
};

/// MenuResults are vectors of strings
typedef std::vector<std::string> MenuResult;

/// Add each result type to this enum
enum TerminalPromptResultType {
    YES_OR_NO,
    MENU,
    STRING
};

struct TerminalPromptResult {
    TerminalPromptResult() {}; // Default constructor
    ~TerminalPromptResult() {}; // Default destructor
    TerminalPromptResult(const TerminalPromptResult& r) {
        type = r.type;
        switch (type) {
            case TerminalPromptResultType::YES_OR_NO:
                yesOrNo = r.yesOrNo;
                break;
            case TerminalPromptResultType::MENU:
                menu = r.menu;
                break;
            case TerminalPromptResultType::STRING:
                string = r.string;
                break;
            
            default:
                std::cout << "INVALID PROMPT RESULT TYPE. DID YOU FORGET TO ADD IT TO THE COPY CONSTRUCTOR?" << std::endl;
                exit(1);
                break;
        }
    };

    TerminalPromptResultType type;
    // Add each result type to this union
    union {
        MenuResult menu;
        YesOrNo yesOrNo;
        std::string string;
    };
};

class TerminalPrompt {
    virtual TerminalPromptResult presentPrompt(std::ostream& out, std::istream& in) = 0;
};

#endif