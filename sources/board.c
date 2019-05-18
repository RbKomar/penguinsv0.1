#include"../headers/board.h"


void createBoard(int dimx, int dimy, IceFloe map[dimx][dimy]){
    for(int i=0; i<dimy; i++){
        for(int j=0; j<dimx; j++)
        {
            map[i][j].nFish = (rand() % 3 ) + 1;
            map[i][j].hasPenguin = 0;
        }
    }

}

void displayBoard(int dimx, int dimy, int nPlayers, IceFloe map[dimx][dimy], Player players[nPlayers]){
    printf(" ");
    for(int i=0;i<dimy;i++)
    {
        printf("  %d  ",i);
    }
    for(int i=0; i<dimy; i++){
        printf("\n\n%d",i);
        for(int j=0; j<dimx; j++)
        {
            if(map[i][j].hasPenguin)
            {
                printf("[ %c%c ]", toupper(players[map[i][j].hasPenguin-1].id[0]), toupper(players[map[i][j].hasPenguin-1].id[1]));
            }
            else
            {
                printf("[ %d ]", map[i][j].nFish);
            }
        }
        printf("\n");
    }

}
//Board creation fixed - previously all rows were the same, now they are actually randomly generated
