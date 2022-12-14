#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern char *token;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
FILE *_fopen(char *filename);
int _read(FILE *file);
int _find_f(stack_t **s, instruction_t *list, char **adr_line, int linenum);
int is_number(char *s);
void fpush(stack_t **s, unsigned int linenum);
void fpall(stack_t **s, unsigned int linenum);
void fpint(stack_t **s, unsigned int linenum);
void fpop(stack_t **s, unsigned int linenum);
void fswap(stack_t **s, unsigned int linenum);
void fadd(stack_t **s, unsigned int linenum);
void fsub(stack_t **s, unsigned int linenum);
void fdiv(stack_t **s, unsigned int linenum);
void fmul(stack_t **s, unsigned int linenum);
void _fmod(stack_t **s, unsigned int linenum);
void fnop(stack_t **s, unsigned int linenum);
void fpchar(stack_t **s, unsigned int linenum);
void print_error(char *arg, int errornum, unsigned int linenum);
void free_all(stack_t *head, char *line, FILE *file);
void free_listint(stack_t *head);
#endif
