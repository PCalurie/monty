#include "monty.h"
cmd_t cmd = {NULL, NULL};
/**
 * execute - function executes a bytecode
 * argv: arguments
 */
void execute(char *argv)
{
	int c_line = 0, r = 0;
	size_t bufsize = 0;
	char *token = NULL, *val = NULL;
	stack_t *stack = NULL;

	cmd.fd = fopen(argv, "r");

	if (cmd.fd)
	{
		while (getline(&cmd.line, &bufsize, cmd.fd) != -1)
		{
			c_line++;
			token = strtok(NULL, " \n\t\r");
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')
				continue;
			val = strtok(NULL, " \n\t\r");
			r = get_op(&stack, token, val, c_line);
			if (r == -1)
				instr_error(cmd.fd, cmd.line, stack, token, c_line);
		}
		free(cmd.line);
		_free(stack);
		fclose(cmd.fd);
	}
	else
		pen_error(argv);
}
