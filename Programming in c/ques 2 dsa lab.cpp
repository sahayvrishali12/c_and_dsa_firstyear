#include<stdio.h>
#include<conio.h>
main(){
   int i,arr[4];
   int sum=0;
   printf("Enter the values of number:");
   
   for(i=0;i<4;i++)
   scanf("%d",&arr[i]);
   
   for(i=0;i<4;i++)
   sum+=arr[i];
   
   printf("The sum of values of number is %d",sum);
   getch();
   }
