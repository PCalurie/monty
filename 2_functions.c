#include "monty.h"

/**
 * div - function divides the second top element of the stack
 * by the top element of the stack.
 * @stack: double pointer to the stack
 * @line_number: number  of the code
 */
void div(stack_t **stack, unsigned int line_number)
{

	stack_t *val = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

		if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}


	val = (*stack)->next;
	div = val->n;
	div /= (*stack)->n;
	pop(stack, line_number);
	val->n = div;
}
/**
 * mul - function multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: number of the line of code
 */
void mul(stack_t **stack, unsigned int line_number)
{

	stack_t *val = NULL;
	int mul = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->next;
	mul = val->n;
	mul *= (*stack)->n;
	pop(stack, line_number);
	val->n = mul;
}
/**
 * mod - function computes the rest of the division of the second top element 
 * of the stack by the top element of the stack
 * @stack: double pointer to the pointer
 * @line_number: number of the line of code
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *val = NULL;
	int mod = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}


	val = (*stack)->next;
	mod = val->n;
	mod %= (*stack)->n;
	pop(stack, line_number);
	val->n = mod;
}
