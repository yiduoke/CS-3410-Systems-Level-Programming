#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100];
    char str2[100];
    int flag=0;

    printf("Input first string: ");
    scanf("%s", str1);
    printf("Input second string: ");
    scanf("%s", str2);
    char temp;

    // YOUR CODE STARTS HERE

    // Check if str2 is an anagram of str1.
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2){
        flag = 0;
    }
    else{
        char strr1[100];
        strcpy(strr1, str1);
        char strr2[100];
        strcpy(strr2, str2);

        // insertion sort for the string
        for (int i = 0; i < len1 - 1; i++) {
            for (int j = i+1; j < len1; j++) {
                if (strr1[i] > strr1[j]) {
                    temp = strr1[i];
                    strr1[i] = strr1[j];
                    strr1[j] = temp;
                }
            }
        }
        
        for (int i = 0; i < len1-1; i++) {
            for (int j = i+1; j < len1; j++) {
                if (strr2[i] > strr2[j]) {
                    temp = strr2[i];
                    strr2[i] = strr2[j];
                    strr2[j] = temp;
                }
            }
        }
        if (!strcmp(strr1, strr2)){
            flag = 0;
        }
        else{
            flag = 1;
        }
    }

    // YOUR CODE ENDS HERE

    if(flag==1)
        printf("%s is not an anagram of %s\n", str2, str1);
    else
        printf("%s is an anagram of %s\n", str2, str1);

    return 0;
}
