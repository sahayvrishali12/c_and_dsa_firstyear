#include<stdio.h>
#include<conio.h>
main()
{
      int i,num,prod,limit;.
      printf("Enter a number whose table to be completed:");
      scanf("%d",&num);
      printf("\nEnter the limit of the table");
      scanf("%d",&limit);
      for(i=1;i<= limit;i++)
      { 
                  prod=num*i;
                  printf("\n%d X %d = %d", num,i , prod);
                  }
                  getch();
           
} 
