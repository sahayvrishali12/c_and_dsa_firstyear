#include<stdio.h>
#include<conio.h>
 main()
{
      int Matrix[3][3],Matrix1[3][3],sum[3][3],i,j;
      int SUM = 0;
      //clsrcr();
      printf("\nTo understand 2-D arrays!!");
      //input concept 
      printf("\nEnter 9 elements of Matrix\n");
      for(i=0;i<3;i++)
      { 
                      for(j=0;j<3;j++)
                      {
                                      scanf("%d",&Matrix[i][j]);
                                      }//j loop close
                                      }//i loop close
                                      
      printf("\nEnter 9 elements of Matrix1\n");
      for(i=0;i<3;i++)
      { 
                      for(j=0;j<3;j++)
                      {
                                      scanf("%d",&Matrix1[i][j]);
                                      }//j loop close
                                      }//i loop close
                                      
      //output concept 
      
      printf("\nTo print the 9 elements of Matrix\n");
      
      for(i=0;i<3;i++)
      {
                      for(j=0;j<3;j++)
                      {
                                      printf("\t%d",Matrix[i][j]);
                                      }//j loop close
                                      printf("\n");
                                      }//i loop close
                                      
      
      printf("\nTo print the 9 elements of Matrix1\n");
      
      for(i=0;i<3;i++)
      {
                      for(j=0;j<3;j++)
                      {
                                      printf("\t%d",Matrix1[i][j]);
                                      }//j loop close
                                      printf("\n");
                                      }//i loop close
                                      
      //sum of two matrix input
      
      for(i=0;i<3;i++)
      {
                      for(j=0;j<3;j++)
                      {
                                      sum[i][j]=Matrix[i][j] + Matrix1[i][j];
                                      }//j loop close
                                      }//i loop close
                                      
      //sum of two matrix output
      
printf("\n\nThe sum of Matric\n");
      for(i=0;i<3;i++)
      {
                      for(j=0;j<3;j++)
                      {
                                      printf("\t%d",sum[i][j]);
                                      }//j loop close
                                      printf("\n");
                                      }//i loop close
                                      
      //transpose of matrics 
printf("\n\nTranspose of sum Matrics\n");
      for (i=0;i<3;i++)
      {
                      for(j=0;j<3;j++)
                      {
                                      printf("\t%d",sum[j][i]);
                                      }printf("\n");//j loop close
                                      }//i loop close
                                      
                                      
    //sum of diagonals of two diffrent matrixs 
printf("\n\nSum of diagonals of Matrix and Matrix1");
      for(i=0;i<3;i++)
      {
                      
                                      printf("\t%d",Matrix[i][i]+Matrix1[i][i]);
                                      }
                                      printf("\n");//i loop close
//sum of diagonals of one matrix 
printf("\n\nSum of diagonals of Matrix\n");
    for(i=0;i<3;i++)
      {
                      for(j=0;j<3;j++)
                      {
                                      if ( i == j)
                                      { SUM = SUM + Matrix[i][j];
                                         printf("\t%d",Matrix[3][3]);
                                         }
                                      else 
                                      printf("\tNA");
                                      }//j loop close
                                      printf("\n");
                                      }//i loop close
                                                                                                                                                                 
getch();
                                      }//close of main
                                      
      
      
                                      
