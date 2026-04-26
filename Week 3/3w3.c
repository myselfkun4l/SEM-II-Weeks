#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int *ptr; 

    ptr = arr; 

    printf("Traversing array elements using pointers:\n");
    
    int i;
    for (i = 0; i < n; i++) {
      
        printf("Element %d: %d (Address: %p)\n", i, *(ptr + i), (ptr + i));
    }

    return 0;
}

