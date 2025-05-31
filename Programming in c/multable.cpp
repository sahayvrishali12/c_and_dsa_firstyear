//Print the multiplication table of the number entered by the user. It should be in the correct formatting of table form.

#include<stdio.h> 
main() 

{ 

int p,x=1,a,n; 

printf("\nTo print the table of a number"); 

printf("\nEnter the number of which you want the table:"); 

scanf("%d",&a); 

printf("\nEnter the number till which you want the table:"); 

scanf("%d",&n); 

while(x<=n) 

{ 

p=x*a;

printf("\n%d X %d = %d",a,x,p);

x++;

} 

}
