<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">

# Get_Next_Line

A project where we write the Get_next_line Fucntion. aA simple, yet powerful function that reads a line from a file descriptor. It is designed to be easily integrated into your C projects, providing a convenient way to read lines from a file or standard input.

This project is particularly useful for applications where line-by-line input processing is required, such as parsing configuration files, log processing, and more.

---

## Usage
To use get_next_line in your project, follow these steps:

- Clone this repository or download the source files by clicking the green code button in the upper right corner.
  git clone https://github.com/arommers/get_next_line.git
- Add get_next_line.c, get_next_line_utils.c, and get_next_line.h to your project directory.
- Include the get_next_line.h header file in your source files where you want to use the function.
- Compile your project along with the get_next_line files*.  
  `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c your_file.c -o <your_program>`

**The buffer size is optional. When not defined during compilation, it will take the value as defined in the header file.*

  ---
