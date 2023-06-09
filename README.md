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
    [ ] Menu item 1
    <b>[ ] Cursor location</b>
    [ ] Menu item 3
    [ ] Menu item 4
    [x] Selected menu item
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

## Screenshots
> Screenshots of the input/output after running your application

## Compilation and Installation

To build GitBuddy, clone this repository, then run the following commands in its root directory.

```
cmake .
make
```

An executable called "gb" will be created in the root directory of the project. To install GitBuddy, just put that executable somewhere in your PATH.

## Usage

```
Usage: gb <command>

Commands:
  commit    Stage and commit your changes
  merge     Merge one branch into another
  branch    Create or delete a branch
  checkout  Switch to another branch
  sync      Pull and push your current branch
  discard   Discard changes on the working tree
  revert    Select commits to revert
  reset     Select a commit to roll history back to
  ignore    Untrack files and add them to .gitignore
```

## Testing

We used gtest to write unit tests for our ui prompts and git backend classes.

Unit tests were implemented for the `YesOrNoPrompt` and `StringPrompt` by replacing `cin` and `cout` with `istringstream`s and `ostringstream`s. Different combinations of `YesOrNoPrompts` and `StringPrompts` are tested in `src/test/combineYNStringTests.cpp`.

The `MenuPrompt` class does not use C++'s iostreams and instead uses `conio.h`. It might be possible to unit test it if we wrote a wrapper around conio, but we instead wrote a simple program (in `src/menuPromptTest.cpp`) that allows you to check if the menuPrompt works as expected.
Run the `menuTest` executable after building the project to test the menu.

> NOTE: `MenuPrompt` is only verified to work on the CS100 ssh server. See [issue #42](https://github.com/cs100/final-project-ttrin055-twan012-mgheb003-cknox008/issues/42)

Invoking Git cannot be unit tested (at least not easily), so we only test the functions that are responsible for parsing Git's output, such as the `GitStatusResult` constructor or `GitPush::checkForErrors`.