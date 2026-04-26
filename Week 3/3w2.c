#include <stdio.h>

void merge(int arr1[], int n1, int arr2[], int n2, int mergedArr[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            mergedArr[k] = arr1[i];
            i++;
        } else {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
	int i,j; 
	
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int n3 = n1 + n2;
    int mergedArr[n3];

    merge(arr1, n1, arr2, n2, mergedArr);
    printf("First array: ");
    for (i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    printf("Second array: ");
    for (j = 0; j < n2; j++) {
        printf("%d ", arr2[j]);
    }
    printf("\n");

    printf("Merged array: ");
    for (i = 0; i < n3; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    return 0;
}

