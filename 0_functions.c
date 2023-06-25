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

	new = malloc(sizeof(stack_t));
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
void push(stack_t **stack, unsigned int line_number)
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
	stack_t *tmp = NULL;
	(void)line_number;

	tmp = *stack;

	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
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
/**
 * pint - function prints the value at the top of the stack,
 * followed by a new line
 * @stack: double pointer to the stack
 * @line_number: number to the line of code
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%d\n", (*stack)->n);

}
