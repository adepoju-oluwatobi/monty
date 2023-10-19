#include "monty.h"

/**
 * start_variables - Fake rand to jackpoint Giga Millions
 * @var: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int start_variables(variables *variable)
{
	variable->file = NULL;
	variable->buff = NULL;
	variable->tmp = 0;
	variable->dict = create_instru();
	if (variable->dict == NULL)
		return (EXIT_FAILURE);
	variable->head = NULL;
	variable->line_num = 1;
	variable->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_instru - Create new functions dictionary
 * Return: Dictionary pointer
 */
instruction_t *create_instru()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "swap", ptr[4].f = swap;
	ptr[5].opcode = "add", ptr[5].f = add;
	ptr[6].opcode = "nop", ptr[6].f = NULL;
	ptr[7].opcode = "sub", ptr[7].f = sub;
	ptr[8].opcode = "div", ptr[8].f = divi;
	ptr[9].opcode = "mul", ptr[9].f = mul;
	ptr[10].opcode = "mod", ptr[10].f = mod;
	ptr[11].opcode = "pchar", ptr[11].f = pchar;
	ptr[12].opcode = "pstr", ptr[12].f = pstr;
	ptr[13].opcode = "rotl", ptr[13].f = rotl;
	ptr[14].opcode = "rotr", ptr[14].f = rotr;
	ptr[15].opcode = "stack", ptr[15].f = stack;
	ptr[16].opcode = "queue", ptr[16].f = queue;
	ptr[17].opcode = NULL, ptr[17].f = NULL;

	return (ptr);
}

/**
 * call_funct - Call Functions
 * @variable: Global variables
 * @opcode: Command to execute
 * Return: None
 */
int call_funct(variables *variable, char *opcode)
{
	int i;

	for (i = 0; variable->dict[i].opcode; i++)
		if (strcmp(opcode, variable->dict[i].opcode) == 0)
		{
			if (!variable->dict[i].f)
				return (EXIT_SUCCESS);
			variable->dict[i].f(&variable->head, variable->line_num);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			variable->line_num, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * free_all - Clean all program mallocs
 * Return: None
 */
void free_all(void)
{
	if (variable.buff != NULL)
		free(variable.buff);
	if (variable.file != NULL)
		fclose(variable.file);
	free(variable.dict);
	if (variable.head != NULL)
	{
		while (variable.head->next != NULL)
		{
			variable.head = variable.head->next;
			free(variable.head->prev);
		}
		free(variable.head);
	}
}

/**
 * _isdigit - Clean all program mallocs
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
