# GitBuddy: the git workflow tool
 
Authors: [Mark Ghebrial](https://github.com/MarkGhebrial), [Charlie Knox](https://github.com/TheProgrammingWalrus), [Thomas Trinh](https://github.com/ttrin055), Hugo Wan

## Project Description

GitBuddy is a command line tool for simplifing the Git workflow.

Most IDEs come with a graphical Git integration for performing multiple steps (staging, commiting, pulling, pushing) in one operation (like "commit and push"). Imagine GitBuddy as a CLI version of that.

### Why are we interested in this project?

Students who are new to Git often find the workflow to be unintuitive, often forgetting steps like checking out to a freshly created branch.
A tool like GitBuddy would help reduce mistakes from new git users, and possible implementing a "learning" or "tutorial" mode would allow users to gain confidence with Git itself.

>> We also believe that the scope of GitBuddy's features is flexible enough to ensure that, in the worst case, a minimal product will be produced, and, in the best case, a feature-rich tool will emerge.

>> Essentialy, more features can fit into the project if we finish it early, but, if we've bitten off more than we can chew, we can cut features and still have a working product.

>> We also believe that more features can fit into GitBuddy if we finish it early, but, if we've bitten off more than we can chew, we can cut features and still have a working product.

### What languages/tools will we use?

- **C++**: All four group members have skill in C++ from CS010, so it is the language of choice. Python might be a better option on account of its memory safety, but its dynamic typing doesn't play well with large projects.
- **gtest**: Will be used to implement unit tests, especially for edge cases.
- **Git**: GitBuddy will invoke Git using the [`system()`](https://cplusplus.com/reference/cstdlib/system/) function in the C standard library. Git will, of course, also be used to manage the project's versions.
- **GitHub**: Will host Git repository for GitBuddy's source code.

### Input/Output example

User interaction with GitBuddy will be similar to interacting with github-cli.

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
Pull, then push changes? (Y/n): y
Proceed? (Y/n): y
```

In this example, GitBuddy then runs `git add <selected files> && git commit -m "Initial commit" && git pull && git push`.

### Features

Similar wizards will exist for other Git commands like branch, checkout, revert, etc. The amount of edge cases

A possible "tutorial mode" will show the user the sequence of commands that GitBuddy would run to make their request happen.



 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
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
 
