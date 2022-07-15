#include "monty.h"

glob_vars globv;


/**
 * main - check the code.
 * @ac: number of command line arguments.
 * @av: pointer to array containing commad line arguments.
 *
 * Usage: monty file, where file is the path to the file containing Monty,
 * byte code.
 * If the user does not give any file or more than one argument to your,
 * program, print the error message USAGE: monty file, followed by a new,
 * line, and exit with the status EXIT_FAILURE.
 * If, for any reason, it’s not possible to open the file, print the error,
 * message Error: Can't open file <file>, followed by a new line, and exit,
 * with the status EXIT_FAILURE where <file> is the name of the file.
 * If the file contains an invalid instruction, print the error message,
 * L<line_number>: unknown instruction <opcode>, followed by a new line,
 * and exit with the status EXIT_FAILURE where is the line number where the,
 * instruction appears. Line numbers always start at 1.
 * The monty program runs the bytecodes line by line and stop if either,
 * it executed properly every line of the file, it finds an err in the file,
 * an error occured.
 * If you can’t malloc anymore, print the error message Error: malloc failed,
 * followed by a new line, and exit with status EXIT_FAILURE.
 * You have to use malloc and free and are not allowed to use any other,
 * function from man malloc (realloc, calloc, …)
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	stack_t *head;

	stack_init(&head);
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_reader(av[1], &head);
	exit(EXIT_SUCCESS);
}

/**
 * file_reader - process the whole monty file
 * @filename: str name of monty opcode file
 * @stack: double pointer to top of stack data struct
 * Return: return an error code or success
 **/
int file_reader(char *filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
	char *op;


	if (!filename)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	atexit(free_all);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		op = strtok(line, "\n\t\r ");
		line_number++;
		if (op)
			get_po(stack, op, line_number);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}


/**
 * stack_init - function that initializes all the things.
 * @head: double pointer to top of stack.
 *
 * Return: No return.
 **/
void stack_init(stack_t **head)
{
	*head = NULL;
	globv.top = head;
}

/**
 * free_all - function that frees all malloc'ed memory.
 *
 * Return: No return.
 **/
void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(globv.top);
	/* printf("glob.top->%p\n",  (void*)glob.top); */
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
