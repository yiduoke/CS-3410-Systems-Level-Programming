#include <stdio.h>
#include <stdlib.h>
#include "oList.h"

/**
 * This is the solution for OrderedLink List Assignment
 */

int string_length(char string[]){
    int c = 0;
    while (string[c] != '\0'){
        c++;
    }
    return c;
}

int main()
{
    char someString[800];
    gets( someString );

    printf("Input a sentence: ");

    int length = string_length(someString);
    printf("%s\n",someString);
    printf("%d\n", length);
    
    struct Link* basic_linked_list = build_basic(someString, 0, length);
    printf("Basic link-list: ");
    print_list(basic_linked_list);

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
