#include<conio.h>
#include <stdio.h>

main()
{
 int N = 4;
 int *ptr1, *ptr2;
 ptr1 = &N;
 ptr2 = &N;
 printf("Pointer ptr2 before Subtraction: ");
 printf("%p \n", ptr2);
 ptr2 = ptr2 - 3;
 printf("Pointer ptr2 after Subtraction: ");
 printf("%p \n", ptr2);
 getch();
}
