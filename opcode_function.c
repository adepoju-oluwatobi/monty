#include "monty.h"
/**
 * pall - Print list
 * @stack: Double linked list
 * @line_num: File line execution
 */
void pall(stack_list **stack, unsigned int line_num)
{
	stack_list *temp = *stack;
	(void) line_num;

	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push - Insert a new value in list
 * @stack: Double linked list
 * @line_num: File line execution
 */
void push(stack_list **stack, unsigned int line_num)
{
	stack_list *temp = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (line_num(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = malloc(sizeof(stack_list));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(num);
	if (variable.MODE == 0 || !*stack)
	{
		temp->next = *stack;
		temp->prev = NULL;
		if (*stack)
			(*stack)->prev = temp;
		*stack = temp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = temp;
		temp->prev = tm;
		temp->next = NULL;
	}
}

/**
 * pint - Print last node
 * @stack: Double linked list
 * @line_num: File line execution
 */
void pint(stack_list **stack, unsigned int line_num)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - Delete top of list
* @stack: Double linked list
* @line_num: File line execution
*/
void pop(stack_list **stack, unsigned int line_num)
{
	stack_list *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
