#include "shell.h"

/**
 * list_to_strings - this returns an array of strings of the list->str
 * @head: the pointer to the first node
 *
 * Return: the array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t a = list_len(head), b;
	char **strs;
	char *str;

	if (!head || !a)
		return (NULL);
	strs = malloc(sizeof(char *) * (a + 1));
	if (!strs)
		return (NULL);
	for (a = 0; node; node = node->next, a++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (b = 0; b < a; b++)
				free(strs[b]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[a] = NULL;
	return (strs);
}

/**
 * print_list - prints all the elements of a list_t linked list
 * @h: the pointer to the first node
 *
 * Return: the size of the list
 */

size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * list_len - determines the length of a linked list
 * @h: the pointer to the first node
 *
 * Return: the size of the list
 */

size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * get_node_index - gets index of node
 * @head: the pointer to list head
 * @node: the pointer to the node
 *
 * Return: index of node or -1 otherwise
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t a = 0;

	while (head)
	{
		if (head == node)
			return (a);
		head = head->next;
		a++;
	}
	return (-1);
}

/**
 * node_starts_with - returns node with string that starts with prefix
 * @node: the pointer to list head
 * @prefix: the string to match
 * @c: the next character after prefix to match
 *
 * Return: the match node or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *q = NULL;

	while (node)
	{
		q = starts_with(node->str, prefix);
		if (q && ((c == -1) || (*q == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
