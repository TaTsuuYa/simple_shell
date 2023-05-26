#Simple Shell

##Overview

Simple Shell is a UNIX command line interpreter program that allows users to execute commands and manage their UNIX system. It provides a basic command-line interface, similar to the `/bin/sh` shell, with support for built-in commands and handling of the `PATH` environment variable.

##Features

1. **Command Execution**: Simple Shell accepts commands from the user and executes them.
2. **Prompt**: After executing a command, Simple Shell displays a prompt again, indicating that it is ready to accept the next command.
3. **Single-Word Commands**: Command lines entered in Simple Shell consist of a single word command without any arguments.
4. **Error Handling**: Simple Shell handles errors and displays appropriate error messages when necessary, maintaining compatibility with the /bin/sh shell.
5. **Built-in Commands**:
    - `exit`: Allows the user to exit the shell.
        - Usage: `exit`
        - Arguments: The `exit` command does not accept any arguments.
    - `env`: Prints the current environment.
        - Usage: `env`
        - Arguments: The `env` command does not accept any arguments.
6. **PATH Handling**: Simple Shell handles the `PATH` environment variable to locate and execute commands.
7. **Commands Separator**: Simple Shell supports the commands separator `;`. It allows executing multiple commands separated by semicolons.
8. **Logical Operators**: Simple Shell supports the shell logical operators `&&` and `||`. It allows executing commands based on the success or failure of the previous command.

##Compilation

```shell
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

##Usage

To use Simple Shell, run the compiled program hsh from the command line:

```shell
$ ./hsh
```

Once the Simple Shell is running, it will display a prompt and wait for you to enter a command. After executing a command, the prompt will be displayed again, indicating that it is ready to accept the next command.

##Examples

Here are a few examples of using Simple Shell:

```shell
$ ./hsh
$ ls
file1 file2 file3
$ pwd
/home/user/Documents
$ exit
$
```

In the example above, the user runs the Simple Shell program `hsh`, enters commands (`ls` and `pwd`), and finally exits the shell using the `exit` command.

##Conclusion

Simple Shell provides a basic command line interpreter with support for executing commands, handling built-in commands, and managing the PATH environment variable. It aims to replicate the behavior of the `/bin/sh` shell, including error messages and prompt display. With Simple Shell, users can perform common UNIX command line operations efficiently.

