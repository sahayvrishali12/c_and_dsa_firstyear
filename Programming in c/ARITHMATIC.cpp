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
getch();
}
