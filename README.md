# Project Name: Minishell

# Summary
This project is about creating a simple shell, similar to bash. 

# Basic Features:
**Our shell**:<br>
• displays a prompt when waiting for a new command. \
• has a working history. \
• searches and launches the right executable (based on the PATH variable or using a
  relative or an absolute path). \
• handles single quotes which prevents the shell from interpreting the metacharacters
  in the quoted sequence. \
• handles double quotes which prevents the shell from interpreting the metacharacters
  in the quoted sequence except for $ (dollar sign). \
  • works with redirections: \
    1. < redirects input. \
    2. > redirects output. \
    3. << is given a delimiter, then reads the input until a line containing the
      delimiter is seen. \
    4. >> redirects output in append mode. \
• pipes are implemented (||). The output of each command in the pipeline is
connected to the input of the next command via a pipe. \
• handles environment variables ($ followed by a sequence of characters) which expands to their values.\
• handles $? which expands to the exit status of the most recently executed
foreground pipeline.\
• handles ctrl-C, ctrl-D and ctrl-\ which behaves like in bash.
  In interactive mode:\
   1. ctrl-C displays a new prompt on a new line. \
   2. ctrl-D exits the shell.\
   3. ctrl-\ does nothing.\
 • the following builtins are also implemented:\
   1. echo with option -n\
   2. cd with only a relative or absolute path\
   3. pwd with no options\
   4. export with no options\
   5. unset with no options\
   6. env with no options or arguments\
   7. exit with no options

# Usage
To compile the program, the provided Makefile can be used. There we defined some rules and they can be run by these basic commands:<br>
**make**: This command compiles the necessary source code files and links them to create the final executable.<br>
**make test**: This command runs valgrind for memory leaks and is used for debugging purposes.<br>
**make clean**: This command will remove any generated files and clean up the project directory.<br>

# Contributors
jpa-rocha<br>
GulenayMer<br>
