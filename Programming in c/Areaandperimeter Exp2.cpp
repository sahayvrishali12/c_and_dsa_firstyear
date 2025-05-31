#include<stdio.h>
#include<conio.h>
main()
{
float c;
float f;
printf("\n\nEnter the temperature in Celcius:");
scanf("%f",&c);
f = (c*9/5)+32;
printf("The temperature in fahrenheit is %f",f);
getch();
}
