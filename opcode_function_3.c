#include "monty.h"

/**
 * mul - s
 * @stack: Double linked list
 * @line_num: File line execution
 */
void mul(stack_list **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_num);
}


/**
 * mod - s
 * @stack: Double linked list
 * @line_num: File line execution
 */
void mod(stack_list **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_num);
}

/**
 * pchar - s
 * @stack: Double linked list
 * @line_num: File line execution
 */
void pchar(stack_list **stack, unsigned int line_num)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n))
	{
		printf("%c\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pstr - s
 * @stack: Double linked list
 * @line_num: File line execution
 */
void pstr(stack_list **stack, unsigned int line_num)
{
	stack_list *temp = *stack;
	(void) line_num;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (temp)
	{
		if (temp->n == 0)
			break;
		if (!isascii((temp)->n))
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
