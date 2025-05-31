#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main()
{
      int i,j;
      printf("\nTo understand working of nested for loop");
      
      for (i=1;i<=3;i++)
          {
                        for(j=1;j<=3;j++)
                        {
                                         printf("\nInside for loop");
                                         
                                         }
                        
                        printf("\nOutside j loop");
                        }
          printf("\nOutside i loop");
          getch();
       
       }
       
       
       

                        
