#include "monty.h"

int value;

/**
 * createNode - create a new node
 * @n: node value
 * Return: new node
 */
stack_t *createNode(int n)
{
	stack_t *new = NULL;

	new = mallock(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}
/**
 * push - pushes new nodes in the stack
 * @stack: double pointer to the stack
 * @line_number: number of the line of code
 */
void push(stack_t **stack, unsingned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	if (*stack != NULL)
	{
		(*stack)->prev = new;
	*stack = new;
	}
}
/**
 * pall - prints all the values in a stack
 * @stack: double pointer to the stack
 * @line_number: number of the line of code
 */
void pall(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf((stderr, "L%u: can't pint, stack empty\n", line_number);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	fprint(stdout, "&d\n" (*stack)->n);
}
/**
 * pop - remove a node from a stack
 * @stack: double pointer to the stack
 * @line_number: number of the line of code
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		_free(*stack);
		if (temp)
			temp->prev = NULL;

		*stack = temp;
	}
}
