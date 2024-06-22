#include<stdio.h>
#include "functions.c"

int main()
{   
    int cards [4][11] = {-1}; /*fisrt braket for players 0 to 3*/
    /*second braket for cards of each player*/
    int card [44];
    char Hokm;
    int player1_cards[NUMBEROFCARDS];
    int player2_cards[NUMBEROFCARDS];
    int player3_cards[NUMBEROFCARDS];
    int player4_cards[NUMBEROFCARDS];
    int set_score1 = 0;
    int set_score2 = 0;
    char first_choise;  
    int winnerplayer = 1;
    
    while (set_score1 < FINISH_GAME && set_score2 < FINISH_GAME)
    {   
        int point_team1 = 0;
        int point_team2 = 0;

        while (point_team1 < FINISH_POINT && point_team2 < FINISH_POINT)
        {   
            int choise1 = EMPTY;
            int choise2 = EMPTY;
            int choise3 = EMPTY;
            int choise4 = EMPTY;
            int round = 1;

            if (point_team1 == 0 && point_team2 == 0)
            {
                winnerplayer = 1;
                Hokm = distribute_cards(card,cards,player1_cards,player2_cards,player3_cards,player4_cards);
            }
            
            if (winnerplayer == 1)
            {
                board(point_team1,point_team2,choise1,choise2,choise3,choise4,set_score1,set_score2);
                sym_num(player1_cards);
                choise1 = user_player(player1_cards, round,Hokm,first_choise, &winnerplayer);
                round += 1;
                first_choise = symbol(choise1);              
                choise2 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);
                choise3 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);                
                choise4 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);                      
            }
            
            else if (winnerplayer == 2)
            {               
                choise2 = player(player2_cards,player3_cards,player4_cards,round,first_choise, Hokm, &winnerplayer);
                round += 1;
                first_choise = symbol(choise2);
                choise3 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);
                choise4 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);
                board(point_team1,point_team2,choise1,choise2,choise3,choise4,set_score1,set_score2);
                sym_num(player1_cards);
                choise1 = user_player(player1_cards, round,Hokm, first_choise, &winnerplayer);                 
            }

            else if (winnerplayer == 3)
            {   
                choise3 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);
                round += 1;
                first_choise = symbol(choise3);
                choise4 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);
                board(point_team1,point_team2,choise1,choise2,choise3,choise4,set_score1,set_score2);
                sym_num(player1_cards);                
                choise1 = user_player(player1_cards, round,Hokm,first_choise, &winnerplayer);
                choise2 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);
            }

            else if (winnerplayer == 4)
            {      
                choise4 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);
                round += 1;
                first_choise = symbol(choise4);
                board(point_team1,point_team2,choise1,choise2,choise3,choise4,set_score1,set_score2);
                sym_num(player1_cards);              
                choise1 = user_player(player1_cards, round,Hokm,first_choise, &winnerplayer);
                choise2 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);
                choise3 = player(player2_cards,player3_cards,player4_cards,round,first_choise,Hokm, &winnerplayer);       
            }
            
            winnerplayer = judgement(choise1,choise2,choise3,choise4,Hokm,first_choise,&point_team1,&point_team2,&set_score1,&set_score2);
            board(point_team1,point_team2,choise1,choise2,choise3,choise4,set_score1,set_score2);
            sym_num(player1_cards);
        }     
    }
}
