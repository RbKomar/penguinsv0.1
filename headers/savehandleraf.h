#ifndef PENGUINS_V0_1_SAVEHANDLER_H
#define PENGUINS_V0_1_SAVEHANDLER_H


void saveGame(GameState gamestate, int dimx, int dimy, IceFloe icefloes[dimx][dimy], int PlayersNumbers);
void saveAuto(GameState gamestate, int dimx, int dimy, IceFloe icefloes[dimx][dimy], int PlayersNumbers, char *outputFilePath);
int loadGame(char *inputFilePath, char *outputFilePath);
#endif
