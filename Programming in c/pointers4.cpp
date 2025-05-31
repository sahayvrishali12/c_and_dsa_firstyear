#include<conio.h>
#include <stdio.h>
main()
{
 int x = 6;
 int N = 4;
 int *ptr1, *ptr2;
 ptr1 = &N; 
 ptr2 = &x; 
 printf(" ptr1 = %u, ptr2 = %u\n", ptr1, ptr2);
 x = ptr1 - ptr2;
 printf("Subtraction of ptr1 "
 "& ptr2 is %d\n",
 x);
 getch();
}
