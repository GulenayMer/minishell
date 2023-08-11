# Project Name: Minishell

# Summary
This project is about creating a simple shell, similar to bash. 

# Basic Features:
**Our shell**:<br>
• Displays a prompt when waiting for a new command.<br>
• Has a working history.<br>
• Searches and launches the right executable (based on the PATH variable or using a relative or an absolute path).<br>
• Handles single quotes which prevents the shell from interpreting the metacharacters in the quoted sequence.<br>
• Handles double quotes which prevents the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).<br>
• Works with redirections:<br>
    1. < redirects input.<br>
    2. > redirects output.<br>
    3. << is given a delimiter, then reads the input until a line containing the delimiter is seen.<br>
    4. >> redirects output in append mode.<br>
• Pipes are implemented (||). The output of each command in the pipeline is connected to the input of the next command via a pipe.<br>
• Handles environment variables ($ followed by a sequence of characters) which expands to their values.<br>
• Handles $? which expands to the exit status of the most recently executed foreground pipeline.<br>
• Handles ctrl-C, ctrl-D, and ctrl-\ which behaves like in bash.<br>
    - ctrl-C displays a new prompt on a new line.<br>
    - ctrl-D exits the shell.<br>
    - ctrl-\ does nothing.<br>
• The following builtins are also implemented:<br>
    - echo with option -n<br>
    - cd with only a relative or absolute path<br>
    - pwd with no options<br>
    - export with no options<br>
    - unset with no options<br>
    - env with no options or arguments<br>
    - exit with no options<br>

# Usage
To compile the program, the provided Makefile can be used. There we defined some rules and they can be run by these basic commands:<br>
**make**: This command compiles the necessary source code files and links them to create the final executable.<br>
**make test**: This command runs valgrind for memory leaks and is used for debugging purposes.<br>
**make clean**: This command will remove any generated files and clean up the project directory.<br>

# Contributors
jpa-rocha<br>
GulenayMer<br>
