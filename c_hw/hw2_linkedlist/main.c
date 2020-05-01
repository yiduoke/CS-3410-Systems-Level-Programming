#include <stdio.h>
#include <stdlib.h>
#include "oList.h"

/**
 * This is the solution for OrderedLink List Assignment
 */

int is_letter(char character){
    int ascii = (int) character;
    return ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122));
}

node_t *new_link(char data){
    struct Link* node = NULL;
    
    if (data == 'a' || data == 'e' || data == 'i' || data == 'o' || data == 'u' || data == 'y'){
        node -> value = 7;
    }
    else if (is_letter(data)){
        node -> value = 3;
    }
    else{
        node -> value = 11;
    }
    
    node -> data = data;
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

node_t *minus_2(node_t *head){
    if (head && (head -> next)){
        struct Link* running_antepenultimate = head;
        struct Link* running_penultimate = head -> next;
        struct Link* running_ultimate = (head -> next) -> next;
        
        while (running_ultimate) {
            running_antepenultimate = running_penultimate;
            running_penultimate = running_ultimate;
            running_ultimate = running_ultimate -> next;
        }
        free(running_antepenultimate);
        return head;
    }
    else{
        return NULL;
    }
}

void free_list(node_t *head){
    struct Link* temporary;
    while(head){
        temporary = head;
        head = head->next;
        free(temporary);
    }
}

//TODO: meow
node_t *insert(char c, int v, node_t *head){
    struct Link* previous = head;
    struct Link* current = head -> next;
    while (current && (v > current -> data)){
        previous = current;
        current = current -> next;
    }
    if ((previous -> value) == v){
        previous -> value = (previous -> value) + v;
    }
    else{
        struct Link* new_node = new_link(c);
        previous -> next = new_node;
        new_node -> next = current;
    }
    return head;
}

void print_list(node_t *node){
    while (node) {
        printf("%d ", node -> data);
        node = node -> next;
    }
    printf("\n");
}

void print_value(node_t *node){
    int sum = 0;
    while (node) {
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
