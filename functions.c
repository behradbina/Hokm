#include <stdio.h>
#include "shuffle_card.c"

#define NUMBEROFCARDS 11
#define EMPTY -50 /*It's for used cards*/
#define LENGTH 22
#define WIDTH 7
#define FINISH_POINT 6
#define FINISH_GAME 5

char symbol(int number);
int indexofcard(int number);
int max_value(int cards_of_player[NUMBEROFCARDS]);
int min_value(int cards_of_player[NUMBEROFCARDS]);
void board(int point_team1,int point_team2, int choise1, int choise2, int choise3, int choise4, int set_score1, int set_score2);
void sym_num(int card_of_player1[NUMBEROFCARDS]);
int check_all_cards_are_hokm(int card_of_player[NUMBEROFCARDS], char hokm);
int converter_hokm_to_number(char symbol);
int havingSymbol(int cards_of_player[NUMBEROFCARDS], char sym);
int judgement(int ch1, int ch2, int ch3, int ch4, char hokm, char first_choise,
              int* point_team1,int* point_team2, int* set_score1, int* set_score2);
int player (int player2_cards[NUMBEROFCARDS],int player3_cards[NUMBEROFCARDS],
            int player4_cards[NUMBEROFCARDS],int round, int firstchoice, char hokm, int *player_number);
char distribute_cards(int card[4*NUMBEROFCARDS], int cards[4][NUMBEROFCARDS],
                    int player1_cards[NUMBEROFCARDS], int player2_cards[NUMBEROFCARDS],int player3_cards[NUMBEROFCARDS]
                    ,int player4_cards[NUMBEROFCARDS]);
int user_player(int player1_cards[NUMBEROFCARDS], int round, char hokm, char first_choise, int* player_number);
void sort_cards(int player1_cards[NUMBEROFCARDS]);

