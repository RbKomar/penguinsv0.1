#include"../headers/penguin.h"

int placePenguin(int dimx, int dimy, int tdimX, int tdimY, IceFloe map[dimx][dimy],Player players[],int playerNumber,int penguinNumber){
    if(map[tdimX][tdimY].nFish && !map[tdimX][tdimY].hasPenguin)
    {
        map[tdimX][tdimY].hasPenguin = players[playerNumber].number;
        players[playerNumber].nPoints = players[playerNumber].nPoints + map[tdimX][tdimY].nFish;
        map[tdimX][tdimY].nFish = 0;
        players[playerNumber].penguins[penguinNumber].pengPositionX = tdimX;
        players[playerNumber].penguins[penguinNumber].pengPositionY = tdimY;
        return 0;
    }else
    {
        printf("\nThis tile is already occupied or has nothing to stand on\n");
        printf("Input coordinates of target tile in following way  'y x' \n");

        return 1;
    }

}

void MovePenguin(int dimx,int dimy, IceFloe map[dimx][dimy],int playerNumber,Player player[playerNumber],int penguinNumber,int playerID,int currX, int currY, int targetY, int targetX)
{
    map[currX][currY].hasPenguin=0;
    map[currX][currY].nFish=0;
    player[playerID].penguins[penguinNumber].pengPositionX=targetX;
    player[playerID].penguins[penguinNumber].pengPositionY=targetY;
    map[targetX][targetY].hasPenguin=playerID+1;
    player[playerID].nPoints= player[playerID].nPoints + map[targetX][targetY].nFish;
    map[targetX][targetY].nFish=0;
}
