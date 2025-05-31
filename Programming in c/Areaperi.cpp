#include<stdio.h>
#include<conio.h>
main()
{
int l,b,a,p;
printf("Enter the lenght of rectangle:");
scanf("%d",&l);
printf("Enter the width of rectangle:");
scanf("%d",&b);
a = l*b;
p = 2*(l + b);
printf("The area of the rectangle is %d,while the perimeter of the rectangle is %d",a,p);
getch();
}
