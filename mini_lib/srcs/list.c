#include "../incl/mini_lib.h"

t_list		*new_list(void)
{
	t_list *list;

	if (!(list = (t_list*)memalloc(sizeof(t_list))))
		return (NULL);
	list->len = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_node		*new_node(void *data, size_t size)
{
	t_node *node;

	if (!(node = (t_node*)memalloc(sizeof(t_node))))
		return (NULL);
	mini_memcpy(&node->data, &data, size);
	node->size = size;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

#include <stdio.h>
t_tree	*list_to_nary(t_list **list)
{
	t_node	*node;
	t_tree	*nary;

	nary = new_tree();
	while ((*list)->tail)
	{
		printf("wile\n");
		if ((node = dequeue(list)))
			if (enqueue(&nary->children, node->data, sizeof(node->data)) == FAILURE)
				return (NULL);
	}
	return (nary);
}

//t_list	*va_to_list(va_list ap, int args)
//{
//	char 	*arg;
//	t_list	*list;
//
//	list = new_list();
//	return (list);
//}