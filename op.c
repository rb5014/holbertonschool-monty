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
	if (s == NULL || *s == NULL)
		print_error(NULL, NULL, 6, linenum);
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
		print_error(NULL, NULL, 7, linenum);
	tmp = *s;
	*s = (*s)->next;
	free(tmp);

}
/**
 * fadd - function to add the two elements on top of the stack
 * @s: stack to modify
 * @linenum: line number of the instruction
 */
void fadd(stack_t **s, unsigned int linenum)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL)
		print_error(NULL, NULL, 9, linenum);
	(*s)->next->n += (*s)->n;
	fpop(s, linenum);
}
