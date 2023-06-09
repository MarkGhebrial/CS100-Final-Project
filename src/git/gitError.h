#ifndef _GIT_ERROR_H_
#define _GIT_ERROR_H_

enum GitErrorType{
    /// user does not have Git installed
    GIT_NOT_INSTALLED,

    /// user has no staged files
    GIT_NO_STAGED_FILES,

    /// no branch to push to
    GIT_NO_UPSTREAM_BRANCH,

    /// pull will overwrite uncommitted changes
    GIT_OVERWRITING_LOCAL_FILES,

    /// couldn't pull from the repository
    GIT_FAILED_TO_PULL,
    /// checkout will overwrite uncommitted changes
    GIT_CHECKOUT_WILL_OVERWRITE,

    /// couldn't push to repository
    GIT_FAILED_TO_PUSH,

    /// `git add` failed
    GIT_ADD_ERROR
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
            else if (errorType == GIT_OVERWRITING_LOCAL_FILES)
            {
                return "Pull will overwrite local changes!";
            }
            else if (errorType == GIT_FAILED_TO_PULL)
            {
                return "Failed to pull from the repository!";
            }
            else if (errorType == GIT_CHECKOUT_WILL_OVERWRITE)
            {
                return "Checkout will overwrite uncommited changes!";
            }
            else if (errorType == GIT_FAILED_TO_PUSH)
            {
                return "Failed to push to the repository!";
            }
            else if (errorType == GIT_ADD_ERROR)
            {
                return "Git add failed!";
            }
            else {
                return "INVALID ERROR TYPE!";
            }
        }

    private:
        GitErrorType errorType;
};

#endif