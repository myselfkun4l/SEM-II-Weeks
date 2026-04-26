#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], copy[100];
    int i, len;

    printf("Enter first string: ");
    fgets(s1, sizeof(s221), stdin);

    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);
    
    
    strcat(s1, s2);
    printf("\n(A) Addition (Joined): %s", s1);

    strcpy(copy, s1);
    printf("\n(B) Copy of first string: %s", copy);
    
    len = strlen(s1);
    for (i = 0; i < len / 2; i++) {
        char temp = s1[i];
        s1[i] = s1[len - i - 1];
        s1[len - i - 1] = temp;
    }
    printf("\n(C) Reverse of joined string: %s\n", s1);
    
    len = strlen(s1);
    printf("\n(D) Length of string: %d", len);

    return 0;
}

