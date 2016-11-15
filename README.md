# PA7
Washington State University Computer Science 121- Programming Assignment 7

Here it is, in the words of Head Code Coach Andy O'Fallon:

Mathematics is one of the most important, yet most difficult, subjects to teach and learn. We have all heard of the saying "Practice makes perfect".
Well I'm a huge believer in this saying and would like a software program which can generate various arithmetic problems and evaluate answers supplied
by the user.
 
For this assignment you will need to design and construct a basic math program which targets elementary school children. Your program must adhere to the following steps and requirements:
 
    1. (5 pts) A user interface with options similar to the following:
            a. Learn about how to use the program
            b. Enter your initials (3 individual characters...)
            c. Difficulty selection
            d. Start a new sequence of problems
            e. Save and Quit
    2. (25 pts - 5 pt/level) Generate mathematical problems based on the difficulty level selected. You must implement the following five levels of difficulty:
            a. Level 1 - Easy: Includes addition and subtraction problems, with positive single digit operands and up to three terms only (i.e. d1 + d2 - d3  = )
            b. Level 2 - Fair: Includes multiplication problems, with positive single digit operands and up to two terms only (i.e. d1 x d2 =  )
            c. Level 3 - Intermediate: Includes division problems, with positive single digit operands and up to two terms only (i.e. d1 / d2 =  ); 
                              Note: results should be shown in the form Num R Remainder, i.e. if the problem is 5 / 3, then the answer should be provided as 1 R 2.
            d. Level 4 - Hard: Includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative single digit operands
                               and up to three terms only (i.e. d1 + -d2 / d3 = ); Hint: you may have to first find a common denominator.
            e. Level 5 - Impossible: Includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative 
                              two and three digit operands and up to four terms only (i.e. dd1 + -ddd2 x ddd3 / dd4 = );
                              Hint: you may have to first find a common denominator.
    3. (5 pts) Allow the user to enter an answer corresponding to a generated math problem
    4. (10 pts) Evaluate the answer provided by the user. The user gets a certain number of points for correct answers 
                    and loses points for incorrect answers. The number of points should directly relate to the difficulty of the problem.
    5. (10 pts) Each level must generate a sequence of ten problems
    6. (10 pts) Within each level, problems should become a little more difficult as the user enters correct answers
    7. (10 pts) Once the user quits the program, output the user's initials and total score to a file
 
Your program must implement error checking where appropriate. It also must use strings, pointers, and output parameters where appropriate.
 
BONUS Opportunities:
    1. Implement a "load previous progress" feature (up to 10 pts)
    2. Implement a "help" feature, which illustrates step-by-step how to solve various addition, subtraction, multiplication, and division problems (up to 15 pts)
    3. Others? (up to 15 pts)
 
