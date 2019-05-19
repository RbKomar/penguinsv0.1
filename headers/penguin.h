#ifndef PENGUINS_V0_1_PENGUIN_H
#define PENGUINS_V0_1_PENGUIN_H

int placePenguin(int dimx, int dimy, int tdimX, int tdimY, IceFloe map[dimx][dimy],Player players[],int playerNumber,int penguinNumber); //changes positionx and positiony for given penguin, gives the fish from target tile to player, changes tiles status to used and hasPenguin to true
void MovePenguin(int dimx,int dimy, IceFloe map[dimx][dimy],int playerNumber,Player player[playerNumber],int penguinNumber,int playerID,int currX, int currY, int targetY, int targetX);

#endif //PENGUINS_V0_1_PENGUIN_H
