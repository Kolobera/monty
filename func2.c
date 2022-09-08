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

/**
 * _rotl - rotates the stack to the top
 * @head: double pointer to the begining of the list
 * @line_count: script line number
 */
void _rotl(stack_t **head, unsigned int line_count)
{
	stack_t *temp, *top;
	(void) line_count;

	if (!head || !(*head) || !(*head)->next)
		return;
	temp = *head;
	top = temp->next;
	top->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;

	(*head)->next = NULL;
	(*head)->prev = temp;

	*head = top;
}

/**
 * _rotr - rotates the stack to the bottom
 * @head: double pointer to the begining of the list
 * @line_count: script line number
 */

void _rotr(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	(void) line_count;

	if (!head || !(*head) || !(*head)->next)
		return;

	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*head)->prev = temp;
	(*head) = temp;
}

