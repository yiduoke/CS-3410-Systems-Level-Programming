#include <stdio.h>

int main()
{
    char str1[100];
    char str2[100];
    int flag=0;

    printf("Input first string: ");
    scanf("%s", str1);
    printf("Input second string: ");
    scanf("%s", str2);

    // YOUR CODE STARTS HERE

    // Check if str2 is an anagram of str1.

    // YOUR CODE ENDS HERE

    if(flag==1)
        printf("%s is not an anagram of %s\n", str2, str1);
    else
        printf("%s is an anagram of %s\n", str2, str1);

    return 0;
}