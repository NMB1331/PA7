#include "problem_gen.h"

///////////////////////////////GAME SETUP FUNCTIONS/////////////////////////////

//Function that lets the user decide what to do (choose level, get instructions, etc.)
int user_interface(char *initials)
{
  //Determines whether or not to print the rules, or play the game
  int initial_choice = 0;
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
  return 1;

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

////////////////////////////////////////////////////////////////////////////////
