#include<stdio.h>
#include<conio.h>
main()
{ 
      int m,f3,f1=0,f2=1,i,lenght;
      
    printf(" length of the  fibonacci series:");
    scanf("%d",&lenght);
    printf("\t%d\t%d",f1,f2);
    
     for(i=1;i<=lenght;i++)          
    {
        f3=f1+f2;               
        printf("\t%d",f3);     
        f1=f2;
        f2=f3;
        i=i+1;  
        }                
       getch();
    
    }
       
