#include "monty.h"

/**
 * swap - Delete top of list
 * @stack: Double linked list
 * @line_num: File line execution
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - add the top two elements of the stack
 * @stack: Double linked list
 * @line_num: File line execution
 */
void add(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_num);
}

/**
 * sub - substract the top two elements of the stack
 * @stack: Double linked list
 * @line_num: Line counter
 */
void sub(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_num);
}

/**
 * divi - divide the top two elements of the stack
 * @stack: Double linked list
 * @line_num: File line counter
 */
void divi(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
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
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_num);
}
