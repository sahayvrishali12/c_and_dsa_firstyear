#include<stdio.h>
#include<conio.h>
main()
{ 
      int i=1,m,f3,f1=0,f2=1,lenght;
      
      printf(" length of the  fibonacci series:");
    scanf("%d",&lenght);
    printf("\t%d\t%d",f1,f2);
    
     while(i<=lenght)          
    {
        f3=f1+f2;               
        printf("\t%d",f3);     
        f1=f2;
        f2=f3;
        i=i+1;  
        }                
       getch();
    
    }
       
