#include "../headers/automative.h"

int automative(GameState gameState, char *phase, int dimx, int dimy, int nPlayers, int nPenguins, int ourPlayer){

    if(strcmp(phase, "placement") == 0)
    {
        AutoPlacement(gameState, dimx, dimy, ourPlayer, nPenguins);
       // saveGame(gameState, dimx, dimy, gameState.map, ourPlayer);
    }else if(strcmp(phase, "manual")== 0){
        AutoMovement(gameState, dimx, dimy, nPlayers, ourPlayer, nPenguins);
       // saveGame(gameState, dimx, dimy, gameState.map, ourPlayer);

    }

    return 0;
}


int AutoPlacement(GameState gameState, int dimx, int dimy, int nPlayer, int nPenguins){
    static int allPenguinsPlaced;
    if(allPenguinsPlaced != nPenguins){
        int targetX=0, targetY=0, areProperValuesUsed;
        do {
            targetX = rand() % dimx;
            targetY = rand() %dimy;
            areProperValuesUsed = placePenguin(dimx, dimy, targetX, targetY, gameState.map, gameState.players, nPlayer, nPenguins);
        }while(areProperValuesUsed);
        allPenguinsPlaced++;

        return 0;
    }else{
        return 1;
    }
}


int AutoMovement(GameState gameState, int dimx, int dimy, int nPlayers, int playerNumber, int nPenguins){

    if(checkPlayerMoves(dimx, dimy, nPenguins, gameState.map, gameState.players[playerNumber]) ){
        int choosenPenguin, penguinWithMoves, targetX, targetY, areProperValuesUsed;
        do{
            choosenPenguin = rand() % nPenguins;
            penguinWithMoves = checkPeng(dimx, dimy, gameState.map, gameState.players[playerNumber].penguins[choosenPenguin]);
        }while(penguinWithMoves);

        do {
            targetX = rand() % dimx;
            targetY = rand() % dimy;
            areProperValuesUsed = checkMoveLegal(dimx,dimy, gameState.map, gameState.players[playerNumber].penguins[choosenPenguin].pengPositionX,gameState.players[playerNumber].penguins[choosenPenguin].pengPositionY, targetX, targetY);
        }while(!areProperValuesUsed);


        MovePenguin(dimx, dimy, gameState.map, nPlayers, gameState.players, choosenPenguin, playerNumber, gameState.players[playerNumber].penguins[choosenPenguin].pengPositionX,gameState.players[playerNumber].penguins[choosenPenguin].pengPositionY,targetX,targetY);

        return 0;
    }else{

        return 1;

    }


}