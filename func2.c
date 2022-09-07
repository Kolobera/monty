#include "monty.h"
int dprintf(int fd, const char *format, ...);
/**
 * _pchar - prints top stack number as ascii
 * @node: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void _pchar(stack_t **node, unsigned int line_count)
{
	int num = 0;

	if (!*node || !node)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_count);
		exit_op();
		exit(EXIT_FAILURE);
	}
	num = (*node)->n;
	if ((num < 33) || (num > 127))
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_count);
		exit_op();
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar('\n');
}

/**
 * _pstr - prints stack as ascii code
 * @node: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void _pstr(stack_t **node, unsigned int line_count)
{
	stack_t *temp = *node;
    (void)line_count;

	while (temp && (temp->n != 0) && ((temp->n) > 32) && ((temp->n) < 128))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	putchar('\n');
}