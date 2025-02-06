#include <stdio.h>

int interpolation_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    int size, target, result;

    printf("Enter the number of elements in the array (sorted in ascending order): ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    result = interpolation_search(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
