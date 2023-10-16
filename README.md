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
- lseek() and global variables are forbidden.

---

### The Function

**Prototype:**  

`char *get_next_line(int fd);`  

**Parameters**

fd: The file descriptor for reading.  

**Return Value**  

- On success: A pointer to the line read, terminated with a newline character.
- On end-of-file (EOF): NULL is returned.  
- On error: NULL is returned.

Get_next_line carries out its task in three straightforward steps:

- **Read an amount of characters equal to BUFFER_SIZE:**  
  It begins by using the read function to bring in a portion of the data, placing it into a temporary storage area called a buffer. It does this until the read portion includes a newline '\n' character or it has reached the end of the file.

```
  char	*read_to_stash(int fd, char *str)
  {
	char	*buffer;
	int		cursor;

	cursor = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && cursor != 0)
	{
		cursor = read(fd, buffer, BUFFER_SIZE)**;
		if (cursor == -1)
			return (free(buffer), free(str), NULL);
		buffer[cursor] = 0;
		str = ft_strjoin(str, buffer);
	}
	return (free(buffer), str);
  }
```


- **Extract the Line:**  
  Next, the function looks through the buffer and isolates the line up until it reaches the newline character ('\n'). I will return this line to the calling function.

```
char	*stash_to_line(char *str)
{
	char	*line;
	size_t	len;

	len = ft_strlen(str);
	line = ft_calloc (sizeof(char), len + 1);
	if (!line)
		return (NULL);
	line = ft_strjoin(line, str);
	if (line[0] == 0)
		return (free(line), NULL);
	return (ft_str_cut(line));
}
```


- **Prepare for Next Read:**  
  After successfully retrieving the line, get_next_line makes sure the static buffer is updated. It now starts at the character right after the newline ('\n') character, preparing for the next read.

```
char	*update_stash(char *str)
{
	int		i;
	int		j;

	i = ft_strchr(str, '\n');
	if (!ft_strchr(str, '\n') && str[i] != '\n')
		return (free(str), NULL);
	j = 0;
	while (str[i + 1])
	{
		str[j++] = str[i + 1];
		i++;
	}
	while (str[j] != '\0')
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}
```

And that's how get_next_line efficiently processes text, step by step!

---

## Remarks
This project served as a nice introduction to utilizing file descriptors and the read function effectively. While I acknowledge there may be room for improvement in how I managed the process of isolating lines up to and including the newline character, I consider it a valuable learning experience and an opportunity for future improvement.

---

## Sources
- [Reading a line from a file](https://www.youtube.com/watch?v=w0mgn6OLKUs&t=178s)
- [Man pages Read](https://man7.org/linux/man-pages/man2/read.2.html)
- [Input/Output](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)
