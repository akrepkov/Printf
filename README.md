## Ft_printf

The printf project is a personal implementation of the printf function in C, which is a standard output function used for formatting and printing data to the console. 

### Key concepts
1. Variadic Functions
    - Concept: Functions that accept a variable number of arguments.
    - Skills: Using stdarg.h macros such as va_start, va_arg, and va_end to handle a variable number of arguments in your custom printf function.
2. Format Specifiers
    - Concept: Format specifiers are placeholders in strings that define how data should be formatted and displayed.
    - Skills: Parsing and interpreting format specifiers like %d (integers), %s (strings), %c (characters), %f (floating-point numbers), %x (hexadecimal), etc., and formatting output accordingly.
3. Memory Management
    - Concept: Efficiently managing memory usage for dynamic strings and buffers.
    - Skills: Allocating and deallocating memory for string manipulation and handling edge cases to prevent memory leaks.
4. Error Handling
    - Concept: Managing errors and edge cases in function implementation.
    - Skills: Validating format specifiers and arguments, and handling unexpected input or formatting issues gracefully.
   
### Example
```
#include "printf.h"

int main() {
    char *name = "Anna";
    int age = 30;
    ft_printf("Name: %s, Age: %d\n", name, age);
    return 0;
}
```
