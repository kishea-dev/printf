
#include main.h

/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
                 int flags, int width, int precision, int size)
{
    int i, unknow_len = 0, printed_chars = -1;
    format_t fmt_types[] = {{'c', print_char}, {'s', print_string}, {'%', print_percent}, {'i', print_int}, {'d', print_int}, {'b', print_binary}, {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal}, {'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable}, {'R', print_rot13string}, {'\0', NULL}};
    for (i = 0; fmt_types[i].format != '\0'; i++)
        if (format[*ind] == fmt_types[i].format)
            return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

    if (fmt_types[i].format == '\0')
    {
        if (format[*ind] == '\0')
            return (-1);
        unknow_len += write(1, %%, 1);
        if (format[*ind - 1] == ' ')
            unknow_len += write(1,  , 1);
        else if (width)
        {
            --(*ind);
            while (format[*ind] != ' ' && format[*ind] != '%')
                --(*ind);
            if (format[*ind] == ' ')
                --(*ind);
            return (1);
        }
        unknow_len += write(1, &format[*ind], 1);
        return (unknow_len);
    }
    return (printed_chars);
}

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] == 'l')
        size = S_LONG;
    else if (format[curr_i] == 'h')
        size = S_SHORT;

    if (size == 0)
        *i = curr_i - 1;
    else
        *i = curr_i;

    return (size);
}

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i;
    int width = 0;

    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            width *= 10;
            width += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            width = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curr_i - 1;

    return (width);
}

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] == 'l')
        size = S_LONG;
    else if (format[curr_i] == 'h')
        size = S_SHORT;

    if (size == 0)
        *i = curr_i - 1;
    else
        *i = curr_i;

    return (size);
}

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curr_i - 1;

    return (precision);
}
