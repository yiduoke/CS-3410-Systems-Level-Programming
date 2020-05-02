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

int is_letter(char character){
    int ascii = (int) character;
    return ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122));
}

node_t *new_link(char data)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
//    node->value= 0;////////////////
    
    if (data == 'a' || data == 'e' || data == 'i' || data == 'o' || data == 'u' || data == 'y'){
        node -> value = 7;
    }
    else if (is_letter(data)){
        node -> value = 3;
    }
    else{
        node -> value = 11;
    }
    
    ///////////////////
    node->next = NULL;

    return(node);
}

node_t *new_node(char data){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    
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


node_t *insert_reverse(char c, int v, node_t *head){
    struct Link* previous = head;
    struct Link* current = head -> next;
    
    while (current && (v < current -> data)){
        previous = current;
        current = current -> next;
    }
    if ((previous -> value) == v){
        if ((previous -> data) == c){
            previous -> value = (previous -> value) + v;
        }
        else if (((previous -> data) < c)){
            node_t* new_node = new_link(c);
            previous -> next = new_node;
            new_node -> next = current;
        }
        else{
            node_t* new_node = new_link(c);
            char temp_data = previous -> data;
            int temp_value = previous -> value;
            
            previous -> next = new_node;
            new_node -> next = current;
            
            previous -> data = c;
            previous -> value = v;
            
            new_node -> data = temp_data;
            new_node -> value = temp_value;
        }
    }
    else {
        node_t* new_node = new_link(c);
        previous -> next = new_node;
        new_node -> next = current;
    }
    return head;
}

node_t *insert_basic(char c, int v, node_t *head){
    struct Link* current_node = head;
    while (current_node -> next){
        if (current_node -> data == c){
            current_node -> value = (current_node -> value) + v;
        }
        current_node = current_node -> next;
    }
    node_t* new_node = new_link(c);
    current_node -> next = new_node;
    return head;
}


node_t *build_basic(char in[], int start, int end){
    struct Link* head = new_link(in[start]);
    int i;
    for (i = start + 1; i < end; i++){
        head = insert_basic(in[i], (int)in[i], head);
    }
    return head;
}

node_t *build_ordered(char in[], int start, int end){
    struct Link* head = new_link(in[start]);
    int i;
    for (i = start + 1; i < end; i++){
        head = insert(in[i], (int)in[i], head);
    }
    return head;
}

node_t *build_reverse(char in[], int start, int end){
    struct Link* head = new_link(in[start]);
    int i;
    for (i = start + 1; i < end; i++){
        head = insert_reverse(in[i], (int)in[i], head);
    }
    return head;
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


node_t *insert(char c, int v, node_t *head){
    if (!head){
        return new_link(c);
    }
    
    struct Link* previous = head;
    struct Link* current = head -> next;
    
    while (current && (v > current -> data)){
        previous = current;
        current = current -> next;
    }
    if ((previous -> value) == v){
        if ((previous -> data) == c){
            previous -> value = (previous -> value) + v;
        }
        else if (((previous -> data) > c)){
            struct Link* new_node = new_link(c);
            previous -> next = new_node;
            new_node -> next = current;
        }
        else{
            struct Link* new_node = new_link(c);
            char temp_data = previous -> data;
            int temp_value = previous -> value;
            
            previous -> next = new_node;
            new_node -> next = current;
            
            previous -> data = c;
            previous -> value = v;
            
            new_node -> data = temp_data;
            new_node -> value = temp_value;
        }
    }
    else {
        struct Link* new_node = new_link(c);
        previous -> next = new_node;
        new_node -> next = current;
    }
    return head;
}

void print_list(node_t *node){
    while (node) {
        printf("%c ", node -> data);
        node = node -> next;
    }
    printf("\n");
}

void print_value(node_t *node){
    int sum = 0;
    while (node) {
        sum += node -> value;
        node = node -> next;
    }
    printf("%d\n", sum);
}
