#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
printf("Let us find distance travelled by car through equation of motion");
int s,u,a,t;
printf("\n\nEnter the initial velocity(u) of car:");
scanf("%d",&u);
printf("\nEnter the time(t) taken by car to travel distance(s):");
scanf("%d",&t);
printf("\nEnter the acceleration(a) attained by car:");
scanf("%d",&a);
int p = pow(t,t);
s = (u*t)+(a*p)/2;
printf("\nThe distance(s) travelled by car in time(t) with initial velocity(u) and acceleration(a) is: %d",s);
printf("\n\nLet us now swap two no. without third variable");
int x,y;
printf("\nEnter the value of x:");
scanf("%d",&x);
printf("\nEnter the value of y:");
scanf("%d",&y);
printf("\nSwapping both the varaibles...");
x = x + y;
y = x - y;
x = x - y;
printf("Now x =%d",x);
printf(" and y =%d",y);
printf("\n\nNow swapping two no. with the use of third variable");
int var1,var2,temp;
printf("\nEnter the value of var1:");
scanf("%d",&var1);
printf("\nEnter the value of var2:");
scanf("%d",&var2);
temp = var1;
var1 = var2;
var2 = temp;
printf("\nSwapping both the varaibles...");
printf("Now var1=%d",var1);
printf(" and var2=%d",var2);
getch();
}
