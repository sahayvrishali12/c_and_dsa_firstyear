#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
main()
{
      int choice;
      int num1,num2,sum,sub,div,prod;

printf("To understand switch in c!");

printf("\n PRESS 1 TO ADD \n PRESS 2 TO SUBSTRACT \n PRESS 3 TO MULTIPLY \n PRESS 4 TO DIVIDE \n PRESS 5 TO EXIT\n");
scanf("%d",&choice);

switch(choice)
   {
              case 1 : printf("\nEnter value of num1 and num2:");
                       scanf("%d%d",&num1,&num2);
                       
                       sum = num1 + num2;
                       printf("\n%d +%d = %d", num1 , num2, sum);
                       
                       break;
                       
              case 2 : printf("\nEnter value of num1 and num2:");
                       scanf("%d%d",&num1,&num2);
                       
                       sub = num1 - num2;
                       printf("\n%d -%d = %d", num1 , num2, sub);
                       
                       break;
                       
              case 3 : printf("\nEnter value of num1 and num2:");
                       scanf("%d%d",&num1,&num2);
                       
                       prod = num1*num2;
                       printf("\n%d*%d = %d", num1 , num2, prod);
                       
                       break;
                       
              case 4 : printf("\nEnter value of num1 and num2:");
                       scanf("%d%d",&num1,&num2);
                       
                       div = num1/num2;
                       printf("\n%d/%d = %d", num1 , num2, div);
                       
                       break;
                       
              case 5 : exit(0);
              
              default : printf("\ninvalid input");
           
  }
getch();
}

                       
              
