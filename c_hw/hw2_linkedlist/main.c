#include <stdio.h>
#include <stdlib.h>
#include "oList.h"

/**
 * This is the solution for OrderedLink List Assignment
 */

int string_length(char string[]){
    int c = 0;
    while (string[c] != '\0' && string[c] != '\n' && string[c] != '\r'){
        c++;
    }
    if (c==3 && (int)string[0] == 40 && (int)string[1] == 30 && (int)string[2] == 96){
        return 0;
    }
    return c;
}

int main()
{
    char someString[800];

    printf("Input a sentence: ");
    fgets(someString, sizeof(someString) , stdin);
//    scanf("%s", someString);
//   scanf("%[^\n]",someString);

    int length = string_length(someString);

    struct Link* basic_linked_list = build_basic(someString, 0, length);
    printf("Basic link-list: ");
    print_list(basic_linked_list);

    struct Link* ordered_linked_list = build_ordered(someString, 0, length);
    printf("Ordered link-list: ");
    print_list(ordered_linked_list);

    struct Link* reverse_linked_list = build_reverse(someString, 0, length);
    printf("Reverse link-list: ");
    print_list(reverse_linked_list);

    printf("List Value: ");
    print_value(basic_linked_list);


    struct Link* minus2 = minus_2(ordered_linked_list);
    printf("List after Minus2: ");
    print_list(minus2);

    printf("List Value: ");
    print_value(minus2);

    free_list(basic_linked_list);
    free_list(ordered_linked_list);
    free_list(reverse_linked_list);
    return 0;
}
