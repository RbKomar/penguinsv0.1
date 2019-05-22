#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "headers/structures.h"
#include "sources/legality.c"
#include "sources/player.c"
#include "sources/board.c"
#include "sources/savehandler.c"
#include "sources/menu.c"
#include "sources/penguin.c"
#include "sources/manualgamemode.c"



int main(int argc, char *argv[]) {
    if (argc > 4) {

        srand(time(0));

        int playersNumber = atoi(argv[1]);
        int penguinsNumber = atoi(argv[2]);
        int dimx = atoi(argv[3]), dimy = atoi(argv[4]);

        int ask_auto;

        if (checkInputParameters(playersNumber, dimx, dimy, penguinsNumber)) {


            GameState gameState;
            gameState.players = (Player *) malloc(sizeof(Player) * playersNumber);
            gameState.map = (IceFloe **) malloc(sizeof(IceFloe) * dimx * dimy);
            for(int i=0;i<playersNumber;i++)
            {
                gameState.players[i].penguins = (Penguin *) malloc(sizeof(Penguin) * penguinsNumber);
            }

            do{// Playing Phase (PP)

                gameState.endGame = menu(dimx, dimy, playersNumber, penguinsNumber, gameState.map, gameState.players);
                if(gameState.endGame)
                {
                    return 0;
                }
                printf("Begin Game\nType 1 for human control, type 0 for automatic play \n");
                scanf("%d", &ask_auto);
                if(ask_auto == 1)
                {
                    manual_play(gameState, dimx, dimy, playersNumber, penguinsNumber, gameState.map, gameState.players);
                    gameState.endGame=1;
                }
                else
                {
                    //automatic_play();
                    printf("Automatic play not implemented yet \n");
                    gameState.endGame=1;
                }


            }while(!gameState.endGame); //finish the game when argument endGame is 1

            return 0;

        }else{

        }
    }
}