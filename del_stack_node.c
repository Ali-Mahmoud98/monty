#include "monty.h"
/**
* delete_stack_node - delete node at the head/top
*/
void delete_stack_Top_node(void)
{
	stack_t *tmp;

	tmp = arguments->stackHead;
	arguments->stackHead = tmp->next;
	free(tmp);
}