#ifndef PENGUINS_V0_1_AUTOMATIVE_H
#define PENGUINS_V0_1_AUTOMATIVE_H

int automative(GameState gameState, char *phase, int dimx, int dimy, int nPlayers, int nPenguins, int ourPlayer);
int AutoPlacement(GameState gameState, int dimx, int dimy, int nPlayer, int nPenguins);
int AutoMovement(GameState gameState, int dimx, int dimy, int nPlayers, int playerNumber, int nPenguins);
#endif
