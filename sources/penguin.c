#include"../headers/penguin.h"

void placePenguin(int dimx, int dimy, IceFloe map[dimx][dimy], Player player, Penguin penguin)
{
    int tdimX, tdimY;
    printf("Placing phase: \n");
    printf("Input coordinates of target tile in following way  'x y' \n");
    scanf("%d %d",&tdimY,&tdimX);
    if(map[tdimX][tdimY].nFish && !map[tdimX][tdimY].hasPenguin)
    {
        map[tdimX][tdimY].hasPenguin = player.number;
        player.nPoints = player.nPoints + map[tdimX][tdimY].nFish;
        map[tdimX][tdimY].nFish = 0;
        penguin.pengPositionX = tdimX;
        penguin.pengPositionY = tdimY;
    }

    else
    {
        printf("\n This tile is already occupied or has nothing to stand on\n");
        placePenguin(dimx, dimy, map, player, penguin);
    }

}

void MovePenguin(int currX, int currY, int targetX, int targetY, Player player)
{
//check if on curr exists penguin which belongs to the current player

//check if the target isfree && has no zero value

//change the penguin location & points to the user

}
