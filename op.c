#include "monty.h"
/**
 * fpush - function to push new node
 * @s: stack to modify
 * @linenum: line number of the instruction
 * Return: nothing
 */

void fpush(stack_t **s, unsigned int linenum)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		print_error(NULL, 4, linenum);
		return;
	}
	node->n = atoi(token);
	node->prev = NULL;
	node->next = *s;

	if ((*s) != NULL)
		(*s)->prev = node;

	*s = node;
}

/**
 * fpall - function to print all elements of the stack
 * @s: stack to print
 * @linenum: line number of the instruction
 * Return: nothing
 */

void fpall(stack_t **s, unsigned int linenum)
{
	stack_t *tmp;

	(void)linenum;
	tmp = *s;
	while (tmp != NULL)
	{
		printf("%d\n", (tmp)->n);
		tmp = (tmp)->next;
	}
}

/**
 * fpint - function to print all elements of the stack
 * @s: stack to print
 * @linenum: line number of the instruction
 * Return: nothing
 */

void fpint(stack_t **s, unsigned int linenum)
{
	if (s == NULL || *s == NULL)
	{
		print_error(NULL, 6, linenum);
		return;
	}
	printf("%d\n", (*s)->n);
}


/**
 * fpop - function to remove element on top of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void fpop(stack_t **s, unsigned int linenum)
{
	stack_t *tmp;

	if (s == NULL || *s == NULL)
	{
		print_error(NULL, 7, linenum);
		return;
	}
	tmp = *s;
	*s = (*s)->next;
	free(tmp);
	tmp = NULL;
}
/**
 * fadd - function to add the two elements on top of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void fadd(stack_t **s, unsigned int linenum)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL)
	{
		print_error(NULL, 8, linenum);
		return;
	}
	(*s)->next->n += (*s)->n;
	fpop(s, linenum);
}
