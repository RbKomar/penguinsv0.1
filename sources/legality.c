#include"../headers/legality.h"



int checkNumberOfPlayers(int i)
{   if(i>MAX_PLAYERS){printf("Number of players is too big"); return 0;}
    else if(i<1){printf("Number of players is too small"); return 0;}
    else
    {
        return 1;
    }
}

int checkDimensions(int a, int b)
{ if( (a<0 || b<0) || (a>MAX_DIMENSIONS || b>MAX_DIMENSIONS ) ){
        printf("Dimensions are wrong \nUse dimensions in range 0-%d", MAX_DIMENSIONS);
        return 0;
    }else{
        return 1;
    }
}


int checkNumberOfPenguins(int a){
    if(a<0 && a>MAX_PENGUINS){printf("Wrong number of penguins!");
        return 0;
    }
    else
    {
        return 1;
    }
}

int checkInputParameters(int nPlayers, int dimx, int dimy, int nPenguins){
    if(checkNumberOfPenguins(nPlayers) && checkDimensions(dimx, dimy) &&
       checkNumberOfPlayers(nPenguins))return 1;
    else return 0;
}

int checkMoveLegal(int beginX,int beginY,int targetX,int targetY,GameState gameState)
{
    if(gameState.map[targetX][targetY].nFish!=0)
    {
        if(beginX==targetX || beginY==targetY){
            if(beginX!=targetX){
                if(targetX-beginX>0){
                    for(int i=1;i<targetX-beginX;i++)
                    {
                        if(gameState.map[beginX+i][beginY].nFish==0)return 0;
                    }
                    return 1;
                }
                else if(targetX-beginX<0)
                {
                    for(int i=-1;i>targetX-beginX;i--)
                    {
                        if(gameState.map[beginX+i][beginY].nFish==0)return 0;
                    }
                    return 1;
                }
            }
            else if(beginY!=targetY)
            {
                if(targetY-beginY>0)
                {
                    for(int i=1;i<targetY-beginY;i++)
                    {
                        if(gameState.map[beginX][beginY+i].nFish==0)return 0;
                    }
                    return 1;
                }
                else if(targetY-beginY<0) {
                    for (int i = -1; i > targetY - beginY; i--) {
                        if (gameState.map[beginX][beginY + i].nFish == 0)return 0;
                    }
                    return 1;
                }
            }
            else return 0;
        }else return 0;
    }else return 0;
}
//This checks the legality of the move: first it checks if the target tile can be stepped on, then it checks if its in the same row or column as previous tile, then it checks if the path to the target tile doesnt have any gaps or penguins on it

int checkPeng(int dimx,int dimy, IceFloe map[dimx][dimy], Penguin penguin)
{
    int canMoveR=1,canMoveL=1,canMoveU=1,canMoveD=1;
    if(penguin.pengPositionX==dimx)
    {
        canMoveR=0;
    }
    if(penguin.pengPositionX==0)
    {
        canMoveL=0;
    }
    if(penguin.pengPositionY==dimy)
    {
        canMoveD=0;
    }
    if(penguin.pengPositionY==0)
    {
        canMoveU=0;
    }
    if(map[penguin.pengPositionX+1][penguin.pengPositionY].nFish==0 && canMoveR==1)
    {
        canMoveR=0;
    }
    if(map[penguin.pengPositionX-1][penguin.pengPositionY].nFish==0 && canMoveL==1)
    {
        canMoveL=0;
    }
    if(map[penguin.pengPositionX][penguin.pengPositionY+1].nFish==0 && canMoveU==1)
    {
        canMoveU=0;
    }
    if(map[penguin.pengPositionX][penguin.pengPositionY-1].nFish==0 && canMoveD==1)
    {
        canMoveD=0;
    }
    if(canMoveR==0 && canMoveL==0 && canMoveU==0 && canMoveD==0)
    {
        printf("This penguin can't move anymore\n");
        return 0;
    }
    else
    {
        return 1;
    }
}//This checks if a specific penguin has an adjecent empty tile

/*int checkGameEnd(GameState gameState,int playerCount,int pengCount)
{
    for(int i=0;i<playerCount;i++)
    {
        if(checkPlayerMoves(gameState.players[i],pengCount,gameState.map))
        {
            return 1;
        }
    }
    return 0;
}*/

int checkPlayerMoves(int dimx,int dimy, int nPenguins, IceFloe map[dimx][dimy], Penguin penguin)
{
    for(int i=0;i < nPenguins;i++)
    {
        if(checkPeng(dimx, dimy, map, penguin))
        {
            return 1;
        }
    }
    return 0;
}
