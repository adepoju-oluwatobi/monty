#include "monty.h"

variables variable;

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

	if (start_variables(&variable) != 0)
		return (EXIT_FAILURE);

	variable.file = fopen(argv[1], "r");
	if (!variable.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&variable.buff, &variable.tmp, variable.file) != EOF)
	{
		opcode = strtok(variable.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_funct(&variable, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		variable.line_num++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
