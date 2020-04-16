#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct arraylist {
    int* array;
    unsigned int capacity;  // the max number of elements the array can hold
    unsigned int length;    // the number of integers stored in the list
} arraylist;


// Doubles the size of the arraylist if the number of elements is equal to the
// size of the array
void grow(arraylist* a) {
    if (a->length == a->capacity) {
        a->capacity <<= 1; // double the capacity value
        // extend the allocated memory
        int* new_arr = realloc(a->array, a->capacity * sizeof(int));
        if (new_arr == NULL) {
            printf("Not enough memory to grow the arraylist\n");
            exit(1);
        }
        a->array = new_arr;
    }
}

////////////////////////////////////////////////////////////////////////////////
//Functions that you need to implement:
/*
 * Append the value x to the end of the arraylist. If necessary, double the
 * capacity of the arraylist.
 */
void arraylist_add(arraylist* a, int x) {
}

/*
 * Store x at the specified index of the arraylist. Previously stored values
 * should be moved back rather than overwritten. It is undefined behavior to
 * insert an element with an index beyond the end of an arraylist.
 */
void arraylist_insert(arraylist* a, unsigned int index, int x) {
}

/*
 * Free any memory used by that arraylist.
 */
void arraylist_free(arraylist* a) {
    // Hint: How many times is malloc called when creating a new arraylist?
}

////////////////////////////////////////////////////////////////////////////////

arraylist* arraylist_new()
{
    arraylist* a = (arraylist*)malloc(sizeof(arraylist));
    a->array = (int*)malloc(4 * sizeof(int));
    a->capacity = 4;
    a->length = 0;

    return a;
}

void arraylist_remove(arraylist* a, unsigned int index)
{
    for (unsigned int i = index; i < a->length - 1; i++)
        a->array[i] = a->array[i + 1];

    --a->length;
}

int arraylist_get(arraylist* a, unsigned int index)
{
    return a->array[index];
}

void arraylist_print(arraylist* a)
{
    printf("[");
    if (a->length > 0) {
        for (unsigned int i = 0; i < a->length - 1; i++)
            printf("%d, ", arraylist_get(a, i));
        printf("%d", arraylist_get(a, a->length - 1));
    }

    printf("]\n");
}

int main(int argc, char* argv[])
{
    // START OF TEST
    arraylist* a = arraylist_new();
    int ints[] = { 0, 1, 2, 3, 4, 5, 100 };

    arraylist_add(a, ints[0]);
    arraylist_add(a, ints[1]);
    arraylist_add(a, ints[2]);
    arraylist_add(a, ints[3]);
    arraylist_add(a, ints[4]);
    arraylist_add(a, ints[5]);
    arraylist_print(a);

    for (unsigned int i = 0; i < a->length; i++) {
        arraylist_insert(a, i, ints[6]);
        printf("Insert position %d: ", i);
        arraylist_print(a);
        arraylist_remove(a, i);
    }
    printf("Clean: ");
    arraylist_print(a);

    arraylist_free(a);
    // END OF TEST

    return 0;
}
