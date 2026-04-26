#include <stdio.h>
#include <string.h>

int main() {
    char str[100] ;
    char word[20] ;
    char result[100];
    int i, j, k, found;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("Enter word to remove: ");
    scanf("%s", word);

    int strLen = strlen(str);
    int wordLen = strlen(word);
    int r = 0;

    for (i = 0; i < strLen; i++) {
        found = 1;
        
        for (j = 0; j < wordLen; j++) {
            if (str[i + j] != word[j]) {
                found = 0;
                break;
            }
        }

        if (found == 1) {
            i = i + wordLen - 1;
        } else {
            result[r++] = str[i];
        }
    }
    result[r] = '\0'; 

    printf("Result: %s\n", result);
    return 0;
}

