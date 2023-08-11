# Project Name: Minishell

# Summary
This project is about creating a simple shell, similar to bash. 

# Basic Features:
**Our shell**:<br>
• Displays a prompt when waiting for a new command.
• Has a working history.
• Searches and launches the right executable (based on the PATH variable or using a relative or an absolute path).
• Handles single quotes which prevents the shell from interpreting the metacharacters in the quoted sequence.
• Handles double quotes which prevents the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
• Works with redirections:
    1. < redirects input.
    2. > redirects output.
    3. << is given a delimiter, then reads the input until a line containing the delimiter is seen.
    4. >> redirects output in append mode.
• Pipes are implemented (||). The output of each command in the pipeline is connected to the input of the next command via a pipe.
• Handles environment variables ($ followed by a sequence of characters) which expands to their values.
• Handles $? which expands to the exit status of the most recently executed foreground pipeline.
• Handles ctrl-C, ctrl-D, and ctrl-\ which behaves like in bash.
    - ctrl-C displays a new prompt on a new line.
    - ctrl-D exits the shell.
    - ctrl-\ does nothing.
• The following builtins are also implemented:
    - echo with option -n
    - cd with only a relative or absolute path
    - pwd with no options
    - export with no options
    - unset with no options
    - env with no options or arguments
    - exit with no options

# Usage
To compile the program, the provided Makefile can be used. There we defined some rules and they can be run by these basic commands:<br>
**make**: This command compiles the necessary source code files and links them to create the final executable.<br>
**make test**: This command runs valgrind for memory leaks and is used for debugging purposes.<br>
**make clean**: This command will remove any generated files and clean up the project directory.<br>

# Contributors
jpa-rocha<br>
GulenayMer<br>
