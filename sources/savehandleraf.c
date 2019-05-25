#include"../headers/savehandleraf.h"
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

int loadGame(char *inputFilePath, char *outputFilePath){

    int dimx=0, dimy=0, icefloe=0, nPlayers=0, points=0;
    char name[50];


    FILE *load =fopen(inputFilePath, "r");
    if(load == NULL){
        perror("File opening error");
        return 0;
    }

//                      Board dimensions loading
//----------------------------------------------------------------------------------

    fscanf(load, "%d %d", &dimx, &dimy);
    printf("%d %d\n", dimx, dimy);

//                            Board loading
//----------------------------------------------------------------------------------


    IceFloe map[dimx][dimy];
    createEmptyBoard(dimx, dimy, map);

    for(int i=0; i<dimy; i++){
        for(int j=0; j<dimx;j++){
            fscanf(load, "%d", &icefloe);
            map[i][j].hasPenguin = icefloe % 10;
            icefloe /= 10;
            map[i][j].nFish = icefloe % 10;
            printf("%d%d ", map[i][j].nFish, map[i][j].hasPenguin);
        }
        printf("\n");
    }


//                    Players data loading
//----------------------------------------------------------------------------------


    long offset = ftell(load); //saving position

    while(!feof(load)){
        fscanf(load,"%s %d %d", name, &nPlayers, &points);
    }
    //last player number is number of players in Game

    fseek(load, offset, 0);//loading position

    Player players[nPlayers];
    createEmptyPlayers(players, nPlayers);

    for(int i=0; i<nPlayers; i++){
        fscanf(load,"%s %d %d", players[i].id, &players[i].number, &players[i].nPoints);
        printf("%s %d %d\n", players[i].id, players[i].number, players[i].nPoints);
    }

    fclose(load);

// After all we have two struct-typed arrays map[][] and players[][]
//----------------------------------------------------------------------------------
//TODO: assign them to gamemode or somehow connect to the rest of the automative mode
//TODO: write down the [values checkers] in order to throws error (remember about using perror() )

//    GameState gameState = { .map = (IceFloe **) malloc(sizeof(IceFloe) * dimx * dimy), .players = (Player *) malloc(sizeof(Player) * nPlayers), .phase = 1 };
//    free(gameState.map);
//    free(gameState.players);


    return 1;
}