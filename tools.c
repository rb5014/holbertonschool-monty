#include "monty.h"

/**
 * is_number - check if string is a number
 * @s: string to check
 *
 * Return: 0 if number, else -1
 */

int is_number(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0 && s[i] != '-')
			return (0);
	}
	return (1);

}

void free_listint(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		free_listint(head->next);
	free(head);
}
