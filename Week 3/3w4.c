#include <stdio.h>

int main() {

    int array[] = {10, 20, 30, 40, 50};
    
    int *ptr = array;
    
    int index;

    printf("Enter an index (0 to 4): ");
    scanf("%d", &index);
   
    int element = *(ptr + index);

    printf("The element at index %d is %d\n", index, element);

    return 0;
}

