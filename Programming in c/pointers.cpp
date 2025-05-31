#include<stdio.h>
#include<conio.h>
main()
{
      int *debarred;
      int proxy;
      
      printf("\nHow many proxy you attempted?\n");
      scanf("%d",&proxy);
      debarred =&proxy;
      
      printf("\nYou have attempted = %d proxies", *debarred);
      printf("\nThe address of proxy = %u", debarred );
      
      printf("\nThe address of proxy= %x",debarred);
      printf("\nThe address of proxy=%x",&proxy);
      
getch();
}

      
      
