#include<stdio.h>
#include<string.h>
#define max 100
int main() 
{
   char str[max],f='a';
   int i;
   printf("enter the string to be checked: ");
   scanf("%s",str);
   int length = strlen(str);
   if(str[0] == '0' && str[length-1] == '1')
   {
      printf("Accepted");
   }
    else
	{
      printf("Rejected");
    return 0;
    }
}
