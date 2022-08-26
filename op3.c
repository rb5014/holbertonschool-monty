#include "monty.h"

/**
 * _fmod - divides the second top element of the stack
 * by the top element of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void _fmod(stack_t **s, unsigned int linenum)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL)
	{
		print_error(NULL, 8, linenum);
		return;
	}
	if ((*s)->n == 0)
	{
		print_error(NULL, 9, linenum);
		return;
	}
	(*s)->next->n %= (*s)->n;
	fpop(s, linenum);
}

/**
 * fpchar - prints the char at the top of the stack, followed by a new line
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void fpchar(stack_t **s, unsigned int linenum)
{
	if (s == NULL || *s == NULL)
	{
		print_error(NULL, 6, linenum);
		return;
	}
	if ((*s)->n < 0 || (*s)->n > 127)
	{
		print_error(NULL, 10, linenum);
		return;
	}
	printf("%c\n");
}
