#include "../headers/automative.h"

int automative(GameState gameState, char *phase, int dimx, int dimy, int nPlayers, int nPenguins, int ourPlayer){

    //WIEC TERA TA DZIELIMY SE NA PLACEMENT PHASE i MOVEMENT PHASE
    if(strcmp(phase, "placement") == 0)
    {
        AutoPlacement(gameState, dimx, dimy, ourPlayer, nPenguins);
       // saveGame(gameState, dimx, dimy, gameState.map, ourPlayer);
    }else if(strcmp(phase, "manual")== 0){
        AutoMovement(gameState, dimx, dimy, nPlayers, ourPlayer, nPenguins);
       // saveGame(gameState, dimx, dimy, gameState.map, ourPlayer);

    }
    //GITTARA

    return 0;
}

// AUTPLACEMENT FUNKCJA XD

int AutoPlacement(GameState gameState, int dimx, int dimy, int nPlayer, int nPenguins){

    int targetX=0, targetY=0, areProperValuesUsed;
    do {
        targetX = rand() % dimx;
        targetY = rand() %dimy;
        areProperValuesUsed = placePenguin(dimx, dimy, targetX, targetY, gameState.map, gameState.players, nPlayer, nPenguins);
    }while(areProperValuesUsed);

    placePenguin(dimx, dimy, targetX, targetY, gameState.map , gameState.players, nPlayer, nPenguins);
    return 0;
}

//AUTO

int AutoMovement(GameState gameState, int dimx, int dimy, int nPlayers, int playerNumber, int nPenguins){

    int choosenPenguin, penguinWithMoves, targetX, targetY, areProperValuesUsed;
    do{
        choosenPenguin = rand() % nPenguins;
        penguinWithMoves = checkPeng(dimx, dimy, gameState.map, gameState.players[playerNumber].penguins[choosenPenguin]);
    }while(penguinWithMoves);

    do {
        targetX = rand() % dimx;
        targetY = rand() % dimy;
        areProperValuesUsed = placePenguin(dimx, dimy, targetX, targetY, gameState.map, gameState.players, playerNumber, choosenPenguin);
    }while(areProperValuesUsed);


    MovePenguin(dimx, dimy, gameState.map, nPlayers, gameState.players, choosenPenguin, playerNumber, gameState.players[playerNumber].penguins[choosenPenguin].pengPositionX,gameState.players[playerNumber].penguins[choosenPenguin].pengPositionY,targetX,targetY);

    return 0;
}