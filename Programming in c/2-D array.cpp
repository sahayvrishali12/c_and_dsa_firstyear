#include<stdio.h>
#include<conio.h>
main()
{
      int Matrix[3][3],i,j;
      printf("\nTo understand 2-D arrays!!");
      //input concept 
      printf("\nEnter 9 elements of Matrix\n");
      for(i=0;i<3;i++)
      { 
                      for(j=0;j<3;j++)
                      {
                                      scanf("%d",&Matrix[i][j]);
                                      }
                                      }
                                      
      //output concept 
      
      printf("\nTo print the 9 elements of Matrix\n");
      
      for(i=0;i<3;i++)
      {
                      for(j=0;j<3;j++)
                      {
                                      printf("%d",Matrix[i][j]);
                                      }
                                      printf("\n");
                                      }
                                      
getch();
                                      }
                                      
                                      
