<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">

# Get_Next_Line

A project where we write the Get_next_line Fucntion. aA simple, yet powerful function that reads a line from a file descriptor. It is designed to be easily integrated into your C projects, providing a convenient way to read lines from a file or standard input.

This project is particularly useful for applications where line-by-line input processing is required, such as parsing configuration files, log processing, and more.

---

## Usage
To use get_next_line in your project, follow these steps:

- Clone this repository or download the source files by clicking the green code button in the upper right corner.  
  Run git clone https://github.com/arommers/get_next_line.git in your terminal to clone.
- Add get_next_line.c, get_next_line_utils.c, and get_next_line.h to your project directory.
- Include the get_next_line.h header file in your source files where you want to use the function.
- Compile your project along with the get_next_line files*.  
  `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c your_file.c -o <your_program>`

**The buffer size is optional. When not defined during compilation, it will take the value as defined in the header file.*

  ---

## Requirements

The Get_Next_Line function is written as an exercise of the Codam curriculum and has to adhere to the following rules:
- Repeated calls (e.g., using a loop) to your get_next_line() function should let
  you read the text file pointed to by the file descriptor, one line at a time.
- Your function should return the line that was read.
  If there is nothing else to read or if an error occurred, it should return NULL.
- Make sure that your function works as expected both when reading a file and when
  reading from the standard input.
- Please note that the returned line should include the terminating \n character,
  except if the end of file was reached and does not end with a \n character.
- Because you will have to read files in get_next_line(), add this option to your
  compiler call: -D BUFFER_SIZE=n
  It will define the buffer size for read().
- We consider that get_next_line() has an undefined behavior if the file pointed to
  by the file descriptor changed since the last call whereas read() didn’t reach the
  end of file.
- We also consider that get_next_line() has an undefined behavior when reading
  a binary file. However, you can implement a logical way to handle this behavior if
  you want to.
  
