#include<string.h>
#include<stdio.h>
#include<conio.h>
main()
{
      char a;
      char name[15],str[15],str1[20],str2[15];
      int len;
      
      printf("Enter your name:");
          gets(name);
      
      printf("\n\nYour name is ");
          puts(name);
          len=strlen(name);
          printf("\n\nThe lenght of the str is %d\n\n",len);
      
      strcpy(str,name);
          puts(str);
          printf("\n\n");
      
      strrev(str);
      puts(str);
      
      printf("\n\nEnter some text for string:");
      gets(str1);
      printf("\n\n");
      strcat(str,str1);
      puts(str);
      
      
getch();

}
      
      
