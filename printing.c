#include "main.h"
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
	format_t format_types[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexadecimal},
		{'X', print_hexa_upper},
		{'p', print_pointer},
		{'S', print_non_printable},
		{'r', print_reverse},
		{'R', print_rot13string},
		{'\0', NULL}};

	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, precision, size));

	printed_chars = _check(format_types, i, format, unknow_len, width, ind);
	return (printed_chars);
}
