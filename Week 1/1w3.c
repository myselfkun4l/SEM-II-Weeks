#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200];
    int v = 0, c = 0, d = 0, s = 0, o = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

	int i;
    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]); 

        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                v++;
            else
                c++;
        } else if (ch >= '0' && ch <= '9') {
            d++;
        } else if (ch == ' ' || ch == '\t' || ch == '\n') {
            s++;
        } else if (str[i] != '\n' && str[i] != '\0') {
            o++;
        }
    }

    printf("\nVowels: %d", v);
    printf("\nConsonants: %d", c);
    printf("\nDigits: %d", d);
    printf("\nWhite Spaces: %d", s);
    printf("\nOther Characters: %d\n", o);

    return 0;
}

