#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// one Player plays a Rock-Paper-Scissors game with a computer

#define NUM_OBJECTS 3

int main() {
    int player, player_score = 0;
    int computer, pc_score = 0;
    int againPlay = 1, n = 0;
    
    printf("\tWelcome! Rock Paper Scissors Game!\n\n");
    printf("\t\tGame Start!\n\n");
    
    // Main loop for paly again, user enters 1 to continue the game, or 0 to quit 
    do
    {
        player_score = 0;
        pc_score = 0;
        do
        {
            srand(time(NULL));
            n = rand() % 100 ;
            if (n < 33)  
                computer = 1;
            else if (n > 33 && n < 66)  
                computer = 2;
            else computer = 3;

            printf("Please enter your choice (1=Rock, 2=Paper, 3=Scissors):  ");
            scanf("%d", &player);

            if (player == computer)
            {
                printf("Tie!\n");
            } else if (player == 1)
            {
                if (computer == 3)
                {
                    printf("Rock crushes Scissors. You win!\n");
                    player_score += 1;
                } else {
                    printf("Paper covers Rock. You lose.\n");
                    pc_score += 1;
                }
            } else if (player == 2)
            {
                if (computer == 1)
                {
                    printf("Paper covers Rock. You win!\n");
                    player_score += 1;
                } else {
                    printf("Scissors cuts Paper. You lose.\n");
                    pc_score += 1;
                }
            } else if (player == 3)
            {
                if (computer == 2)
                {
                    printf("Scissors cuts Paper. You win!\n");
                    player_score += 1;
                } else {
                    printf("Rock crushes Scissors. You lose.\n");
                    pc_score += 1;
                }
            }

            if (player_score == 2 || pc_score == 2)
            {
                if (player_score == 2)
                {
                    printf("Best 2 out of 3. You are the winner!\n");
                } else {
                    printf("You lose. Thank you for your play.\n");
                }
            }
        } while (player_score != 2 && pc_score != 2);

        printf("Play Again?\n"
          "Enter your choice <1-continue play | 0-quit>:  ");
        scanf("%d", &againPlay);
    } while (againPlay = 1);
    return 0;
}
