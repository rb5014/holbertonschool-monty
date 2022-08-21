#include "monty.h"

/**
 * fmod - divides the second top element of the stack
 * by the top element of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void fmod(stack_t **s, unsigned int linenum)
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