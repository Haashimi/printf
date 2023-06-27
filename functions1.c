#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_unsigned(va_list args, char buffer[],
                  int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int number = va_arg(args, unsigned long int);

    number = convert_unsigned_size(number, size);

    if (number == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (number > 0)
    {
        buffer[i--] = (number % 10) + '0';
        number /= 10;
    }

    i++;

    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list args, char buffer[],
               int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int number = va_arg(args, unsigned long int);
    unsigned long int init_number = number;

    UNUSED(width);

    number = convert_unsigned_size(number, size);

    if (number == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (number > 0)
    {
        buffer[i--] = (number % 8) + '0';
        number /= 8;
    }

    if (flags & F_HASH && init_number != 0)
        buffer[i--] = '0';

    i++;

    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list args, char buffer[],
                      int flags, int width, int precision, int size)
{
    return (print_hexa(args, "0123456789abcdef", buffer,
                       flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list args, char buffer[],
                     int flags, int width, int precision, int size)
{
    return (print_hexa(args, "0123456789ABCDEF", buffer,
                       flags, 'X', width, precision, size));
}

/************** PRINT HEX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa(va_list args, char map_to[], char buffer[],
               int flags, char flag_ch, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int number = va_arg(args, unsigned long int);
    unsigned long int init_number = number;

    UNUSED(width);

    number = convert_unsigned_size(number, size);

    if (number == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (number > 0)
    {
        buffer[i--] = map_to[number % 16];
        number /= 16;
    }

    if (flags & F_HASH && init_number != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++;

    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

