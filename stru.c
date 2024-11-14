#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  char name[20];
  int grade;
};

int main()
{
  int n;
  printf("The number of student: ");
  scanf("%d", &n);
  getchar();

  struct student* students = (struct student*)malloc(n* sizeof(struct student));
  if (students == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  {
    /* code */
  }
  
  for (int i = 0; i<n; i++) {

    printf("Enter the name of the student %d: ", i+1);
    fgets(students[i].name, sizeof(students[i].name), stdin);
    students[i].name[strspn(students[i].name, "\n")] = 0;


    label:
    printf("Enter grade of %s: ", students[i].name);
    scanf("%d", students[i].grade);
    getchar();

    if (students[i].grade < 0 && students[i].grade > 100){
      printf("Student's grade cannot be less than 0 and more than 100!");
      goto label;
    }
  }
  
  int highest = 0, lowest = 100;
  float sum;

  for (int i = 0; i<n; i++) {

    sum += students[i].grade;

    if (students[i].grade > highest) {
      highest == students[i].grade;
    }

    if (students[i].grade < lowest) {
      lowest == students[i].grade;
    }

  }

  printf("Average grade: %d", sum/n);

  for (int i = 0; i<n; i++) {
    if (highest == students[i].grade) {
      printf("Highest grade: %d (%s)", students[i].grade, students[i].name);
    }
    if (lowest == students[i].grade) {
      printf("lowest grade: %d (%s)", students[i].grade, students[i].name);
    }
  }

  free(students);
  return 0;

}