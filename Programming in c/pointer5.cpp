#include <stdio.h>
#include<conio.h>
main()
{
 int arr[5];
 int *ptr1 = &arr[0];
 int *ptr2 = &arr[0];
 if (ptr1 == ptr2) {
 printf("Pointer to Array Name and First Element are Equal.");
 }
 else {
 printf("Pointer to Array Name and First Element are not Equal.");
 }
 getch();
}
