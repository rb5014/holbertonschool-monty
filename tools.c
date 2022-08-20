#include "monty.h"

/**
 * is_number - check if string is a number
 * @s: string to check
 * Return: 0 if number, else -1
 */

int is_number(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0 && s[i] != '-')
			return (0);
	}
	return (1);

}

/**
 * free_listint - free memory of list
 * @head: pointer to head of the list
 */
void free_listint(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		free_listint(head->next);
	free(head);
}

/**
 * free_all - free everything at the same time
 * @head: pointer to the head of the list
 * @line: line read by _read (getline)
 * @file: file opened by _fopen (fopen)
 */
void free_all(stack_t *head, char *line, FILE *file)
{
	if (head)
		free_listint(head);
	if (line)
		free(line);
	if (file)
		fclose(file);
}
