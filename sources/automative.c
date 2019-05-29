#include "../headers/automative.h"

int automative(GameState gameState, char *phase, int dimx, int dimy, int nPlayer, int nPenguin){

    // MAMY SE WCZYTANA MAPE HERE
    //WIEC TERA TA DZIELIMY SE NA PLACEMENT PHASE i MOVEMENT PHASE
    if(strcmp(phase, "placement") == 0)
    {
        AutoPlacement(gameState);
    }else if(strcmp(phase, "manual")== 0){
        AutoMovement(Gamestate);
    }
    //GITTARA

    return 0;
}

// AUTPLACEMENT FUNKCJA XD

int AutoPlacement(GameState gameState, int dimx, int dimy, int nPlayer, int nPenguin){

    int targetX=0, targetY=0, areProperValuesUsed;
    //SRAND trzeba targetX i targetY i
    do {
        //TODO: WE TU SRANDA WSTAW W JAKIMS ZAKRESIE DIMX DIMY DLA TARGETX I TARGETY
        areProperValuesUsed = placePenguin(dimx, dimy, targetX, targetY, gameState.map, gameState.players, nPlayer, nPenguin);
    }while(areProperValuesUsed);

    placePenguin(dimx, dimy, targetX, targetY, gameState.map , gameState.players, nPlayer, nPenguin);
    return 0;
}

//AUTOREGGRESION W MOZGU SE MAM
// A I AUTOMOVEMENT FUNKCJA TEZ TU JEST XD
int AutoMovement(){

}