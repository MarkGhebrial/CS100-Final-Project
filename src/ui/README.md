### How to add new prompt

1. Define a result type for the prompt in `TerminalPrompt.h`.
1. Add that new type to the union in `TerminalPromptResult`.    
1. Add an item to the `TerminalPromptResultType` enum to represent that result type.
1. Create new header and source files for the prompt in `src/ui`.
1. Create a class that implements `TerminalPrompt` and implement a constructor and `TerminalPrompt::presentPrompt` for that class
   - `presentPrompt` takes an input and output stream as arguments and returns a `TerminalPromptResult` that *must* have a the correct type.