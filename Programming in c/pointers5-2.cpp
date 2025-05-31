#include <stdio.h>
#include<conio.h>

main()
{
 int n = 10;
 int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 int* ptr; 
 ptr = arr;

 int count_even = 0;
 int count_odd = 0;
 for (int i = 0; i < n; i++) {
 if (*ptr % 2 == 0) {
 count_even++;
 }
 if (*ptr % 2 != 0) {
 count_odd++;
 }
 ptr++;
 }
 printf("No of even elements in an array is : %d",
 count_even);
 printf("\nNo of odd elements in an array is : %d",
 count_odd);
 getch();
}
