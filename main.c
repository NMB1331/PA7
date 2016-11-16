#include "problem_gen.h"
#include "problem_gen.c"

int main(void)
{
  char problem[20], initials[3];
  int number_correct[6], number_incorrect[6];
  char wanna_keep_going = 'Y';

  int level_choice = welcome_screen(initials);
  if (level_choice == 1)
  {
    play_level_one(problem, number_correct, number_incorrect);
  }
  /*
  if (level_choice == 2)
  {
    play_level_two();
  }
  if (level_choice == 3)
  {
    play_level_three();
  }
  if (level_choice == 4)
  {
    play_level_four();
  }
  if (level_choice == 5)
  {
    play_level_five();
  }
  */
printf("Now, the cutting and pasting begins....\n");

}

/*
NOTES:
  -nest main game code in do-while loop
  -prompt user to keep playing after they complete a level
*/
