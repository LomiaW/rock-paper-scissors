#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_OBJECTS 3

int main() {
    int player, player_score = 0;
    int computer, computer_score = 0;
    int againPlay, n = 0;
    
    printf( "\t+------------------------------------+\n"
            "\t|Welcome to Rock-Paper-Scissors Game!|\n"
            "\t+------------------------------------+\n");
    
    do {    // main loop for playing the ganme again
        printf("\nGame Start!\n\n");
        player_score = 0;
        computer_score = 0;
        againPlay = 0;
        do {    // loop a round  until best 2 out of 3 and declare the winner
            srand(time(NULL));
            n = rand() % 100 ;
            if (n < 33 || n == 33)  computer = 1;
            if (n > 33 || n < 66)   computer = 2;
            if (n > 66 || n == 66)  computer = 3; // computer chooses random objects
            // prompt user to enter the choice
            printf("Please enter your choice (1=Rock|2=Paper|3=Scissors):  ");
            scanf("%d", &player);
            // compare player to computer each round and display the result
            if (player == 1)
            {
                switch (computer)
                {
                case 3:
                    printf("Rock crushes Scissors. You win!\n");
                    player_score ++; 
                    break;
                case 2:
                    printf("Paper covers Rock. You lose.\n");
                    computer_score ++; 
                    break;
                case 1:
                    printf("Tie!\n"); 
                    break;
                }
            } 
            if (player == 2)
            {
                switch (computer)
                {
                case 1:
                    printf("Paper covers Rock. You win!\n");
                    player_score ++; 
                    break;
                case 3:
                    printf("Scissors cuts Paper. You lose.\n");
                    computer_score ++; 
                    break;
                case 2:
                    printf("Tie!\n"); 
                    break;
                }        
            }
            if (player == 3)
            {
                switch (computer)
                {
                case 2:
                    printf("Scissors cuts Paper. You win!\n");
                    player_score ++; 
                    break;
                case 1:
                    printf("Rock crushes Scissors. You lose.\n");
                    computer_score ++; 
                    break;
                case 3:
                    printf("Tie!\n");
                    break;
                }
            }
            // display the best 2 out of 3 and delcare the winner or loser
            if (player_score == 2 || computer_score == 2)
            {
                printf("\nResult: \n");
                if (player_score == 2)
                {
                    printf("Best 2 out of 3. You are the winner!\n");
                } else {
                    printf("You lose. Thank you for playing the game.\n");
                }
            }
        } while (player_score < 2 && computer_score < 2);
        // prompt user to enter the choice for palying again or not
        printf("\nPlay Again?\n"
          "Enter your choice number <1=play again|0=quit>:  ");
        scanf("%d", &againPlay);
    } while (againPlay);
    return 0;
}
