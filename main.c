#include "monty.h"

variables variable;

/**
 * main - Start LIFO, FILO program
 * @ac: Number of arguments
 * @av: Pointer containing arguments
 * Return: 0 Success, 1 Failed
 */
int main(int ac, char **av)
{
	char *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_variables(&variable) != 0)
		return (EXIT_FAILURE);

	variable.file = fopen(av[1], "r");
	if (!variable.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&variable.buffer, &variable.temp, variable.file) != EOF)
	{
		opcode = strtok(variable.buffer, " \r\t\n");
		if (opcode != NULL)
			if (call_function(&variable, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		variable.line_num++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
