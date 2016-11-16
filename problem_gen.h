#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <curses.h>

#define LEVEL_ONE 1
#define LEVEL_TWO 2
#define LEVEL_THREE 3
#define LEVEL_FOUR 4
#define LEVEL_FIVE 5
#define PROBLEM_SIZE 20
#define EASY 1
#define MEDIUM 2
#define HARD 3

//////////////////////////////GAME SETUP FUNCTIONS//////////////////////////////////////////////////////////////////////

/*************************************************************
* Function: user_interface                                  *
* Date Created: 11/12/2016                                  *
* Date Last Modified: 11/12/2016                            *
* Description: Welcomes player; gets input for what to do (instructions, select level, etc.)
* Input parameters: String initials                         *
* Returns: Integer corresponding to choice                  *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
int welcome_screen(char *initials);

/*************************************************************
* Function: print_rules                                     *
* Date Created: 11/12/2016                                  *
* Date Last Modified: 11/12/2016                            *
* Description: Prints the rules, until the user understands them
* Input parameters: None                                    *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void print_rules(void);

/*************************************************************
* Function: get_initials                                    *
* Date Created: 11/12/2016                                  *
* Date Last Modified: 11/12/2016                            *
* Description: Gets the user's initials (3- 1st, mid, last) *
* Input parameters: String initials                         *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void get_initials(char *initials);

/*************************************************************
* Function: get_level                                       *
* Date Created: 11/13/2016                                  *
* Date Last Modified: 11/13/2016                            *
* Description: Lets the user select a difficulty level      *
* Input parameters: None                                    *
* Returns: Integer 1-5 (level choice)                       *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
int get_level(void);

/*************************************************************
* Function: play_next_level                                 *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Asks the user if they wish to continue       *
* Input parameters: Pointer to int level choice             *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void play_next_level(int *level_choice);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////PROBLEM GENERATION FUNCTIONS

/*************************************************************
* Function: reset_problem                                   *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Resets problem string to all null            *
* Input parameters: String problem (size 20)                *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void reset_problem(char *problem);

/*************************************************************
* Function: generate_basic_operator                         *
* Date Created: 11/13/2016                                  *
* Date Last Modified: 11/13/2016                            *
* Description: Generates a + or - pseudo randomly           *
* Input parameters: None                                    *
* Returns: Character + or -                                 *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
char generate_basic_operator(void);

/*************************************************************
* Function: generate_number                                 *
* Date Created: 11/13/2016                                  *
* Date Last Modified: 11/13/2016                            *
* Description: Generates a random number for problems       *
* Input parameters: None                                    *
* Returns: Character number, 1-9 (returns as type int)      *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
int generate_number(void);

/*************************************************************
* Function: generate_level_one_problem                      *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Generates an easy, med, or hard lvl 1 problem*
* Input parameters: String problem, int difficulty          *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void generate_level_one_problem(char *problem, int difficulty);

/*************************************************************
* Function: generate_level_two_problem                      *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Generates a problem for level 2              *
* Input parameters: String problem                          *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void generate_level_two_problem(char *problem);

/*************************************************************
* Function: generate_level_three_problem                     *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Generates a problem for level 3              *
* Input parameters: String problem                          *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void generate_level_three_problem(char *problem);

/*************************************************************
* Function: generate_level_four_problem                     *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Generates a problem for level 3              *
* Input parameters: String problem                          *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void generate_level_four_problem(char *problem);

/*************************************************************
* Function: generate_level_five_problem                     *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Generates an easy, med, or hard lvl 5 problem*
* Input parameters: String problem, int difficulty          *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void generate_level_five_problem(char *problem, int difficulty);

/*************************************************************
* Function: play_level_one                                  *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Plays and scores level one                   *
* Input parameters: String problem, number_correct[6], int number_incorrect[6]
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void play_level_one(char *problem, int number_correct[6], int number_incorrect[6], int *level_choice);

/*************************************************************
* Function: play_level_two                                  *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Plays and scores level two                   *
* Input parameters: String problem, number_correct[6], int number_incorrect[6]
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void play_level_two(char *problem, int number_correct[6], int number_incorrect[6], int *level_choice);

/*************************************************************
* Function: play_level_three                                *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Plays and scores level three                 *
* Input parameters: String problem, number_correct[6], int number_incorrect[6]
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void play_level_three(char *problem, int number_correct[6], int number_incorrect[6], int *level_choice);

/*************************************************************
* Function: play_level_four                                 *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Plays and scores level four                  *
* Input parameters: String problem, number_correct[6], int number_incorrect[6]
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void play_level_four(char *problem, int number_correct[6], int number_incorrect[6], int *level_choice);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////PROBLEM SOLVING/STATS FUNCTIONS

/*************************************************************
* Function: reverse                                         *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Reverses a string                            *
* Input parameters: A string                                *
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void reverse(char *str);

/*************************************************************
* Function: my_strtok                                       *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Tokenizes a string around a give char        *
* Input parameters: A string, a char, 2 output strings (left and right side)
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void my_strtok(char *problem, char op, char *new_lhs, char *new_rhs);

/*************************************************************
* Function: find_last_occurence                             *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Finds the last occurence of a char in a string
* Input parameters: A string problem, string of operators   *
* Returns: Character of the last operator                   *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
char find_last_occurence(char *problem, char *ops);

/*************************************************************
* Function: char_compare                                    *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Compares 2 characters                        *
* Input parameters: 2 characters                            *
* Returns: 0 if the same, 1 if different                    *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
int char_compare(char c1, char c2);

/*************************************************************
* Function: solve_problem                                   *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Solves a give math expression (string)       *
* Input parameters: String problem                          *
* Returns: Double solution to the problem                   *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
double solve_problem(char *problem);

/*************************************************************
* Function: calculate_and_display_stats                     *
* Date Created: 11/15/2016                                  *
* Date Last Modified: 11/15/2016                            *
* Description: Calculates and prints game stats             *
* Input parameters: File outfile, number_correct, number incorrect
* Returns: None                                             *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
void calculate_and_display_stats(int number_correct[6], int number_incorrect[6], FILE *outfile);
