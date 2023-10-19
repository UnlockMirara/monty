#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX_LINE_SIZE 1024

/**
 * main - Entry point for the Monty code interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_SIZE];
	stack_t *stack = NULL;
	unsigned int counter = 0;
	size_t line_length;

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		counter++;

	line_length = strlen(line);
		if (line_length > 0 && line[line_length - 1] == '\n')
		{
			line[line_length - 1] = '\0';
		}

		execute(line, &stack, counter, file);
	}

	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
