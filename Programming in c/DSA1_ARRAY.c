#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int list[], int *currentSize) {
    if (*currentSize >= MAX_SIZE) {
        printf("List is full! Cannot insert new element.\n");
        return;
    }
    
    int newElement;
    int position;

    printf("Enter the element to insert: ");
    scanf("%d", &newElement);

    printf("Enter the position to insert (0 to %d): ", *currentSize);
    scanf("%d", &position);
    
    if (position < 0 || position > *currentSize) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", *currentSize);
        return;
    }

    for (int i = *currentSize; i > position; i--) {
        list[i] = list[i - 1];
    }
    
    list[position] = newElement;
    (*currentSize)++;

    printf("Element '%d' inserted at position %d.\n", newElement, position);
}

void deleteElement(int list[], int *currentSize) {
    if (*currentSize == 0) {
        printf("List is empty! Cannot delete any element.\n");
        return;
    }

    int position;

    printf("Enter the position to delete from (0 to %d): ", *currentSize - 1);
    scanf("%d", &position);
    
    if (position < 0 || position >= *currentSize) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", *currentSize - 1);
        return;
    }

    int removedElement = list[position];
    
    for (int i = position; i < *currentSize - 1; i++) {
        list[i] = list[i + 1];
    }
    
    (*currentSize)--;

    printf("Element '%d' deleted from position %d.\n", removedElement, position);
}

void searchElement(int list[], int currentSize) {
    int target;
    int found = 0;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < currentSize; i++) {
        if (list[i] == target) {
            printf("Element '%d' found at position %d.\n", target, i);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Element '%d' not found in the list.\n", target);
    }
}

void displayList(int list[], int currentSize) {
    if (currentSize == 0) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Current List: ");
    
    for (int i = 0; i < currentSize; i++) {
        printf("%d ", list[i]);
    }
    
    printf("\n");
}

void bubbleSort(int list[], int size) {
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

int binarySearch(int list[], int target, int low, int high) {
   while (low <= high) {
       int mid = low + (high - low) / 2;

       if (list[mid] == target) {
           return mid;
       }
       if (list[mid] < target) {
           low = mid + 1;
       } else {
           high = mid - 1;
       }
   }
   return -1;
}

void binarySearchElement(int list[], int currentSize) {
   int target;
   
   printf("Enter the element to search for using Binary Search: ");
   scanf("%d", &target);

   int result = binarySearch(list, target, 0, currentSize - 1);
   
   if (result != -1)
       printf("Element '%d' found at index %d.\n", target, result);
   else
       printf("Element '%d' not found in the list.\n", target);
}

void selectionSort(int list[], int size) {
   for (int i = 0; i < size - 1; i++) {
       int minIndex = i;
       for (int j = i + 1; j < size; j++) {
           if (list[j] < list[minIndex]) {
               minIndex = j;
           }
       }
       if (minIndex != i) {
           int temp = list[i];
           list[i] = list[minIndex];
           list[minIndex] = temp;
       }
   }
} 

void displayMenu() {
   printf("\nMenu:\n");
   printf("1. Insert element\n");
   printf("2. Delete element\n");
   printf("3. Search an item using linear search\n");
   printf("4. Display list\n");
   printf("5. Bubble Sort\n");
   printf("6. Selection Sort\n");
   printf("7. Search an item using binary search\n");
   printf("8. Exit\n");
}

int main() {
   int list[MAX_SIZE];
   int currentSize = 0;
   int userChoice;

   while (1) {
       displayMenu();
       printf("Enter choice (1-8): ");
       scanf("%d", &userChoice);

       switch (userChoice) {
           case 1:
               insertElement(list, &currentSize);
               break;
           case 2:
               deleteElement(list, &currentSize);
               break;
           case 3:
               searchElement(list, currentSize);
               break;
           case 4:
               displayList(list, currentSize);
               break;
           case 5:
               bubbleSort(list, currentSize);
               printf("Array sorted in ascending order using Bubble Sort.\n");
               break;
           case 6:
               selectionSort(list, currentSize);
               printf("Array sorted in ascending order using Selection Sort.\n");
               break;
           case 7:
               binarySearchElement(list, currentSize);
               break;
           case 8:
               printf("Exiting...\n");
               return 0;
           default:
               printf("Invalid choice!\n");
       }
   }

}