#include "monty.h"
/**
 * main - entry point
 * @argc: nb of arguments
 * @argv: array of strings
 * Return: 0 if success, EXIT_FAILURE if fail
 */
int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
		print_error(NULL, 1, 0);
	file = _fopen(argv[1]);
	if (file == NULL)
		exit(EXIT_FAILURE);
	if (_read(file) == -1)
		exit(EXIT_FAILURE);
	return (0);
}
