#ifndef PENGUINS_V0_1_LEGALITY_H
#define PENGUINS_V0_1_LEGALITY_H

#define MAX_PLAYERS 10
#define MAX_PENGUINS 6
#define MAX_DIMENSIONS 15


int checkNumberOfPlayers(int i);
int checkDimensions(int a, int b);
int checkNumberOfPenguins(int a);
int checkMoveLegal(int dimx,int dimy,IceFloe map[dimx][dimy],int beginX,int beginY,int targetX,int targetY);//checks if chosen move is possible
int checkGameEnd(int dimx, int dimy,int nPenguin,int nPlayers,IceFloe map[dimx][dimy],Player players[]);//checks if any players have penguins that can move
int checkPeng(int dimx,int dimy, IceFloe map[dimx][dimy], Penguin penguin);//checks if penguin can move
int checkPlayerMoves(int dimx,int dimy, int nPenguins, IceFloe map[dimx][dimy], Player player);


#endif //PENGUINS_V0_1_LEGALITY_H
