#include<stdio.h>
#include<conio.h>
main()
{
   int x,y,z;
   printf("Enter sides of triangle:");
   scanf("%d%d%d",&x,&y,&z);
   if((x == y) && (y == z))
      {
            printf("The Triangle is equilateral");
            }
   else if(x == y || y == z|| z == x)
      {
             printf("The Triangle is isosceles");
             }
             
   else
      {
             printf("The Triangle is scalene");
             }
   return 0;
   getch();

}
