#include "problem_gen.h"

///////////////////////////////GAME SETUP FUNCTIONS////////////////////////////////////////////////////////////////

//Function that lets the user decide what to do (choose level, get instructions, etc.)
int user_interface(char *initials)
{
  //Determines whether or not to print the rules, or play the game
  int initial_choice = 0;
  int level_choice = 0;
  do
  {
    printf("Welcome to Basic Math Practice!\n");
    printf("What do you want to do?\n");
    printf("1. Get directions\n2. Practice some damn math\n");
    scanf("%d", &initial_choice);
  } while(initial_choice < 1 || initial_choice > 2);
  //Prints the directions until the user understands them
  if (initial_choice == 1)
  {
    print_rules();
  }
  //Sets up the practice session (gets initials and level)
  get_initials(initials);
  printf("Your initials are %s\n", initials);
  level_choice = get_level();
  return level_choice;

}

//Function that prints the directions until the user understands them
void print_rules(void)
{
  char understand = '\0';
  do
  {
    printf("You will be prompted to enter your initials, and choose your level.\n");
    printf("The first level consists of basic addition and subtraction problems,\nworth 1 point each.\n");
    printf("The second level consists of 2 term multiplication problems, worth 2\npoints each.\n");
    printf("The third level consists of 2 term division problems, worth 3 points\neach.\n");
    printf("The fourth level consists of a mix of addition, subtraction, division,\nand multiplication problems, worth 4 points each.\n");
    printf("The fifth level includes a mix of addition, subtraction, multiplication,\nand division problems, with positive and negative two and three digit operands and up to four terms only\n");
    printf("Got it? [Y/N]: ");
    scanf(" %c", &understand);
  } while(understand != 'Y');
}

//Function that gets initials from the user
void get_initials(char *initials)
{
  printf("Enter your initials (first, middle, last): ");
  scanf("%3s", initials);
}

//Function that gets the level to player
int get_level(void)
{
  int choice = 0;
  do
  {
    printf("Enter your choice of level: ");
    scanf("%d", &choice);
  } while(choice < 1 && choice > 5);
  return choice;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////PROBLEM GENERATION FUNCTIONS

//Function that generates mathematical operators
char generate_operator(int level)
{
  if (level == 1)
  {
    int x = rand() % 2 + 1;
    if (x == 1)
    {
      return '+';
    }
    else if (x == 2)
    {
      return '-';
    }
  }

return 'x';
}

int generate_number(int level)
{
  if (level == 1)
  {
    int num = rand() % 8 + 49;
    printf("Num: %d\n", num);
    return num;
  }

  return 0;
}

//Function that generates a problem for level one
void generate_level_one_problem(char *problem)
{
  problem[0] = generate_number(LEVEL_ONE);
  problem[1] = generate_operator(LEVEL_ONE);
  problem[2] = generate_number(LEVEL_ONE);
  printf("%s", problem);
}

//Function that reverses a string
void reverse(char *str)
{
    /* skip null */
    if (str == 0)
    {
        return;
    }

    /* skip empty string */
    if (*str == 0)
    {
        return;
    }

    /* get range */
    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */
    char temp;

    /* reverse */
    while (end > start)
    {
        /* swap */
        temp = *start;
        *start = *end;
        *end = temp;

        /* move */
        ++start;
        --end;
    }
}


//

//Function that splits a problem around a single operator
void my_strtok(char *problem, char op, char *new_lhs, char *new_rhs)
{
  int counter = strlen(problem)-1, rh_count = 0, lh_count = 0;
  //Forms the right side of the problem
  while(problem[counter] != op)
  {
    new_rhs[rh_count] = problem[counter];
    rh_count++;
    counter--;
  }
  counter--; //Skips over the operators
  //Forms the left side of the problem
  while(counter >= 0)
  {
    new_lhs[lh_count] = problem[counter];
    lh_count++;
    counter--;
  }
  reverse(new_lhs);
  reverse(new_rhs);
}

//Function that finds the last occurence of a character (operator)
char findLastOccurence(char *problem, char *ops)
{
  char last_occurence = '\0';
  int problem_size = strlen(problem);
  int num_ops = strlen(ops);
  for (int i=problem_size; i>=0; i--) //Works through backwards
  {
    for (int j=0; j<num_ops; j++)
    {
      if (problem[i] == ops[j])
      {
        last_occurence = ops[j];
        return last_occurence;
        break;
      }
    }
  }
  return last_occurence;
}

int char_compare(char c1, char c2)
{
  if (c1 == c2)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

double solve_problem(char *problem)
{
  char last_operator = '\0';
  char new_lhs[50] = { '\0' };
  char new_rhs[50] = { '\0' };

  last_operator = findLastOccurence(problem, "*/+-");
  if(!char_compare(last_operator, '+') || !char_compare(last_operator, '+') || !char_compare(last_operator, '*') || !char_compare(last_operator, '/'))
  {
    if (!char_compare(last_operator, '+'))
    {
      my_strtok(problem, '+', new_lhs, new_rhs);
      return solve_problem(new_lhs) + solve_problem(new_rhs);
    }
    else if (!char_compare(last_operator, '-'))
    {
      my_strtok(problem, '-', new_lhs, new_rhs);
      return solve_problem(new_lhs) - solve_problem(new_rhs);
    }
    else if (!char_compare(last_operator, '*'))
    {
      my_strtok(problem, '*', new_lhs, new_rhs);
      return solve_problem(new_lhs) * solve_problem(new_rhs);
    }
    else if (!char_compare(last_operator, '/'))
    {
      my_strtok(problem, '/', new_lhs, new_rhs);
      return solve_problem(new_lhs) / solve_problem(new_rhs);
    }
  }
  return atoi(problem);
}
