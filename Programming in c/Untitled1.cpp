#include<stdio.h>
#include<stdlib.h>
//#define n 100

int array[100], Replace_Location, Replace_number, U_i_count=0, U_input_num_amount;

int Insertion_in_array()
{
    // // Showing the contents of the array
    printf("\nThe elements in the array are: \n");
    for (int i = 0; i < U_input_num_amount; i++)
        printf("%d ", array[i]);

    printf("\nWhere do you want to insert a number?\n");
    scanf("%d", &Replace_Location);

    // Check for Space in array
    if (100 == U_i_count)
    {
        printf("The array is filled and number can't be inserted");
        return 0;
    }
    
    printf("\nThe number: ");
    scanf("%d", &Replace_number);

    for (int i = U_input_num_amount; i >= Replace_Location; i--) 
        array[i] = array[i - 1]; 


    array[Replace_Location - 1] = Replace_number;
    
    // Showing the contents of the array
    printf("\nThe Updated elements in the array are: \n");
    for (int i = 0; i < U_input_num_amount + 1; i++)
        printf("%d ", array[i]);
    
    return 0;
}


int Deleting_element()
{

    printf("\nThe elements in the array are: \n");
    for (int i = 0; i < U_input_num_amount; i++)
        printf("%d ", array[i]);

    printf("\nThe elements in the array are: \n");
    for (int i = 0; i < U_input_num_amount; i++)
        printf("%d ", array[i]);
    
    printf("\n");
    printf("\nWhich number do you want to delete?\n");
    scanf("%d", &Replace_number);

    int found = 0; // Flag number was found
    for (int i = 0; i < U_input_num_amount; i++) 
    {
        if (array[i] == Replace_number) 
        {
            found = 1;
            U_input_num_amount--; // Decrease the size of the array
            break; 
        }
    }

    if (found)
        printf("\nThe number %d has been deleted.\n", Replace_number);
    else
        printf("\nNumber %d not found in the array.\n", Replace_number);

    printf("\nThe elements in the array are: \n");
    for (int i = 0; i < U_input_num_amount; i++)
        printf("%d ", array[i]);
    printf("\n");
    
    return 0;
}

int Element_search_LS()
{
    int search_number, position;
    for (int i = 0; i < U_input_num_amount; i++)
        printf("%d ", array[i]);
    printf("\n");

    printf("\nEnter the number you want to search: ");
    scanf("%d", &search_number);
    int found = 0;
    for (int i = 0; i < U_input_num_amount; i++)
    {
        if (array[i] == search_number)
        found = 1, position = i;
    }
    if (found == 1)
        printf("\nNumber %d found in the array, at position %d.\n", search_number, position);
    else
    printf("\nNumber %d not found in the array.\n", search_number);
    
    return 0;
}

int Element_search_BS()
{
    int search_number, left, right, mid;
    for (int i = 0; i < U_input_num_amount; i++)
        printf("%d ", array[i]);
    printf("\n");
    printf("\nEnter the number you want to search: ");
    scanf("%d", &search_number);

    left = 0;
    right = U_i_count - 1;
    int found = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (array[mid] == search_number) {
            found = 1;
            printf("\nNumber %d found in the array, at position %d.\n", search_number, mid + 1);
            break;
        }
        if (array[mid] < search_number)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (!found)
        printf("\nNumber %d not found in the array.\n", search_number);
}



int bubbleSort() 
{

    for (int i = 0; i < U_input_num_amount; i++)
        printf("%d ", array[i]);
    printf("\n");

    for (int i = 0; i < U_i_count - 1; i++) 
    {
        for (int j = 0; j < U_i_count - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("\nArray sorted using Bubble Sort:\n");
    for (int i = 0; i < U_i_count; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int selectionSort() 
{
    for (int i = 0; i < U_input_num_amount; i++)
        printf("%d ", array[i]);
    printf("\n");

    for (int i = 0; i < U_i_count - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < U_i_count; j++) 
        {
            if (array[j] < array[minIndex]) 
              
                minIndex = j;
        }
        // Swap the found minimum element with the first element
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
    printf("\nArray sorted using Selection Sort:\n");
    for (int i = 0; i < U_i_count; i++)
        printf("%d ", array[i]);
    printf("\n");
}


int main(void)
{    
    int U_choice = 0;

    printf("How many numbers do you want to enter: ");
    scanf("%d", &U_input_num_amount);
    printf("elements: ");

    // taking user input and flag for input times
    for (int i = 0; i < U_input_num_amount; i++)
    {
        scanf("%d", &array[i]);
        U_i_count++;
    }
    while(U_choice != 7)
    {
        printf("\n");
        printf("1. Insertion at a desiereed location in an array. \n");
        printf("2. Deletion of an element in an array. \n");
        printf("3. Search an element using linear search. \n");
        printf("4. Search an element using Binary search. \n");
        printf("5. Sort an array using Bubble sort. \n");
        printf("6. Sort an array using Selection sort. \n");
        printf("7. Exit...\n");
        printf("Choice: ");
        scanf("%d", &U_choice);

        switch (U_choice)
        {
            case 1:
                Insertion_in_array();
            break;
            case 2:
                Deleting_element();
            break;
            case 3:
                Element_search_LS();
            break;

            case 4:
                Element_search_BS();
            break;    

            case 5:
                bubbleSort();
            break;

            case 6:
                selectionSort();
            break;

            case 7:

                printf("Exiting the program...\n");
                return 0;
            break;  
            default:
                printf("ERROR: Choose an valid option.\n");
            break;
        }
    }

    printf("\nSUCCESS: Program exited.\n\n");
    return 0;

}