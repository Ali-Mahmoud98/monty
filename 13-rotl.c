#include "monty.h"
/**
 * rotl - top element of the stack become last one.
 * @stack: pointer to pointer to stack_t.
 * @line_number: number.
*/
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr1, *ptr2;

    (void) stack;
    (void) line_number;
    if (arguments->stack_length < 2)
        return;
    ptr1 = arguments->stackHead;
    arguments->stackHead = ptr1->next;
    arguments->stackHead->prev = NULL;
    ptr2 = ptr1->next;
    while (ptr2)
    {
        if (!ptr2->next)
        {
            ptr2->next = ptr1;
            ptr1->prev = ptr2;
            ptr1->next = NULL;
            break;
        }
        ptr2 = ptr2->next;
    }
    
}