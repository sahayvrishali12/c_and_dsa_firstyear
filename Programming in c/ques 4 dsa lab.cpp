#include<stdio.h>
#include<conio.h>
main(){
   int i,arr[9];
   int tosearch,found;
   printf("Enter the values of number:");
   
   for(i=0;i<9;i++)
   scanf("%d",&arr[i]);
   
   printf("Enter the number to search:");
   scanf("%d",&tosearch);
   
   for(i=0;i<9;i++)
   {
   if(tosearch==arr[i])
   { printf("\nThe element at index %d exists",tosearch);`
    break;
}
   else 
   { printf("\nThe element at index does not exist");
   break;
}
}
  
   
   getch();
}
   
