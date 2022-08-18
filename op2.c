#include "monty.h"

/**
 * fswap - function to remove element on top of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 * Return: nothing
 */

void fswap(stack_t **s, unsigned int linenum)
{
	stack_t *tmp;

	(void)linenum;
	if (s == NULL || *s == NULL || (*s)->next == NULL)
		print_error(NULL, NULL, 8, linenum);
	else
	{
		tmp = *s;
		tmp->prev = tmp->next;
		*s = (*s)->next;
		tmp->next = (*s)->next;
		(*s)->prev = NULL;
		(*s)->next = tmp;
	}
}

/**
 * fnop - doesn't do anything
 * @s: stack
 * @linenum: number of the line where nop was found
 */

void fnop(stack_t **s, unsigned int linenum)
{
	(void)s;
	(void)linenum;
}
