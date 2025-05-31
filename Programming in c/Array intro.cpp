#include<stdio.h>
#include<conio.h>
main()
{
      int arr[5];
      int i;
      printf("\nTo understand array");
      printf("\nEnter 5 elements for arr[5]:\n");
      for(i=0;i<5;i++)
      {
                      printf("\nEnter %d values\n",i+1);
                      scanf("%d",&arr[i]);
                      }
                      
      printf("\nOutside loop\n");
      printf("\nFIVE ELEMENTS ARE:\n");
                      
      for(i=0;i<5;i++)
      {
                                      
                      printf("\n%d",arr[i]);
                      printf("\n");
                      }
                      
getch();
}








