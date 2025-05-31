#include <stdio.h>
#include<conio.h>

main()
{
 int N = 4;
 int *ptr1, *ptr2;
 ptr1 = &N;
 ptr2 = &N;
 printf("Pointer ptr2 before Addition: ");
 printf("%p \n", ptr2);
 ptr2 = ptr2 + 3;
 printf("Pointer ptr2 after Addition: ");
 printf("%p \n", ptr2);
 getch();
 
}
