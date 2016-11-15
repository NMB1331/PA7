#include "problem_gen.h"
#include "problem_gen.c"

int main(void)
{
  char new_lhs[20], new_rhs[20], problem[20];
  char last_occurence = '\0';
  printf("Enter a problem: ");
  scanf("%s", problem);
  printf("Solution to problem: %lf\n", solve_problem(problem));
  return 0;
}
