#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum TerminalScreenResultTypes {
    MENU,
    YES_OR_NO,
};

struct TerminalScreenResult {
    TerminalScreenResultTypes type;
};

class TerminalScreen {
    public:
        virtual TerminalScreenResult* present_screen() = 0;
};


struct MenuResult : public TerminalScreenResult {
    string result;

    MenuResult(string result) {
        type = TerminalScreenResultTypes::MENU;
        this->result = result;
    }
};

class MenuScreen : public TerminalScreen {
    public:
        TerminalScreenResult* present_screen() { return new MenuResult("adsfdsaf"); }
};


enum YesOrNo {
    YES,
    NO
};

struct YesOrNoResult : public TerminalScreenResult {
    YesOrNo result;

    YesOrNoResult(YesOrNo result) {
        type = TerminalScreenResultTypes::YES_OR_NO;
        this->result = result;
    }
};

class YesOrNoScreen : public TerminalScreen {
    public:
        TerminalScreenResult* present_screen() { return new YesOrNoResult(YesOrNo::YES); }
};

int main() {
    vector<TerminalScreen*> vec;

    vec.push_back(new MenuScreen);
    vec.push_back(new YesOrNoScreen);
    vec.push_back(new MenuScreen);
    vec.push_back(new YesOrNoScreen);
    vec.push_back(new YesOrNoScreen);

    for (TerminalScreen* screen : vec) {
        TerminalScreenResult* screenResult = screen->present_screen();
        switch (screenResult->type) {
            case (TerminalScreenResultTypes::MENU): {
                // Cast the pointer into a MenuResult so that we can access its `result` member variable
                MenuResult* menuResult = (MenuResult*) screenResult;
                cout << "Menu result: " << menuResult->result << endl;
                break;
            }
            case (TerminalScreenResultTypes::YES_OR_NO): {
                YesOrNoResult* yesOrNoResult = (YesOrNoResult*) screenResult;
                cout << "Yes or no result: " << yesOrNoResult->result << endl;
                break;
            }
            default:
                exit(1);
        }
    }

    return 0;
}