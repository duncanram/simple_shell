#include "shell.h"

/**
 * _erratoi - converts strings to integers.
 * @s: The string to be converted
 *
 * Description: This function attempts to convert the provided string into an integer.
 * If no numbers are found in the string, it returns 0. If an error occurred
 * during conversion, it returns -1.
 *
 * Return: 0 if no numbers are found in the string,
 *         the converted number otherwise,
 *         or -1 on error (invalid input or overflow)
 */
int _erratoi(char *s)
{
    int i = 0;
    unsigned long int result = 0;

    if (*s == '+')
        s++;  /* TODO: why does this make main return 255? */
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result *= 10;
            result += (s[i] - '0');
            if (result > INT_MAX)
                return (-1);
        }
        else
            return (-1);
    }
    return (result);
}

/**
 * print_error - displays error messages
 * @info: The parameter and return information struct
 * @estr: string containing the specified error type.
 *
 * This function is responsible for printing out an error message based on
 * the provided error type string. It returns 0 in most cases but can return
 * -1 in case of an error.
 *
 * Return: 0 in normal cases, or -1 on error
 */
void print_error(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
}

/**
 * print_d - prints a decimal (integer) number in base 10.
 * @input: The input number
 * @fd: The file descriptor to write
 *
 * Return: The number of characters printed
 */
int print_d(int input, int fd)
{
    int (*__putchar)(char) = _putchar;
    int i, count = 0;
    unsigned int _abs_, current;

    if (fd == STDERR_FILENO)
        __putchar = _eputchar;
    if (input < 0)
    {
        _abs_ = -input;
        __putchar('-');
        count++;
    }
    else
        _abs_ = input;
    current = _abs_;
    for (i = 1000000000; i > 1; i /= 10)
    {
        if (_abs_ / i)
        {
            __putchar('0' + current / i);
            count++;
        }
        current %= i;
    }
    __putchar('0' + current);
    count++;

    return (count);
}

/**
 * convert_number - conversion function similar to itoa
 * @num: The number to be converted
 * @base: the base for the conversion
 * @flags: flags related to the argument
 *
 * This function converts the provided number into a string representation
 * using the specified base. It returns the resulting string.
 *
 * Return: the converted string
 */
char *convert_number(long int num, int base, int flags)
{
    static char buffer[BUFFER_SIZE];
    char sign = 0;
    char *ptr;
    unsigned long n = num;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }
    ptr = &buffer[BUFFER_SIZE - 1];
    *ptr = '\0';

    do
    {
        *--ptr = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef"[n % base] : "0123456789ABCDEF"[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--ptr = sign;
    return (ptr);
}

/**
 * remove_comments - replaces first instance of '#' in the string with '\0'
 * @buf: The address of the string to modify it.
 *
 * This function is designed to replace the first occurrence of '#' in the
 * given string with a null terminator ('\0'). It always returns 0
 *
 * Return: always returns 0
 */
void remove_comments(char *buf)
{
    int i;

    for (i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
        {
            buf[i] = '\0';
            break;
        }
}