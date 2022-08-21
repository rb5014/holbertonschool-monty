#include "monty.h"
/**
 * print_error - print error with line number
 * @errornum: error identifier
 * @linenum: line number where error was found
 * @arg: arg that isn't a file
 */

void print_error(char *arg, int errornum, unsigned int linenum)
{
	switch (errornum)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		break;
	case 3:
		fprintf(stderr, "L%u: unknown instruction %s\n", linenum, arg);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%u: usage: push integer\n", linenum);
		break;
	case 6:
		fprintf(stderr, "L%u: can't pint, stack empty\n", linenum);
		break;
	case 7:
		fprintf(stderr, "L%u: can't pop an empty stack\n", linenum);
		break;
	case 8:
		fprintf(stderr, "L%u: can't %s, stack too short\n", linenum, token);
		break;
	case 9:
		fprintf(stderr, "L%u: division by zero\n", linenum);
		break;
	}
	token = "error";
}
