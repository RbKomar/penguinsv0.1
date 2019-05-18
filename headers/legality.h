#ifndef PENGUINS_V0_1_LEGALITY_H
#define PENGUINS_V0_1_LEGALITY_H

#define MAX_PLAYERS 10
#define MAX_PENGUINS 6
#define MAX_DIMENSIONS 15


int checkNumberOfPlayers(int i);
int checkDimensions(int a, int b);
int checkNumberOfPenguins(int a);
int checkMoveLegal(int beginX,int beginY,int targetX,int targetY,GameState gameState);//checks if chosen move is possible
int checkGameEnd(GameState gameState,int playerCount,int pengCount);//checks if any players have penguins that can move
int checkPeng(int dimx,int dimy, IceFloe map[dimx][dimy], Penguin penguin);//checks if penguin can move
int checkPlayerMoves(int dimx,int dimy, int nPenguins, IceFloe map[dimx][dimy], Penguin penguin);


#endif //PENGUINS_V0_1_LEGALITY_H
