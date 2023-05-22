#ifndef _GIT_COMMIT_H_
#define _GIT_COMMIT_H_

#include "gitCommand.h"

class GitCommit : public GitCommand {
    public:
        /// Default constructor that doesn't implement a commit message
            /// The user will instead type in the message through vim
        GitCommit() : GitCommand("git commit") { };

        /// Parameterized constructor that implements a user inputted commit message
        GitCommit(std::string commitMessage);

        void run();
    private:
        std::string message;
};
// kksddflksdjalkfjsa;dlfjsad;klf sdaf saf afdsa hacking into the mainframe fkdslajf;dlksajfkdlsajfklsda fdsa fdsaf code dcode code code fkdlasjflkdsajfkljdsa;fkjdslafjdlksajflsafj;as foh oh boi fjkldsajf;lsajfklas;jfdsklafjkl;sdajf;sjadf enter im in

#endif