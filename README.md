# GitBuddy: the git workflow tool
 
Authors: [Mark Ghebrial](https://github.com/MarkGhebrial), [Charlie Knox](https://github.com/TheProgrammingWalrus), [Thomas Trinh](https://github.com/ttrin055), [Hugo Wan](https://github.com/HugoWan0504)

## Project Description

GitBuddy is a command line tool for simplifing the Git workflow.

Most IDEs come with a graphical Git integration for performing multiple steps (staging, commiting, pulling, pushing) in one operation (like "commit and push"). Imagine GitBuddy as a CLI version of that.

### Why are we interested in this project?

Students who are new to Git often find the workflow to be unintuitive, often forgetting steps like checking out to a freshly created branch.
A tool like GitBuddy would help reduce mistakes from new git users, and possible implementation of a "learning" or "tutorial" mode would allow users to gain confidence with Git.

### What languages/tools will we use?

- **C++**: All four group members have skill in C++ from CS010, so it is the language of choice. Python might be a better option on account of its memory safety, but its dynamic typing doesn't play well with large projects.
- **gtest**: Will be used to implement unit tests, especially for edge cases.
- **Git**: GitBuddy will invoke Git using the [`system()`](https://cplusplus.com/reference/cstdlib/system/) or `popen()` functions in the C standard library. Git will, of course, also be used to manage the project's versions.
- **GitHub**: Will host the Git repository for GitBuddy's source code.
- **valgrind**: Will be used to detect and debug memory errors. Fixing memory leaks will not be a significant priority since GitBuddy will not run in the background.

### Input/Output example

User interaction with GitBuddy will look something like this:

```
$ gb commit
Unstaged changes:
    main.cpp ++++--
    CMakeLists.txt ++++
    .gitignore +++-
Staged changes: none
Do you want to stage all changes? (Y/n): n
Select files to stage: (Some sort of terminal wizardry allows the user to choose what to stage)
Enter a commit message (leave blank to edit it in vim): Initial commit
Sync changes with remote? (Y/n): y
Apply changes? (Y/n): y
Done :)
```

In the above example, GitBuddy then runs `git add <selected files> && git commit -m "Initial commit" && git pull && git push`.

```
$ gb branch
Local branches:
    main
    mgheb003/project-proposal <- Current branch
Create or delete a branch? (C/d): c
Enter branch name: mgheb003/class-diagram
Checkout to the new branch? (Y/n): y
Apply changes? (Y/n): n
Canceled.
```

### Error handling

GitBuddy will handle git errors as gracefully as possible. For example:
- When attempting to push changes a branch that does not have an upstream, GitBuddy will ask the user if they want to create a branch on the remote.
- When encountering merge conflicts, GitBuddy will tell the user what files have conflicts. Once the conflicts have been resolved, the user can use GitBuddy to automatically finish the merge.
- If the user is not authenticated with GitHub, GitBuddy will provide them with instructions on how to authenticate.

### Features

Wizards will be implemented for the following Git workflows
- `commit`: Allows the user to select files to stage and enter a commit message.
- `merge`: Allows the user to select which branches to merge, then handles checking them out in the correct order and notifying the user of any merge conflicts. If a merge is in progress and all conflicts have been resolved when this command is invoked, GitBuddy will commit the merge.
- `branch`: Allows the user to create or delete a branch and asks if they want to checkout to that branch or not.
- `checkout`: Allows the user to choose a branch or commit to checkout to. If there are uncommited changes in the working directory, GitBuddy will ask the user if they want to stash their changes.
- `sync`: Will push and pull changes from the remote.
- `discard`: Allows the user to undo changes to files in the working directory.
- `revert`: Allows the user to select one or more commits to revert. If multiple commits are chosen, GitBuddy will then ask the user if they want to squash the revert commits.
- `reset`: Allows the user to roll history back to a commit of their choice.
- `ignore`: Allows users to untrack files of thier choosing and optionally add them to the gitignore.
- More features will be hashed out as development continues.

Other feature ideas
- GitBuddy will have a tool for configuring Git username and email, since the commands required for doing so are hard to remember.
- ~~A `gb tree` command could print out the repository's commit and branch history in a tree format.~~ It turns out that `git log --all --oneline --graph` can already do this. Maybe we can alias `gb tree` to that command?

A possible "tutorial mode" will show the user the sequence of commands that GitBuddy would run to make their request happen.

## User Interface Specification

### [Navigation Diagram](https://drive.google.com/file/d/1Tyxf2Yi88Hm0ikOwKy6oJPfvHjo4OSOQ/view)

![Navigation diagram](images/Navigation%20Diagram.drawio.png)

### Screen Layouts

#### Menu screen

Presents a number of options in the terminal for the user to select from.
Menu can either allow the user to select one item or multiple.

The user moves the cursor with the arrow keys, selects items with the space bar, and confirms the selection using the enter key.

<pre><code>Menu prompt:
    [ ] Menu item 1       [ ] Menu item 6
    <b>[ ] Cursor location</b>   [ ] Menu item 7
    [ ] Menu item 3       [ ] Menu item 8
    [ ] Menu item 4       [x] <i>Selected menu item</i>
    [ ] Menu item 5
</code></pre>

Menu types:
- Unstaged file menu: Choose one or more unstaged files
- Branch menu: Choose a branch
- Commit history menu: Choose one or more commits

#### File menu screen

Allows the user to select one or more files in the working directory.
The up and down arrow keys are used to move the cursor. The left and right arrow keys are used to expand/collapse folders.

<pre><code>Select files:
    .gitignore
    Makefile
    <b>cursor-location.sh</b>
    CmakeLists.txt
  > src
  v include
        Rectangle.h
        <i>SelectedFile.h</i>
</code></pre>

#### Staged and unstaged changes screen

Shows the files with uncommited changes.

```
Unstaged changes:
    main.cpp ++++--
    CMakeLists.txt ++++
    .gitignore +++-
Staged changes:
    main.cpp ++-
    README.md
```

#### Branch display screen

Shows the local and remote branches and indicates the one that is currently checked out.

<pre><code>Local branches:
  <b>main <- Checked out</b>
  navigation-diagram
Remote branches:
  origin/screen-layouts
  origin/main
  origin/navigation-diagram
</code></pre>

#### Change confirmation screen

Asks the user if they want GitBuddy to execute the commands they just specified.

```
Apply changes? (Y/n):
```

#### Commit options screen

```
Enter a commit message (leave blank to edit it in vim):
Sync changes with remote? (Y/n):
```

#### Branch options screen

```
Create or delete a branch? (C/d):
Enter branch name:
Checkout to the new branch? (Y/n):
```

#### Revert options screen

If the user selected multiple commits to revert, this screen will ask them if they want to turn the multiple revert commits that will be created into one commit.

```
Squash revert commits? (Y/n): 
```

#### Ignore options screen

```
Add files to gitignore? (Y/n):
```

## Class Diagram

### [Original class diagram](https://drive.google.com/file/d/16vnE1fs09R_JhpO_OeMHC76BUgr4fuAm/view)

![Old class diagram](images/Class%20Diagram.drawio.png)

See [the prototype](promptInheritancePrototype.cpp) to see what this class diagram looks like as code.

### [New class diagram](https://drive.google.com/file/d/1DnEhqoISOAFiNkcXasOvjgUPER_93_hh/view?usp=sharing)

![New class diagram](images/New%20Class%20Diagram.drawio.png)

After learning the SOLID priciples, we realized that our design severely violated the open/closed principle, since adding a new prompt or git command would require changes beyond just adding a new child class.

Consequentially, we decided that the polymorphism provided by our complex inheritance structure was not very important for our program, so we removed the `GitCommandResult`, `TerminalPromptResult`, and `TerminalPrompt` interfaces.
We kept the `GitCommand` parent class because it actually provides functionality to its children (i.e. invoking git in a shell).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
