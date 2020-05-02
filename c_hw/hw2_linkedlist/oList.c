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

int is_vowel(char data){
    return (data == 'a' || data == 'e' || data == 'i' || data == 'o' || data == 'u' || data == 'y' || data == 'A' || data == 'E' || data == 'I' || data == 'O' || data == 'U' || data == 'Y');
}

int get_value(char data){
    if (is_vowel(data)){
        return 7;
    }
    else if (is_letter(data)){
        return 3;
    }
    else{
        return 11;
    }
}

node_t *new_link(char data)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node -> value = get_value(data);
    node->next = NULL;

    return(node);
}

node_t *new_node(char data){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    
    if (is_vowel(data)){
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

node_t *remove_duplicates(node_t *head){
    struct Link* current = head;

    if (!current){
        return NULL;
    }

    while (current->next){
        if (current->data == current->next->data){
            current -> value = (current -> value) + (current->next-> value);
            free(current->next);
            current->next = current->next->next;
        }
        else{
            current = current->next;
        }
    }
    return head;
}


node_t *insert_reverse(char c, int v, node_t *head){
    node_t* new_node = new_link(c);
    
    if (!head || head->value > v || (head->value == v && head->data > c)){
        new_node -> next = head;
        head = new_node;
        return head;
    }
    
    struct Link* current = head;
    
    while (current->next && (current->next->value < v || (current->next->value == v && c < current->next-> data < c))){
        current = current -> next;
    }

    new_node -> next = current->next;
    current->next = new_node;
    return head;
}

node_t *insert_basic(char c, int v, node_t *head){
    struct Link* current_node = head;
    while (current_node -> next){
        if (current_node -> data == c){
            current_node -> value = (current_node -> value) + v;
            return head;
        }
        current_node = current_node -> next;
    }
    if (current_node -> data == c){
        current_node -> value = (current_node -> value) + v;
        return head;
    }
    node_t* new_node = new_link(c);
    current_node -> next = new_node;
    return head;
}


node_t *build_basic(char in[], int start, int end){
    struct Link* head = new_link(in[start]);
    int i;
    for (i = start + 1; i < end; i++){
        head = insert_basic(in[i], get_value(in[i]), head);
    }
    return head;
}

node_t *build_ordered(char in[], int start, int end){
    struct Link* head = NULL;
    int i;
    for (i = start; i < end; i++){
        head = insert(in[i], get_value(in[i]), head);
    }
    return remove_duplicates(head);
}

node_t *build_reverse(char in[], int start, int end){
    struct Link* head = NULL;
    int i;
    for (i = start; i < end; i++){
        head = insert_reverse(in[i], get_value(in[i]), head);
    }
    return remove_duplicates(head);
}

node_t *minus_2(node_t *head){
    if (!head || !(head -> next) || !((head -> next)->next)){
        return NULL;
    }
    
    struct Link* running_antepenultimate = head;
    while (running_antepenultimate -> next -> next-> next) {
        running_antepenultimate = running_antepenultimate -> next;
    }
    struct Link* penultimate = running_antepenultimate -> next;
    free_list(penultimate);
    running_antepenultimate -> next = NULL;
    return head;
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
    node_t* new_node = new_link(c);
    
    if (!head || head->value < v || (head->value == v && head->data < c)){
        new_node -> next = head;
        head = new_node;
        return head;
    }
    
    struct Link* current = head;
    
    while (current->next && (current->next->value > v || (current->next->value == v && c < current->next-> data > c))){
        
        current = current -> next;
    }

    new_node -> next = current->next;
    current->next = new_node;
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
