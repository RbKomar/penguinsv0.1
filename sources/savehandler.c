#include"../headers/savehandler.h"

void saveGame(GameState gamestate, int dimx, int dimy, IceFloe icefloes[dimx][dimy], int PlayersNumbers){
   static int saveID=1;
    char str[10], SAVE_URL[20] = "..\\saves\\save";
    sprintf(str, "%d", saveID);
    FILE *save= fopen( strcat( strcat(SAVE_URL, str), ".txt"), "w" );
    fprintf(save, "%d %d", dimx, dimy);

    for (int i = 0; i < dimx; i++) {
        fprintf(save, "\n");
        for (int j = 0; j < dimy; j++)
            fprintf(save, "%d%d ", icefloes[i][j].nFish, icefloes[i][j].hasPenguin);
    }

    fprintf(save, "\n");

    for (int i = 0; i < PlayersNumbers; i++) {
        fprintf(save, "%s %d %d \n", gamestate.players[i].id, gamestate.players[i].number, gamestate.players[i].nPoints);
    }

    fclose(save);
    saveID++;

}
