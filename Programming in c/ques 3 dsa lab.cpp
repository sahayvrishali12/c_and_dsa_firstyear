#include<stdio.h>
#include<conio.h>
main(){
   int i,arr[4];
   int mul=1;
   printf("Enter the values of number:");
   
   for(i=0;i<4;i++)
   scanf("%d",&arr[i]);
   
   for(i=0;i<4;i++)
   mul = mul * arr[i];
   
   printf("The multiplication of values of number is %d",mul);
   getch();
   }
