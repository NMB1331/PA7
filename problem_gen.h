#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define LEVEL_ONE 1
#define LEVEL_TWO 2
#define LEVEL_THREE 3
#define LEVEL_FOUR 4
#define LEVEL_FIVE 5
#define PROBLEM_SIZE 10

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
int user_interface(char *initials);

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////PROBLEM GENERATION FUNCTIONS

/*************************************************************
* Function: generate_operator                               *
* Date Created: 11/13/2016                                  *
* Date Last Modified: 11/13/2016                            *
* Description: Generates a mathematical operator            *
* Input parameters: None                                    *
* Returns: Characters +, -, *, /                            *
* Preconditions: None                                       *
* Postconditions: None                                      *
*************************************************************/
char generate_operator(int level);
