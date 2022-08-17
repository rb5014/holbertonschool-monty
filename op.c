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
	(void)s;
	printf("In fpush, p:%d    , linenum: %d\n", p, linenum);
}
/**
 * fpall - function to print all elements of the stack
 * @s: stack to print
 * @linenum: line number of the instruction
 * Return: nothing
 */

void fpall(stack_t **s, unsigned int linenum)
{
	(void)s;
	printf("In fpall, p:%d    , linenum: %d\n", p, linenum);
}
