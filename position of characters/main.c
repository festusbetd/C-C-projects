#include <stdio.h>
#include <conio.h>
#include <string.h>

void main(void)
{

  int i=0;
  char str[40], ch;

  printf("\n\n\t\tSearch position of characters within a string.\n");
  printf("\n\tEnter string [Length max 40]: ");
  gets(str);
  printf("\n\tEnter character to search: ");
  scanf("%c", &ch);
  while(i<strlen(str))
  {
    if(str[i] == ch)
    {
      printf("\n\tCharacter %c found on position %d", ch, i+1);
      break;
    }
    i++;
  }
  if(str[i] != ch)
    printf("\n\t%c is not present in the entered string.", ch);
  getch();

}
