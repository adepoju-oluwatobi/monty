#include "monty.h"

vars var;

/**
 * main - Start LIFO, FILO program
 * @argc: Number of arguments
 * @argv: Pointer containing arguments
 * Return: 0 Success, 1 Failed
 */
int main(int argc, char **argv)
{
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(argv[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&var.buff, &var.tmp, var.file) != EOF)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_funct(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
