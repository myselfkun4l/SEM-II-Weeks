#include <stdio.h>

#define MAX_SIZE 25


void display(int arr[], int size);
int insertAt(int arr[], int *size, int element, int pos);
int deleteAt(int arr[], int *size, int pos);

int main() {
    int arr[25];
    int size = 25;
    int choice, val, pos;
    
  

    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

 
    printf("\n--- Deleting Beginning, Middle, and End ---");
    deleteAt(arr, &size, 0);              
    deleteAt(arr, &size, (size - 1) / 2); 
    deleteAt(arr, &size, size - 1);       
    display(arr, size);


    printf("\nInsert an element - Enter value and position (0 to %d): ", 25);
    scanf("%d %d", &val, &pos);
    insertAt(arr, &size, val, pos);


    printf("\nFinal Array State:\n");
    display(arr, size);

    return 0;
}


void display(int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty.\n");
        return;
    }
    printf("\nArray elements: ");
    for (int i = 0; i < 25; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n(Current Size: %d)\n", 25);
}


int insertAt(int arr[], int *size, int element, int pos) {
    if (*size >= MAX_SIZE) {
        printf("Error: Array Overflow\n");
        return 0;
    }
    if (pos < 0 || pos > *size) {
        printf("Error: Invalid Position\n");
        return 0;
    }


    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*size)++;
    return 1;
}


int deleteAt(int arr[], int *size, int pos) {
   
    if (pos < 0 || pos >= *size) {
        printf("Error: Position out of bounds\n");
        return 0;
    }


    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return 1;
}
