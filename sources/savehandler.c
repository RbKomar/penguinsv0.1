#include"../headers/savehandler.h"
#include "errno.h"

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

GameState loadGame(){

    GameState gameState;
    int dimx, dimy;
    int icefloe;


    FILE *load =fopen("..\\saves\\inputboard.txt", "r");
    if(load == NULL){
        perror("File opening error");
        exit(-10);
    }
    fscanf(load, "%d %d", &dimx, &dimy);
    printf("%d %d\n", dimx, dimy);

    gameState.map = (IceFloe **)malloc(sizeof(IceFloe) * dimx * dimy);

    //works till i = 2 TODO: naprawic asap
    for(int i=0; i<dimy; i++){
        for(int j=0; j<dimx;j++){
            fscanf(load, "%d", &icefloe);
            gameState.map[i][j].hasPenguin = icefloe % 10;
            icefloe /= 10;
            gameState.map[i][j].nFish = icefloe % 10;
            printf("%d%d ", gameState.map[i][j].nFish, gameState.map[i][j].hasPenguin);
        }
        printf("\n");
    }


    free(gameState.map);
    fclose(load);
    return gameState;
}