#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define buffersize 30

/**
 * struct stack_element - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_element
{
	int n;
	struct stack_element *prev;
	struct stack_element *next;
} stack_list;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_list **stack, unsigned int line_num);
} instruct_list;


/**
 * struct glob_variable - golbal variableiables
 * @file: file name
 * @buffer: Getline bufferer
 * @temp: Getline counter
 * @dictionary: instruction dictionaryionary
 * @head: pointer to list
 * @line_num: Stores file current line
 * @MODE: Program configuration stack or queue
 */
typedef struct glob_variable
{
	FILE *file;
	char *buffer;
	size_t temp;
	instruct_list *dictionary;
	stack_list *head;
	unsigned int line_num;
	int MODE;
} variables;


extern variables variable;

/* ================================================================= */
/* main_file.c */
/* ================================================================= */
int start_variables(variables *variable);
instruct_list *create_instru();
int call_function(variables *variable, char *opcode);
void free_all(void);
int _is_digit(char *string);

/* ================================================================= */
/* opcode_function.c */
/* ================================================================= */
void pall(stack_list **stack, unsigned int line_num);
void push(stack_list **stack, unsigned int line_num);
void pint(stack_list **stack, unsigned int line_num);
void pop(stack_list **stack, unsigned int line_num);

/* ================================================================= */
/* opcode_function_2.c */
/* ================================================================= */
void swap(stack_list **stack, unsigned int line_num);
void add(stack_list **stack, unsigned int line_num);
void sub(stack_list **stack, unsigned int line_num);
void divi(stack_list **stack, unsigned int line_num);

/* ================================================================= */
/* opcode_function_3.c */
/* ================================================================= */
void mul(stack_list **stack, unsigned int line_num);
void mod(stack_list **stack, unsigned int line_num);
void pchar(stack_list **stack, unsigned int line_num);
void pstr(stack_list **stack, unsigned int line_num);

/* ================================================================= */
/* opcode_function_4.c */
/* ================================================================= */
void rotl(stack_list **stack, unsigned int line_num);
void rotr(stack_list **stack, unsigned int line_num);
void stack(stack_list **stack, unsigned int line_num);
void queue(stack_list **stack, unsigned int line_num);


#endif
