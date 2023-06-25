#include "monty.h"
/**
 * usage_error - prints a usage error
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * open_error - prints an opening file error
 * @file: pointer to the file tobe opened
 */
void open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
/**
 * push_error - prints an error after pushing failure
 * @fd: file descriptor
 * @line: buffer
 * @line_number: buffer line number
 * @stack: stack used
 */
void push_error(FILE *fd, char *line, stack_t *stack, int line_number)
{
	fprintf(stderr, "L%u: usage:  push integer\n", line_number);
	fclose(fd);
	_free(stack);
	free(line);
	exit(EXIT_FAILURE);
}
/**
 * instr_error - prints an error when a wrong instr inputed
 * @fd: file descriptor
 * @stack: pointer to stack
 * @line_number: number of the line
 * @line: pointer to the buffer
 * @val: pointer to instruction inputed
 */
void instr_error(FILE *fd, char *line, stack_t *stack, char *val,
		int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s", line_number, val);
	fclose(fd);
	_free(stack);
	free(line);
	exit(EXIT_FAILURE);
}
