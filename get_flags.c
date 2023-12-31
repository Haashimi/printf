#include "main.h"

/**

get_flags - Calculates active flags

@format: Formatted string in which to print the arguments

@index: Pointer to the current index in the format string

Return: Flags
*/
int get_flags(const char *format, int *index)
{
int j, current_index;
int flags = 0;
const char FLAGS_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
{
for (j = 0; FLAGS_CHARACTERS[j] != '\0'; j++)
{
if (format[current_index] == FLAGS_CHARACTERS[j])
{
flags |= FLAGS_VALUES[j];
break;
}
}
 if (FLAGS_CHARACTERS[j] == 0)
 	break;
}

*index = current_index - 1;

return flags;
}






Regenerate response

