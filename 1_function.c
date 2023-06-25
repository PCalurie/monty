#include "monty.h"
/**
 * nop - this function does nothing
 * @stack: double pointer to the stack
 * @line_number: number of the line of code
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * swap - swaps over the top two elements of a stack
 * @stack: double pointer to the stack
 * @line_number: number of the line of code
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *val;
	int temp = 0;

	val = *stack;

	if (val == NULL || val->next == NULL)
	{
		fprintf(stderr, "L%u: Error: can't swap, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = val->n;
		val->n = val->next->n;
		val->next->n = temp;
	}
}
/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: number of the line of the code
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *val = NULL;
	int sum = 0;

	if (val == NULL || val->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		val = (*stack)->next;
		sum = (*stack)->n;
		sum += (*stack)->next->n;
		pop(stack, line_number);
		val->n = sum;
	}
}
/**
 * pchar - prints the top elements of a stack
 * @stack: double pointer to the stack
 * @line_number: number of the line of code
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c:\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * sub - subtracts top elements from the second top of the stack
 * @stack: double pointer to the stack
 * @line_number: number of the line of code
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *val = NULL;
	int sub;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->next;
	sub = val->n;
	sub -= (*stack)->n;
	pop(stack, line_number);
	val->n = sub;
}
