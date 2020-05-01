  
/**
 * This is a C header file.
 * You are expected to implement all the functions mentioned below
 */

/*
 * A linked list is a struct that has data, a value, and a pointer to
 * the "next" node
 */
typedef struct Link {
    char data;
    int value;
    struct Link *next;
} node_t;


/* Helper function that allocates a new node with the
 * given character [data] and NULL next pointer.
 */
extern node_t *new_link(char data);

/* Functions to construct different types of lists from in[start...end]
 * (3 Types): basic, ordered, reversed
 */
extern node_t *build_basic(char in[], int start, int end); 
extern node_t *build_ordered(char in[], int start, int end);
extern node_t *build_reverse(char in[], int start, int end);

/* Performs the Minus2 operation on an ordered linked-list.
 * [head] is the root of the ordered linked-list, could be NULL if 
 * list is empty
 */
extern node_t *minus_2(node_t *head);


/* Frees the entire list with root [head]
 * input could be NULL if list is empty
 */
extern void free_list(node_t *head);


/*
 * Helper function for creating an ordered list
 * Inserts a new node with data [c] and value [v] into the list with root [head]
 * at the correct position according to the ordering rules
 *
 * Returns the head of the list after new node has been inserted
 */
extern node_t *insert(char c, int v, node_t *head);

/*
 * Prints the sequential list of the linked-list given the root [node]
 */
extern void print_list(node_t *node);


/* Prints the value of the list given the root [node] */
extern void print_value(node_t *node);
