#include <stdio.h>
#include <stdlib.h>
#include "oList.h"

/**
 * This is the solution for OrderedLink List Assignment
 */

node_t *new_link(char data){
    struct Link* node = NULL;
    node = (struct Link*)malloc(sizeof(struct Link));
    node -> data =  (int) data;
    node -> next = NULL;
    return node;
}

// TODO: meow
node_t *build_basic(char in[], int start, int end){
    return NULL;
}

//TODO: meow
node_t *build_ordered(char in[], int start, int end){
    return NULL;
}

//TODO: meow
node_t *build_reverse(char in[], int start, int end){
    return NULL;
}

//TODO: meow
node_t *minus_2(node_t *head){
    return NULL;
}

//TODO: meow
void free_list(node_t *head){
    
}

//TODO: meow
node_t *insert(char c, int v, node_t *head){
    return NULL;
}

//TODO: meow
void print_list(node_t *node){
    while (node != NULL) {
        printf("%d ", node -> data);
        node = node -> next;
    }
    printf("\n");
}

//TODO: meow
void print_value(node_t *node){
    int sum = 0;
    while (node != NULL) {
        sum += node -> data;
        node = node -> next;
    }
    printf("%d\n", sum);
}

int main()
{
    // char someString[800]; // commented out so the code can compile [Read input into this structure]

    printf("Input a sentence: ");
    
    //TODO: Read in the input from the command line:

    int len;

    //TODO: Calculate the length of input strings
    
    //TODO: Build basic list structure
    printf("Basic link-list: ");
    //TODO: Print the basic list structure

    //TODO: Build ordered list structure
    printf("Ordered link-list: ");
    //TODO: Print the ordered list structure

    //TODO: Build reverse list structure
    printf("Reverse link-list: ");
    // TODO: Print the reverse of the ordered list

    printf("List Value: ");
    //TODO: Print the value of the list


    //TODO: Get list after minus2
    printf("List after Minus2: ");
    //TODO: Print list after minus2

    printf("List Value: ");
    //TODO: Print value after minus2

    //TODO: free all memory
    return 0;
}
