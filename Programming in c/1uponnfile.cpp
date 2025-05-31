#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 main()
{
 double n;
     double i=1, sum = 0 ;
    printf("\n enter the number ");
    scanf("%lf",&n);
    
    while(i<=n)
    {
               sum=sum+1/i;
               i++;
}
printf(" sum is %lf",sum);
    getch();
    
}
