#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
main()
{
      int choice;
      printf("\nProgramming to understand exit and goto functionality!");
      printf("\nPRESS 1 FOR MOTHER\nPRESS 2 FOR FATHER\nPRESS 3 FOR CHILDREN\n");
      scanf("%d",&choice);
      if(choice==1)
      {
                   goto M;
                   }
      else if (choice==2)
      goto F;
      else if (choice==3)
      goto children;
      else 
      printf("\nINVALID CHOICE");
      exit(0);
      
      M:
              printf("\nMy mother is my world");
              exit(0);
              
      F:
              printf("\nMy father is my sky");
              exit(0);
              
      children:
               printf("My children are heaven");
               exit(0);
               
               
               
               
      getch();
}
