#include "main.h"

/**
 * _check - check and print
 * @format: Formatted string in which to print the arguments.
 * @format_types: List of arguments to be printed.
 * @i: The current index
 * @unknow_len: Length of the unknown.
 * @width: get width.
 * @ind: index pointer.
 */

int _check(format_t format_types[], int i, const char *format, int unknow_len, int width, int *ind)
{
	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
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
	return unknow_len;
}
