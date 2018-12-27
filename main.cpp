/*У заданому рядку символів визначити символи, які зустрічаються по одному разу і надрукувати номери їх позицій.*/
#include <stdlib.h>
#include <iostream>

using namespace std;

int *getCharCountArray(char *str)
{
   int *count = (int *)calloc(sizeof(int), 256);
   int i;
   for (i = 0; *(str+i);  i++)
      count[*(str+i)]++;                
   return count;
}


void NonRepeating(char *str)
{
  int *count = getCharCountArray(str);
  int i = 0,k = 0;
  int index = -1;
    for (i = 0; *(str+i);  i++)
      {
        if (count[*(str+i)] == 1)
        {
          k++;
          index = i;
          printf("%i non-repeating character is %c and it has %i index\n\n", k,str[index],index);
        }
      }

  free(count);
    if (index == -1)
    printf("Either all characters are repeating or string is empty");
}
using namespace std;

int main()
{
  char str[256];
  cout << "Enter string : " ;
  cin >> str ;
  NonRepeating(str);
  getchar();
  return 0;
}
