#include "monty.h"

/**
 * rotl - s
 * @stack: Double linked list
 * @line_num: File line execution
 */
void rotl(stack_list **stack, unsigned int line_num)
{
	stack_list *tm = *stack;
	(void) line_num;

	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	while (tm->next)
		tm = tm->next;
	tm->next = *stack;
	(*stack) = (*stack)->next;
	tm->next->next = NULL;
	tm->next->prev = tm;
}

/**
 * rotr - s
 * @stack: Double linked list
 * @line_num: File line execution
 */
void rotr(stack_list **stack, unsigned int line_num)
{
	stack_list *temp;
	(void) line_num;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	while (temp->next)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*stack)->prev = temp;
	*stack = temp;

}

/**
 * stack - s
 * @stack: Double linked list
 * @line_num: File line execution
 */
void stack(stack_list **stack, unsigned int line_num)
{
	(void) line_num;
	(void) stack;

	variable.MODE = 0;
}

/**
 * queue - s
 * @stack: Double linked list
 * @line_num: File line execution
 */
void queue(stack_list **stack, unsigned int line_num)
{
	(void) line_num;
	(void) stack;

	variable.MODE = 1;
}
