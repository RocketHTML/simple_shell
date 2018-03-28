# Simple Shell

### Description
	Homemade version of the linux shell
	
### Environment
	Ubuntu 14.04 LTS via Vagrant in VirtualBox

### Features
	Can run user defined executables
	Searches the path for executables
	Can run linux env built-in command
	Can run custom moo built-in command
	Will ignore Ctrl-C signal
	Will quit on "exit"

### File Contents
|   **File**   |   **Description**   |
| -------------- | --------------------- |
| shell.h | Header file containing all function prototypes and struct declaration |
| free_cmd.c| free's the malloc'd space allocated for a command struct |
| shell.c   | The shell program entry point |
| eval.c | Parses command into command struct, and then run's specified built-in or executable |
| parse.c  | Parses command into command struct |
| runUserExecutable.c  | Run's specified executable |
| runBuiltIn.c  | Run's specified built-in |
| env.c  | Built-in function that prints the environment variables |
| moo.c  | Built-in function that prints a cow |
| exit.c  | Built-in function that exits the simple shell |
| path_functions.c  | File containing all path related helper functions |

### Path Functions
|   **Function**   |   **Description**   |
| -------------- | --------------------- |
| create_pathnode | Creates path node struct |
| make_pathlist | Creates linked list from path environment variable |
| pathsearch   | Searches path for a file |

### Usage
	./shell

### Installation
	$ git clone https://github.com/RocketHTML/simple_shell

### Compilation
	$ gcc -Wall -Wextra -Werror -pedantic -Wno-format *.c -o shell

### Example
![shellgif](https://media.giphy.com/media/vgzs5zPpGHdtp2sf1p/giphy.gif)

### Authors

  * [**John Dinh**](https://github.com/koukijohn)
  * [**Madison Burke**](https://github.com/RocketHTML)

### Acknowledgements

<p align="center">
<a href="https://www.holbertonschool.com"><img src="https://intranet.hbtn.io/assets/holberton-logo-simplified-d4e8a1e8bf5ad93c8c3ce32895b4b53749b477b7ba7342d7f064e6883bcd3be2.png"></a>
</p>
