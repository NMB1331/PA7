#include "problem_gen.h"

///////////////////////////////GAME SETUP FUNCTIONS////////////////////////////////////////////////////////////////

//Function that lets the user decide what to do (choose level, get instructions, etc.)
int welcome_screen(char *initials)
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
    printf("Enter your choice of level [1-5]: ");
    scanf("%d", &choice);
  } while(choice < 1 && choice > 5);
  return choice;
}

//Function that asks the user if they wish to continue
void play_next_level(int *level_choice)
{
  char play_again = '\0';
  while (true)
  {
    system("clear");
    printf("Want to play the next level? [Y/N]: ");
    scanf(" %1c", &play_again);
    if (play_again == 'Y') break;
    if (play_again == 'N') break;
  }

  if (play_again == 'Y' && *level_choice <= 4)
  {
    printf("Cool! Onto the next level!\n");
    *level_choice += 1;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    system("clear");
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////PROBLEM GENERATION FUNCTIONS

//Function that resets PROBLEM
void reset_problem(char *problem)
{
  for (int i=0; i<PROBLEM_SIZE; i++)
  {
    problem[i] = '\0';
  }
}

//Function that generates advanced operators (multiply, divide)
char generate_advanced_operator(void)
{

  int x = rand() % 2 + 1;
  if (x == 1)
  {
    return '*';
  }
  else if (x == 2)
  {
    return '/';
  }


return 'X'; //XCode won't let me return NULL
}

//Function that randomly generates
char generate_basic_operator(void)
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


return 'X'; //XCode won't let me return NULL
}

//Function that generates a random number for problems (higher numbers for harder problems)
int generate_number(void)
{
  int num = rand() % 8 + 49;
  return num;
}

//Function that generates a problem for level 1
void generate_level_one_problem(char *problem, int difficulty)
{
  reset_problem(problem);
  if (difficulty == EASY)
  {
    problem[0] = generate_number();
    problem[1] = generate_basic_operator();
    problem[2] = generate_number();
    printf("%s\n", problem);
  }
  else if (difficulty == MEDIUM)
  {
    problem[0] = generate_number();
    problem[1] = generate_basic_operator();
    problem[2] = generate_number();
    problem[3] = generate_basic_operator();
    problem[4] = generate_number();
    printf("%s\n", problem);
  }
  else if (difficulty == HARD)
  {
    problem[0] = generate_number();
    problem[1] = generate_basic_operator();
    problem[2] = generate_number();
    problem[3] = generate_basic_operator();
    problem[4] = generate_number();
    problem[5] = generate_basic_operator();
    problem[6] = generate_number();
    printf("%s\n", problem);
  }
  else
  {
    printf("Error generating problem 1\n");
  }

}

//Function that generates a problem for level 2
void generate_level_two_problem(char *problem)
{
  reset_problem(problem);
  problem[0] = generate_number();
  problem[1] = '*';
  problem[2] = generate_number();
  printf("%s\n", problem);
}

//Function that generates a problem for level 3
void generate_level_three_problem(char *problem)
{
  reset_problem(problem);
  problem[0] = generate_number();
  problem[1] = '/';
  problem[2] = generate_number();
  printf("%s\n", problem);
}

//Function that generates a problem for level 4
void generate_level_four_problem(char *problem)
{
  reset_problem(problem);
  problem[0] = generate_number();
  problem[1] = generate_basic_operator();
  problem[2] = generate_number();
  problem[3] = generate_basic_operator();
  problem[4] = generate_number();
  printf("%s\n", problem);
}

//Function that generates a problem for level 5
void generate_level_five_problem(char *problem, int difficulty)
{
  reset_problem(problem);
  if (difficulty == EASY)
  {
    problem[0] = generate_number();
    problem[1] = generate_advanced_operator();
    problem[2] = generate_number();
    problem[3] = generate_basic_operator();
    problem[4] = generate_number();
    printf("%s\n", problem);
  }
  else if (difficulty == MEDIUM)
  {
    problem[0] = generate_number();
    problem[1] = generate_basic_operator();
    problem[2] = generate_number();
    problem[3] = generate_advanced_operator();
    problem[4] = generate_number();
    problem[5] = generate_basic_operator();
    problem[6] = generate_number();
    printf("%s\n", problem);
  }
  else if (difficulty == HARD)
  {
    problem[0] = generate_number();
    problem[1] = generate_basic_operator();
    problem[2] = generate_number();
    problem[3] = generate_advanced_operator();
    problem[4] = generate_number();
    problem[5] = generate_basic_operator();
    problem[6] = generate_number();
    problem[7] = generate_advanced_operator();
    problem[8] = generate_number();
    printf("%s\n", problem);
  }
  else
  {
    printf("Error generating problem 5\n");
  }

}

//Function that lets the player play level occurence
void play_level_one(char *problem, int number_correct[10], int number_incorrect[10], int *level_choice)
{
  int number_of_problems = 1;
  double correct_answer = 0.0, user_answer = 0.0;
  while (number_of_problems <= 10)
  {
    //Generates easy problems
    if (number_correct[1] <= 3)
    {
      //Creates and displays the problem
      printf("Difficulty: EASY\n");
      printf("Level 1 Problem %d: ", number_of_problems);
      generate_level_one_problem(problem, EASY);
      correct_answer = solve_problem(problem);

      printf("Enter your answer: ");
      scanf("%lf", &user_answer);

      //Checks answer; updates scoring
      if (user_answer == correct_answer)
      {
        printf("Nice! You got it!\n");
        number_correct[LEVEL_ONE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else if (user_answer != correct_answer)
      {
        printf("Sorry! The answer was %.3lf...\n", correct_answer);
        number_incorrect[LEVEL_ONE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else
      {
        printf("ERROR SCORING PROBLEM\n");
        number_of_problems += 1;
      }

    }

    else if (number_correct[1] <= 7)
    {
      //Creates and displays the problem
      printf("Difficulty: MEDIUM\n");
      printf("Level 1 Problem %d: ", number_of_problems);
      generate_level_one_problem(problem, MEDIUM);
      correct_answer = solve_problem(problem);
      printf("Enter your answer: ");
      scanf("%lf", &user_answer);

      //Checks answer; updates scoring
      if (user_answer == correct_answer)
      {
        printf("Nice! You got it!\n");
        number_correct[LEVEL_ONE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else if (user_answer != correct_answer)
      {
        printf("Sorry! The answer was %.3lf...\n", correct_answer);
        number_incorrect[LEVEL_ONE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else
      {
        printf("ERROR SCORING PROBLEM\n");
        number_of_problems += 1;
      }

    }

    else if (number_correct[1] <= 10)
    {
      //Creates and displays the problem
      printf("Difficulty: HARD");
      printf("Level 1 Problem %d: ", number_of_problems);
      generate_level_one_problem(problem, HARD);
      correct_answer = solve_problem(problem);
      printf("Enter your answer: ");
      scanf("%lf", &user_answer);

      //Checks answer; updates scoring
      if (user_answer == correct_answer)
      {
        printf("Nice! You got it!\n");
        number_correct[LEVEL_ONE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else if (user_answer != correct_answer)
      {
        printf("Sorry! The answer was %.3lf...\n", correct_answer);
        number_incorrect[LEVEL_ONE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else
      {
        printf("ERROR SCORING PROBLEM\n");
        number_of_problems += 1;
      }

    }

}
  play_next_level(level_choice);
}

//Function that plays level 2 (displays problems, checks answers)
void play_level_two(char *problem, int number_correct[6], int number_incorrect[6], int *level_choice)
{
  int number_of_problems = 1;
  double user_answer = 0, correct_answer = 0;

  while (number_of_problems <= 10)
  {
    printf("Level 2 Problem %d: ", number_of_problems);
    generate_level_two_problem(problem);
    correct_answer = solve_problem(problem);
    printf("Enter your answer: ");
    scanf("%lf", &user_answer);

    if (user_answer == correct_answer)
    {
      printf("Nice! You got it!\n");
      number_correct[LEVEL_TWO] += 1;
      number_of_problems += 1;
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      system("clear");
    }

    else if (user_answer != correct_answer)
    {
      printf("Sorry, the answer was %.3lf\n", correct_answer);
      number_incorrect[LEVEL_TWO] += 1;
      number_of_problems += 1;
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      system("clear");
    }
    else
    {
      printf("ERROR SCORING PROBLEM 2\n");
      number_of_problems += 1;
    }
  }
  play_next_level(level_choice);
}

//Function that plays level 2 (displays problems, checks answers)
void play_level_three(char *problem, int number_correct[6], int number_incorrect[6], int *level_choice)
{
  int number_of_problems = 1;
  double user_answer = 0, correct_answer = 0;

  while (number_of_problems <= 10)
  {
    printf("Level 3 Problem %d: ", number_of_problems);
    generate_level_three_problem(problem);
    correct_answer = solve_problem(problem);
    printf("Enter your answer: ");
    scanf("%lf", &user_answer);

    if (user_answer == correct_answer)
    {
      printf("Nice! You got it!\n");
      number_correct[LEVEL_THREE] += 1;
      number_of_problems += 1;
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      system("clear");
    }

    else if (user_answer != correct_answer)
    {
      printf("Sorry, the answer was %.3lf\n", correct_answer);
      number_incorrect[LEVEL_THREE] += 1;
      number_of_problems += 1;
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      system("clear");
    }
    else
    {
      printf("ERROR SCORING PROBLEM 3\n");
      number_of_problems += 1;
    }
  }
  play_next_level(level_choice);
}

void play_level_four(char *problem, int number_correct[6], int number_incorrect[6], int *level_choice)
{
  int number_of_problems = 1;
  double user_answer = 0, correct_answer = 0;

  while (number_of_problems <= 10)
  {
    printf("Level 4 Problem %d: ", number_of_problems);
    generate_level_four_problem(problem);
    correct_answer = solve_problem(problem);
    printf("Enter your answer: ");
    scanf("%lf", &user_answer);

    if (user_answer == correct_answer)
    {
      printf("Nice! You got it!\n");
      number_correct[LEVEL_FOUR] += 1;
      number_of_problems += 1;
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      system("clear");
    }

    else if (user_answer != correct_answer)
    {
      printf("Sorry, the answer was %.3lf\n", correct_answer);
      number_incorrect[LEVEL_FOUR] += 1;
      number_of_problems += 1;
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      system("clear");
    }
    else
    {
      printf("ERROR SCORING PROBLEM 4\n");
      number_of_problems += 1;
    }
  }
  play_next_level(level_choice);
}

//Function that lets the player play level occurence
void play_level_five(char *problem, int number_correct[10], int number_incorrect[10], int *level_choice)
{
  int number_of_problems = 1;
  double correct_answer = 0.0, user_answer = 0.0;
  while (number_of_problems <= 10)
  {
    //Generates easy problems
    if (number_correct[LEVEL_FIVE] <= 3)
    {
      //Creates and displays the problem
      printf("Difficulty: EASY\n");
      printf("Level 5 Problem %d: ", number_of_problems);
      generate_level_five_problem(problem, EASY);
      correct_answer = solve_problem(problem);

      printf("Enter your answer: ");
      scanf("%lf", &user_answer);

      //Checks answer; updates scoring
      if (user_answer == correct_answer)
      {
        printf("Nice! You got it!\n");
        number_correct[LEVEL_FIVE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else if (user_answer != correct_answer)
      {
        printf("Sorry! The answer was %.3lf...\n", correct_answer);
        number_incorrect[LEVEL_FIVE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else
      {
        printf("ERROR SCORING PROBLEM 5\n");
        number_of_problems += 1;
      }

    }

    else if (number_correct[LEVEL_FIVE] <= 7)
    {
      //Creates and displays the problem
      printf("Difficulty: MEDIUM\n");
      printf("Level 5 Problem %d: ", number_of_problems);
      generate_level_five_problem(problem, MEDIUM);
      correct_answer = solve_problem(problem);
      printf("Enter your answer: ");
      scanf("%lf", &user_answer);

      //Checks answer; updates scoring
      if (user_answer == correct_answer)
      {
        printf("Nice! You got it!\n");
        number_correct[LEVEL_FIVE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else if (user_answer != correct_answer)
      {
        printf("Sorry! The answer was %.3lf...\n", correct_answer);
        number_incorrect[LEVEL_FIVE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else
      {
        printf("ERROR SCORING PROBLEM 5\n");
        number_of_problems += 1;
      }

    }

    else if (number_correct[LEVEL_FIVE] <= 10)
    {
      //Creates and displays the problem
      printf("Difficulty: HARD");
      printf("Level 5 Problem %d: ", number_of_problems);
      generate_level_five_problem(problem, HARD);
      correct_answer = solve_problem(problem);
      printf("Enter your answer: ");
      scanf("%lf", &user_answer);

      //Checks answer; updates scoring
      if (user_answer == correct_answer)
      {
        printf("Nice! You got it!\n");
        number_correct[LEVEL_FIVE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else if (user_answer != correct_answer)
      {
        printf("Sorry! The answer was %.3lf...\n", correct_answer);
        number_incorrect[LEVEL_FIVE] += 1;
        number_of_problems += 1;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
        system("clear");
      }
      else
      {
        printf("ERROR SCORING PROBLEM 5\n");
        number_of_problems += 1;
      }

    }

  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////PROBLEM SOLVING FUNCTIONS

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
char find_last_occurence(char *problem, char *ops)
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

  last_operator = find_last_occurence(problem, "+-");

  if(!char_compare(last_operator, '+') || !char_compare(last_operator, '-'))
  {
    if (!char_compare(last_operator, '+'))
    {
      my_strtok(problem, '+', new_lhs, new_rhs);
      return solve_problem(new_lhs) + solve_problem(new_rhs);
    }
    if (!char_compare(last_operator, '-'))
    {
      my_strtok(problem, '-', new_lhs, new_rhs);
      return solve_problem(new_lhs) - solve_problem(new_rhs);
    }

  }

  last_operator = find_last_occurence(problem, "*/");

  if(!char_compare(last_operator, '*') || !char_compare(last_operator, '/'))
  {
    if (!char_compare(last_operator, '*'))
    {
      my_strtok(problem, '*', new_lhs, new_rhs);
      return solve_problem(new_lhs) * solve_problem(new_rhs);
    }
    if (!char_compare(last_operator, '/'))
    {
      my_strtok(problem, '/', new_lhs, new_rhs);
      return solve_problem(new_lhs) / solve_problem(new_rhs);
    }

  }
  return atoi(problem);
}

//Function that calculates and displays endgame stats
void calculate_and_display_stats(int number_correct[6], int number_incorrect[6], FILE *outfile)
{
  double total_correct = 0.0, total_incorrect = 0.0, total = 0.0, percent_correct = 0.0;

  //Calculates and prints total correct/incorrect for every level
  for (int i=LEVEL_ONE; i<=LEVEL_FIVE; i++)
  {

    //Calculates and prints stats for one level
    printf("LEVEL %d:\n", i);
    printf("Total correct: %d\n", number_correct[i]);
    printf("Total incorrect: %d\n", number_incorrect[i]);
    percent_correct = (double)number_correct[i] / 10.0; //Number of problems per level
    printf("Percent correct: %.2lf\n", percent_correct * 100);
    total_correct += number_correct[i];
    total_incorrect += number_incorrect[i];
    total += 10; //Number of problems per level
  }
  printf("\nTotal answered correctly: %.2lf\n", total_correct);
  printf("Total answered incorrectly: %.2lf\n", total_incorrect);
  printf("Total percent answered correctly: %.2lf\n", total_incorrect / total * 100);

}
