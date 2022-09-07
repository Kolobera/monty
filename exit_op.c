#include "monty.h"

/**
 * _nop - doesn’t do anything
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * exit_op - performs exit operations (free/close)
 * Return: No Return
 */
void exit_op(void)
{
	free(global.gbuff);
	fclose(global.file);
	free_stack_t(global.headstack);
}