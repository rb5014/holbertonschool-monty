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
	{
		print_error(NULL, 8, linenum);
		return;
	}
		tmp = *s;
		tmp->prev = tmp->next;
		*s = (*s)->next;
		tmp->next = (*s)->next;
		(*s)->prev = NULL;
		(*s)->next = tmp;
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

/**
 * fsub - function to sub the top element from the 2nd top element
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void fsub(stack_t **s, unsigned int linenum)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL)
	{
		print_error(NULL, 8, linenum);
		return;
	}
	(*s)->next->n -= (*s)->n;
	fpop(s, linenum);
}

/**
 * fdiv - divides the second top element of the stack
 * by the top element of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void fdiv(stack_t **s, unsigned int linenum)
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
	(*s)->next->n /= (*s)->n;
	fpop(s, linenum);
}

/**
 * fmul - multiplies the second top element of the stack
 * with the top element of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void fmul(stack_t **s, unsigned int linenum)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL)
	{
		print_error(NULL, 8, linenum);
		return;
	}
	(*s)->next->n *= (*s)->n;
	fpop(s, linenum);
}
