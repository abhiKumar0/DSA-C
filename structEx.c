/*
Your managing a travel agency and you want your n drivers to input their details: name, dln, route, kms

*/

#include <stdio.h>
#include <string.h>

struct drivers
{
  char name[30];
  char dLN[10];
  char route[30];
  int kms;
};


int main(int argc, char const *argv[])
{
  struct arr[3];
  
  for (int i = 0; i < 3; i++)
  {
    char name[30], dln[10], rt[30];
    int kms;
    printf("Enter your name: ");
    gets(name);
    strcpy(name, arr[i].name);
    
    printf("Enter your driving license no: ");
    gets(dln);
    strcpy(dln, arr[i].dLN);
    
    printf("Enter your route: ");
    gets(rt);
    strcpy(rt, arr[i].route);

    scanf("Enter your average speed in kms: \d", kms);
    
  }
  
  return 0;
}
