#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
main()
{
      int choice;
      char name10[15];
      char name11[15];
      char name12[15];
      char string[500];
      printf("Enter the class of which class teacher you liked the most (class 10-12 only)\n");
      printf("\nPRESS 10 FOR CLASS 10 \nPRESS 11 FOR CLASS 12 \nPRESS 12 FOR CLASS 12\n");
      scanf("%d",&choice);
      switch(choice)
      {
                    case 10: printf("Name of your Class 10 teacher was:\n");
                             scanf("%s",&name10);                         
                             printf("What qualities did you like in them?\n");
                             gets(string);
                             puts(string);
                             printf("Your class teacher of 10 %s was a very strong and dedicated teacher.%sLastly teachers hold a special place in everyones life and you should be glad you found a teacher like her",name10,string);
                             break;
                             
                    case 11: printf("Name of your Class 11 teacher was:");
                             scanf("%s",&name11);                           
                             printf("What qualities did you like in them?");
                             gets(string);
                             puts(string);
                             printf("Your class teacher of 11 %s was a very strong and dedicated teacher.%sLastly teachers hold a special place in everyones life and you should be glad you found a teacher like her",name11,string);
                             break;
                    case 12: printf("Name of your Class 12 teacher was:");
                             scanf("%s",&name12);                           
                             printf("What qualities did you like in them?");
                             gets(string);
                             puts(string);
                             printf("Your class teacher of 12 %s was a very strong and dedicated teacher.%sLastly teachers hold a special place in everyones life and you should be glad you found a teacher like her",name12,string);
                             break;
                             }
                             getch();
}
                    
