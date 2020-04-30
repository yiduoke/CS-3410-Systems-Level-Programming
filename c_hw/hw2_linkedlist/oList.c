#include <stdio.h>
#include <stdlib.h>
#include "oList.h"

/** Helper function that allocates a new node with the given
 * data, initializes the value at 0, and NULL for the next pointer.
 * We have created this function for you as it uses malloc and realize
 * it is probable that you are unfamiliar with it.
 * DON'T forget to "free" all the memory allocated before the terminating the
 * program.
 */

node_t *new_link(char data)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->value= 0;
    node->next = NULL;

    return(node);
}

/**
 * TODO: Implement functions defined in oList.h below
 */
