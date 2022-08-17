#include "monty.h"

/**
 * newnode - function to create newnode
 * @num: numero
 *
 * return: pointer sur newnode
 *

stack_t newnode()
{

}
*/

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
		return (NULL);
	node->n = p;
	node->prev = NULL;
	node->next = *s;

	if((*s) != NULL)
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

	for (i = 0; *s != NULL; i++)
	{
		printf("%d\n", (*s)->n);
		*s = (*s)->next;
	}
}
