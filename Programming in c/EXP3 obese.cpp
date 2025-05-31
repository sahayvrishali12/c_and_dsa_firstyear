#include<stdio.h>
#include<conio.h>
main()
{
      float b,w,h,H1,b1;
printf("Enter your height in meters:");
scanf("%f",&h);
printf("Enter your weight in kilograms:");
scanf("%f",&w);
H1=h*h;
b1=w/H1;

printf("\nYour BMI is %f\n",b1);
b=b1;
if(b<15)
{
printf("STARVATION");
}
else if((b>15.1)&&(b<17.5))
{
printf("ANOREXIC");
}
else if((b>17.6)&&(b<18.5))
{
printf("UNDERWEIGHT");
}
else if((b>18.6)&&(b<24.9))
{
printf("IDEAL");
}
     
else if((b>25)&&(b<25.9))
{
printf("OVERWEIGHT");
     }
else if((b>30)&&(b<39.9))
{
     printf("OBESE");
     }
else if(b>40)
{
          printf("MORBIDITY OBESE");
          }
          else
          {
              printf("no data");
}
getch();
}
