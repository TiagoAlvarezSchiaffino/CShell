# CShell
Shell is a project focused on building a custom shell in C, similar to bash.

Early developers found communicating with computers via binary switches tedious and impractical. The creation of shells, which allow interactive command-line communication, marked a significant milestone, bringing us closer to human-like language interactions with machines.

Shell takes you on a journey back to the challenges faced before graphical user interfaces, allowing a deeper understanding of fundamental shell functionalities.


## Features
**General Guidelines**
- Prompt Display: Shows a prompt when waiting for a new command.
- Command History: Maintains a history of executed commands.
- Executable Search: Finds and launches the correct executable using the `PATH` variable or relative/absolute paths.
- Quote Handling: Properly manages unclosed quotes and special characters, excluding unnecessary ones like `\` or `;`.
- Single Quotes `’`: Prevents interpretation of meta-characters within single quotes.
- **Double Quotes `"`: Prevents interpretation of meta-characters within double quotes except for `$`.

**Redirections**
- Input Redirection `<`: Redirects input from a file.
- Output Redirection `>`: Redirects output to a file.
- Here Document `<<`: Reads input until a specified delimiter is reached.
- Append Redirection `>>`: Redirects output in append mode.

**Signals**
- In interactive mode
    - `ctrl-C`: Displays a new prompt on a new line.
    - `ctrl-D`: Exits the shell.
    - `ctrl-\`: Does nothing, similar to bash behavior.

**Builtins**
- `echo`: Supports -n option.
- `cd`: Changes directory with relative or absolute paths.
- `pwd`: Prints the current working directory.
- `export`: Sets environment variables.
- `unset`: Unsets environment variables.
- `env`: Prints the environment.
- `exit`: Exits the shell.


**Others**
- Pipes `|`: Connects the output of one command to the input of the next.
- `Environment Variables`: Expands environment variables to their values.
- Exit Status `$?`: Expands to the exit status of the most recent foreground pipeline.


## Bonus
`&&` (AND operator):
- AND Operator `&&`: Executes the right-hand command only `if the left-hand command succeeds`.

`||` (OR operator):
- OR Operator `||`: Executes the right-hand command only `if the left-hand command fails`.

`()` (Subshells)
- Subshells `()`: Runs commands in a separate shell instance.

Example of using parentheses to create a subshell:
```
(export A="hi" && echo $A) && echo $A
```

In this case, the output will be
```
hi


```
`The second line is empty because the export happened in a subshell`.

`*` (Wildcard)
- Wildcard `*`: Matches any sequence of characters in filenames or paths.
- It can be used in commands like `ls`, `cp`, `mv`, `rm`, and others to perform operations on multiple files or directories that match a specific pattern.
- For example, `*.txt` matches all `.txt` files.