
#include <stdio.h>


int linear_n_r(int arr[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) return i;
    }
    return -1;
}

int linear_recursive(int arr[], int n, int item, int index) {
    if (index >= n) return -1;
    if (arr[index] == item) return index;
    return linear_recursive(arr, n, item, index + 1);
}


int binary_n_r(int arr[], int n, int item) {
    int lb = 0, ub = n - 1;
    while (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (arr[mid] == item) return mid;
        if (arr[mid] < item) lb = mid + 1;
        else ub = mid - 1;
    }
    return -1;
}

 
int binary_recursive(int arr[], int lb, int ub, int item) {
    if (lb > ub) return -1;
    int mid = (lb + ub) / 2;
    if (arr[mid] == item) return mid;
    if (arr[mid] > item) return binary_recursive(arr, lb, mid - 1, item);
    return binary_recursive(arr, mid + 1, ub, item);
}

int main() {
    int n, item, choice, result;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    printf("Enter %d elements (sorted for binary search): ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter item to search: ");
    scanf("%d", &item);

    printf("\nChoose Search Method:\n1. Linear (non-recursive)\n2. Linear (Recursive)\n3. Binary (non-recursive)\n4. Binary (Recursive)\nChoice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: result = linear_n_r(arr, n, item); break;
        case 2: result = linear_recursive(arr, n, item, 0); break;
        case 3: result = binary_n_r(arr, n, item); break;
        case 4: result = binary_recursive(arr, 0, n - 1, item); break;
        default: printf("Invalid choice!\n"); return 0;
    }

    if (result != -1) printf("Item found at index %d\n", result);
    else printf("Item not found.\n");

    return 0;
}

