
#include <stdio.h>

int sumIterative(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int sumRecursive(int arr[], int size) {
    if (size == 0) {
        return 0;
    } else {
        return arr[0] + sumRecursive(arr + 1, size - 1);
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Iterative sum: %d\n", sumIterative(nums, n));
    printf("Recursive sum: %d\n", sumRecursive(nums, n));

    return 0;
}