/*return the symbol of card*/
char symbol(int number)
{
    char sym = 'F';
    int a = number / NUMBEROFCARDS;

    switch (a)
    {
    case 0:
        sym = 'A';
        break;       
    case 1:
        sym = 'B';
        break;        
    case 2:
        sym = 'C';
        break;       
    case 3:
        sym = 'D';
        break;    
    default:
        break;
    }
    
    return sym;  
}
/*return the number of card*/
int indexofcard(int number)
{
    int result = (number % NUMBEROFCARDS) + 1;
    return result;
}
/*return the maximum value of a list*/
int max_value(int cards_of_player[NUMBEROFCARDS])
{
    int max = cards_of_player[0];
    for (int i = 0; i < NUMBEROFCARDS; i++) 
    {     
        if(cards_of_player[i] > max)    
           max = cards_of_player[i];    
    }
    return max;
}
/*return the minimum value of a list*/
int min_value(int cards_of_player[NUMBEROFCARDS])
{
    int min = cards_of_player[0];
    for (int i = 0; i < NUMBEROFCARDS; i++) 
    {     
        if(cards_of_player[i] < min)    
           min = cards_of_player[i];    
    }
    return min;
}
//board of the game
void board(int point_team1,int point_team2, int choise1, int choise2, int choise3, int choise4, int set_score1, int set_score2)
{ 

    for (int i = 1; i <= WIDTH + 4 ; i++)
    {
        if (i != (WIDTH + 5) / 2)
        {
            printf("\t");
        }
       
        if (i == 1)
        {
            for (int m = 0; m < LENGTH / 2; m++)
            {
                printf(" ");
            }
            printf("P3");
        }
        else if (i == 2)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                printf("-");
            }
            printf("\t\tTeam 1:%d\t\tSET: %d", point_team1,set_score1);
        }

        else if (i == 3) /*printing the choise of player 3 */
        {   
            printf("|");
            for (int m = 0; m < LENGTH - 2; m++)
            {
                if (m == (LENGTH / 2) - 1)
                {   
                    if (choise3 == EMPTY)
                    {
                        printf("00");
                    }
                    else
                    {
                        printf("%c%d",symbol(choise3),indexofcard(choise3));
                        if (indexofcard(choise3) > 9)
                        {
                            m++;
                        }                     
                    }                              
                }

                else
                    printf(" ");
                
            }
            printf("|");
        }

        else if (i == WIDTH + 2) /*printing the choise of player 1 */
        {   
            printf("|");
            for (int m = 0; m < LENGTH - 2; m++)
            {
                if (m == (LENGTH / 2) - 1)
                {
                    if (choise1 == EMPTY)
                    {
                        printf("00");
                    }
                    else
                    {
                        printf("%c%d",symbol(choise1),indexofcard(choise1));
                        if (indexofcard(choise1) > 9)
                        {
                            m++;
                        }
                    }                
                }
                else
                {
                    printf(" ");
                }
            }
            printf("|");
        }

        else if (i == WIDTH + 3)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                printf("-");
            }
            printf("\t\tTeam 2:%d\t\tSET:%d", point_team2, set_score2);
        }
       
        else if (i == WIDTH + 4)
        {
            for (int m = 0; m < LENGTH/2; m++)
            {
                printf(" ");
            }
            printf("P1");
        }

        else if (i == (WIDTH + 5) / 2)
        {
            int n = 0;
            printf("      P2");
            printf("|");
            if (choise2 == EMPTY)
            {
                printf("00");
            }
            else
            {   
                /*printing the choise of player 2 */
                printf("%c%d",symbol(choise2),indexofcard(choise2));
                if (indexofcard(choise2) > 9)
                {
                    n++;
                }
            }

            for (int j = n; j < LENGTH - 6; j++)
            {
                printf(" ");
            }
            
            if (choise4 == EMPTY)
            {
                printf(" 00");
            }
            else
            {   
                /*printing the choise of player 4 */
                if (indexofcard(choise4) > 9)
                {
                    printf("%c%d",symbol(choise4),indexofcard(choise4));
                }
                else
                {
                    printf(" %c%d",symbol(choise4),indexofcard(choise4));
                }           
            }

            printf("|");
            printf("P4\t");
        }
           
        else
        {
            printf("|");
            for (int i = 0; i < LENGTH - 1; i++)
            {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}
/*printing the cards of you have*/
void sym_num(int card_of_player1[NUMBEROFCARDS])
{
    for (int i = 1; i <= 6; i++)
    {
        while (i != 2 && i != 4)
        {
            printf("\t");
            break;
        }

        if (i == 1 || i == 3 || i == 5)
        {
            for (int j = 0; j < LENGTH + NUMBEROFCARDS; j++)
            {
                printf("-");
            }
            printf("\n");
        }

        else if (i == 2) /*printig symbol of cards you have*/
        {
            printf("SYMBOL |");

            for (int j = 0; j < NUMBEROFCARDS; j++)
            {           
                if (card_of_player1[j] != EMPTY)
                {
                    printf("%c |", symbol(card_of_player1[j]));
                }
                else
                {
                    printf("- |");
                }
            }
            printf("\n");
        }

        else if (i == 4) /*printig number of cards you have*/
        {
            printf("NUMBER |");
            for (int j = 0; j < NUMBEROFCARDS; j++)
            {   
                if (card_of_player1[j] != EMPTY && indexofcard(card_of_player1[j]) > 9)
                {
                    printf("%d|", indexofcard(card_of_player1[j]));
                }
                else if (card_of_player1[j] != EMPTY && indexofcard(card_of_player1[j]) < 10)
                {
                    printf("%d |", indexofcard(card_of_player1[j]));
                }
                else if (card_of_player1[j] == EMPTY)
                {
                    printf("- |");
                }   
                
            }
            printf("\n");

        }

        else if (i == 6)
        {           
            for (int j = 0; j < NUMBEROFCARDS; j++)
            {
                printf(" %d ", j);
            }
            printf("\n\n");
        }  
    }   
}
/*The below function checks weather all cards are hokm or not! */
int check_all_cards_are_hokm(int card_of_player[NUMBEROFCARDS], char hokm) 
{
    for (int i = 0; i < NUMBEROFCARDS; i++)
    {
        if (symbol(card_of_player[i]) != hokm && card_of_player[i] != EMPTY)
        {
            return 0;
        }        
    }
    return 1;
}

int converter_hokm_to_number(char symbol)
{
    if (symbol == 'A')
    {
        return (0 * NUMBEROFCARDS);
    } 
    else if (symbol == 'B')
    {
        return (1 * NUMBEROFCARDS);
    }
    else if (symbol == 'C')
    {
        return (2 * NUMBEROFCARDS);
    }    
    else if (symbol == 'D')
    {
        return (3 * NUMBEROFCARDS);
    }
    else
    {
        printf("converter_hokm_to_number function error!!!\n");
    }   
}
/*The below function checks weather there is at least a card with determinded symbol*/
int havingSymbol(int cards_of_player[NUMBEROFCARDS], char sym)
{
    for (int i = 0; i < NUMBEROFCARDS; i++)
    {
        if (symbol(cards_of_player[i]) == sym)
            return 1;
    }
    return 0;
}
/*determind which team is the winner*/
int judgement(int ch1, int ch2, int ch3, int ch4, char hokm, char first_choise,int* point_team1,
                int* point_team2, int* set_score1, int* set_score2)
{
    int choises [4] = {ch1, ch2, ch3, ch4};
   
    for (int i = 0; i < 4; i++)
    {
        if (symbol(choises[i]) == hokm)
        {
            choises[i] += 44;
        }
        else if (symbol(choises[i]) != first_choise && symbol(choises[i]) != hokm)
        {
            choises[i] *= 0;
        }     
    }
    
    int max = choises[0];
    int winner = 0;

    for (int i = 0; i < 4; i++) 
    {     
        if(choises[i] > max)    
           max = choises[i];    
    }

    for (winner ; winner < 4; winner++)
    {
        if (choises[winner] == max)
        {
            break;
        }        
    } 

    if (winner == 0 || winner == 2)
    {
        (*point_team1) ++;
        winner ++;
    }
    else if (winner == 1 || winner == 3)
    {
        (*point_team2) ++;
        winner ++;
    }

    if (*point_team1 == FINISH_POINT && *point_team2 != 0)
    {   
        (*set_score1) += 1;
        printf("TEAM 1 WIN!\n");
    }
    else if (*point_team1 == FINISH_POINT && *point_team2 == 0)
    {   
        (*set_score1) += 2;
        printf("TEAM 1 WIN!\n");
    }
    else if (*point_team2 == FINISH_POINT && *point_team1 != 0)
    {
        (*set_score2) += 1;
        printf("TEAM 2 WIN!\n");
    }
    else if (*point_team2 == FINISH_POINT && *point_team1 == 0)
    {
        (*set_score2) += 2;
        printf("TEAM 2 WIN!\n");
    }

    if (*set_score1 >= FINISH_GAME)
    {
        printf("THE MAIN WINNER IS : TEAM 1\n");
    }
    else if (*set_score2 >= FINISH_GAME)
    {
        printf("THE MAIN WINNER IS : TEAM 2\n");
    }

    return winner;
}

int player(int player2_cards[NUMBEROFCARDS],int player3_cards[NUMBEROFCARDS],
            int player4_cards[NUMBEROFCARDS],int round, int firstchoice, char hokm, int *player_number)
{   
    int *card_of_player;
    int number_of_each_card [NUMBEROFCARDS];
    int choise = 0;
    int flag = 0;
    int temp [NUMBEROFCARDS] = {0}; /*shomre kart haye gheir hokm ra zakhire mikonad*/

    if (*player_number == 2)
    {
        card_of_player = player2_cards;
    }
    else if (*player_number == 3)
    {
        card_of_player = player3_cards;
    }
    else if (*player_number == 4)
    {
        card_of_player = player4_cards;
    }
       
    if (round == 1)
    {
        if (check_all_cards_are_hokm(card_of_player,hokm))
        {
            choise = max_value(card_of_player);
        }
        else
        {
            for (int i = NUMBEROFCARDS; i > 0; i--)
            {
                for (int j = 0; j < NUMBEROFCARDS; j++)
                {
                    if (indexofcard(card_of_player[j]) == i && symbol(card_of_player[j]) != hokm)
                    {
                        choise = card_of_player[j];
                        flag = 1;
                        break;
                    }                    
                }
                if (flag == 1)
                {
                    break;
                }                
            }             
        }          
    }

    else
    {
        if (havingSymbol(card_of_player,firstchoice))
        {
            for (int i = 0; i < NUMBEROFCARDS; i++)
            {
                if (converter_hokm_to_number(firstchoice) <= card_of_player[i] &&
                 card_of_player[i] < converter_hokm_to_number(firstchoice) + 11)
                {
                    temp[i] = card_of_player[i];
                }               
            }
            
            choise = max_value(temp);
        }
        else
        {
            if (havingSymbol(card_of_player,hokm))
            {
                for (int i = 0; i < NUMBEROFCARDS; i++)
                {
                    if (converter_hokm_to_number(hokm) <= card_of_player[i] &&
                    card_of_player[i] < converter_hokm_to_number(hokm) + 11)
                    {
                        temp[i] = card_of_player[i];
                    }                  
                }
            
                choise = max_value(temp);
            }
            else
            {
                for (int i = 0; i <= NUMBEROFCARDS; i++)
                {
                    for (int j = 0; j < NUMBEROFCARDS; j++)
                    {
                        if (indexofcard(card_of_player[j]) == i)
                        {
                            choise = card_of_player[j];
                            flag = 1;
                            break;
                        }                      
                    }

                    if (flag == 1)
                    {
                        break;
                    }   
                }              
            }           
        }     
    }
    
    if (*player_number != 4)
    {
        (*player_number) ++;
    }
    else
    {
        (*player_number) = 1;
    }
    
    int main_choise = choise;

    for (int i = 0; i < NUMBEROFCARDS; i++)
    {
        if (choise == card_of_player[i])
        {
            card_of_player[i] = EMPTY;
            break;
        }        
    }
    return main_choise;
}

int user_player(int player1_cards[NUMBEROFCARDS], int round, char hokm, char first_choise, int* player_number)
{
    int flag = 0;
    int index = -1;
    int choise;
    int main_choise;

    while (flag == 0)
    {
        printf("Please choose your card:");
        fflush(stdin);
        scanf("%d", &index);
        
        if (0 > index || index >= NUMBEROFCARDS)
        {
            printf("Please put the right number!!!\n");
            continue;
        }
        else if (player1_cards[index] == EMPTY)
        {
            printf("This card is already used!\n");
            continue;
        }
        
        else if (0 <= index && index < NUMBEROFCARDS && player1_cards[index] != EMPTY)
        {
            if (round == 1)
            {
                break;
            }
            else
            {
                if (havingSymbol(player1_cards,first_choise))
                {
                    if (symbol(player1_cards[index]) == first_choise)
                    {
                        break;
                    }
                    else
                    {
                        printf("You have %c\n", first_choise);
                        continue;
                    }                            
                }
                else
                {
                    flag = 1;                                 
                }                            
            }                   
        }                    
    }

    choise = player1_cards[index];
    main_choise = choise;
    (*player_number)++;
    for (int i = 0; i < NUMBEROFCARDS; i++)
    {
        if (choise == player1_cards[i])
        {
            player1_cards[i] = EMPTY;
            break;
        }                  
    }
    sort_cards(player1_cards);
    return main_choise;
}
//This function distributes cards and returns the hokm
char distribute_cards(int card[4*NUMBEROFCARDS], int cards[4][NUMBEROFCARDS], int player1_cards[NUMBEROFCARDS], int player2_cards[NUMBEROFCARDS],int player3_cards[NUMBEROFCARDS]
    ,int player4_cards[NUMBEROFCARDS])
{
    int numberofcard = 0;
    char Hokm;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < NUMBEROFCARDS; j++)
        {
            cards[i][j] = EMPTY;
        }                 
    }
    
    shuffle_card(card);

    for (int player = 0; player < 4; player++) /*pakhsh 5 card aval be har bazikon*/
    {
        for (int c = 0; c < 5; c++)
        {
            cards[player][c] = card[numberofcard];
            numberofcard += 1;
        }    
    }

    for (int i = 0; i < NUMBEROFCARDS; i++)
    {
        player1_cards[i] =cards[0][i];
    }
    sym_num(player1_cards);

    while (1)
    {
        printf("Hokm ro entekhab kon (A,B,C,D) : ");
        fflush(stdin); 
        scanf("%c", &Hokm);
        printf("\n");

        if (Hokm == 'A' || Hokm == 'B' || Hokm == 'C' || Hokm == 'D')
        {
            break;
        }
        else
        {
            printf("Please put the right character!\n");                      
        }     
    }

    /*pakhsh 4 card badi*/
    for (int player = 0; player < 4; player++)
    {
        for (int c = 5; c < 9; c++)
        {
            cards[player][c] = card[numberofcard];
            numberofcard += 1;
        }    
    }

    /*pakhsh 2 card badi*/
    for (int player = 0; player < 4; player++)
    {
        for (int c = 9; c < NUMBEROFCARDS; c++)
        {
            cards[player][c] = card[numberofcard];
            numberofcard += 1;
        }    
    }

    /*ijad dast har bazikon*/
    for (int i = 0; i < NUMBEROFCARDS; i++)
    {
        player1_cards[i] =cards[0][i];
        player2_cards[i] =cards[1][i];
        player3_cards[i] =cards[2][i];
        player4_cards[i] =cards[3][i];
    }

    sort_cards(player1_cards);
    return Hokm;
}

void sort_cards(int player1_cards[NUMBEROFCARDS])
{
    int temp = EMPTY;
    for (int i = 0; i < NUMBEROFCARDS; i++)
    {
        for (int j = i; j < NUMBEROFCARDS; j++)
        {
            if (player1_cards[i] < player1_cards[j])
            {
                temp = player1_cards[i];
                player1_cards[i] = player1_cards[j];
                player1_cards[j] = temp;
            }           
        }
    }
}
