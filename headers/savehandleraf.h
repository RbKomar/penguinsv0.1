#ifndef PENGUINS_V0_1_SAVEHANDLER_H
#define PENGUINS_V0_1_SAVEHANDLER_H


void saveGame(GameState gamestate, int dimx, int dimy, IceFloe icefloes[dimx][dimy], int PlayersNumbers);
int loadGame( char *inputFilePath, char *outputFilePath);
#endif
