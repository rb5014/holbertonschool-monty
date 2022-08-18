#include "monty.h"
int p;
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
		print_error(NULL, NULL, 4, linenum);
		exit(EXIT_FAILURE);
	}

	node->n = p;
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
	(void)linenum;
	if (s == NULL || *s == NULL)
		print_error(NULL, NULL, 6, linenum);
	else
		printf("%d\n", (*s)->n);
}


/**
 * fpop - function to remove element on top of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 * Return: nothing
 */

void fpop(stack_t **s, unsigned int linenum)
{
	stack_t *tmp;

	(void)linenum;
	if (s == NULL || *s == NULL)
		print_error(NULL, NULL, 7, linenum);
	else
	{
		tmp = *s;
		*s = (*s)->next;
		free(tmp);
	}
}


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
