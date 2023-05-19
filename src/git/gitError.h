#ifndef _GIT_ERROR_H_
#define _GIT_ERROR_H_

enum GitErrorType{
    GIT_NOT_INSTALLED,
    GIT_NO_STAGED_FILES,
    GIT_NO_UPSTREAM_BRANCH
};

class GitError : public std::exception
{
    public:
        GitError(GitErrorType error) { errorType = error; };

        std::string what (){
            if (errorType == GIT_NOT_INSTALLED)
            {
                return "Git not installed!";
            }
            else if (errorType == GIT_NO_STAGED_FILES)
            {
                return "No staged files!";
            }
            else if (errorType == GIT_NO_UPSTREAM_BRANCH)
            {
                return "No upstream branch!";
            }
        }

    private:
        GitErrorType errorType;
};

#endif