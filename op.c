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
		fprintf(stderr, "L%d: Couldn't allocate memory for new node\n", linenum);
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
	int i;

	if (s == NULL)
	{
		fprintf(stderr, "L%d: Stack doesn't exist\n", linenum);
		exit(EXIT_FAILURE);
	}
	for (i = 0; *s != NULL; i++)
	{
		printf("%d\n", (*s)->n);
		*s = (*s)->next;
	}
}
