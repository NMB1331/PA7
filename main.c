#include "problem_gen.h"
#include "problem_gen.c"

int main(void)
{
  srand((unsigned int) (time NULL));
  char problem[20], initials[3];
  int number_correct[6] = { 0 };
  int number_incorrect[6] = { 0 };
  int level_choice = 0;
  FILE *outfile = fopen("game_log.txt", "w");

  //Gets the players initials and choice of level
  level_choice = welcome_screen(initials);
  fprintf(outfile, "PLAYER INITIALS: %s\n", initials);

  //Lets the player play a level; prompts them to continue
  if (level_choice == 1)
  {
    play_level_one(problem, number_correct, number_incorrect, &level_choice);
  }

  if (level_choice == 2)
  {
    play_level_two(problem, number_correct, number_incorrect, &level_choice);
  }

  if (level_choice == 3)
  {
    play_level_three(problem, number_correct, number_incorrect, &level_choice);
  }

  if (level_choice == 4)
  {
    play_level_four(problem, number_correct, number_incorrect, &level_choice);
  }
  if (level_choice == 5)
  {
    play_level_five(problem, number_correct, number_incorrect, &level_choice);
  }

//Thanks the player for playing; displays stats; prints stats to outfile
printf("Damn! Way to slay those math problems!\n");
printf("Here's your stats: \n");
calculate_and_display_stats(number_correct, number_incorrect, outfile);


fclose(outfile); //outfile = fclose(outfile);
return 0;
}
