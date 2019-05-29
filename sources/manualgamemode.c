#include "../headers/manualgamemode.h"

void manual_play(GameState gameState, int dimx, int dimy, int playerNumber, int penguinNumber, IceFloe map[dimx][dimy], Player players[playerNumber])
{
    int chosenX,chosenY;
    int targetX, targetY;
    int isPenguin=0, penguinID=-1;
    int areProperValuesUsed;

    for (int i = 0; i < penguinNumber; i++)
    {
        for (int j = 0; j < playerNumber; j++)
        {
            displayBoard(dimx, dimy, playerNumber, map, players);
            printf("\nCurrent player: %s | Number of points: %d | Penguins able to move: x\n", players[j].id, players[j].nPoints);
            printf("Placing phase: \n");
            printf("Input coordinates of target tile in following way  'x y' \n");
            do {
                scanf("%d %d",&targetY,&targetX);
                areProperValuesUsed = placePenguin(dimx, dimy, targetX, targetY, map, players, j, i);
            }while(areProperValuesUsed);
            saveGame(gameState, dimx, dimy, map, playerNumber);
        }
    }

    displayBoard(dimx, dimy, playerNumber, map, players);
    printf("All penguins were placed <(•ᴗ•<)! Now its time to play! \nShort reminder: \n-After every move your game is saved\n");
    do
    {
        for(int i=0;i<playerNumber;i++)
        {
            if(checkPlayerMoves(dimx,dimy,penguinNumber,map,players[i]))
            {
                displayBoard(dimx, dimy, playerNumber, map, players);
                printf("\nCurrent player: %s | Number of points: %d | Penguins able to move: x\n", players[i].id, players[i].nPoints);
                do
                {
                    printf("List of player %s penguins\n",players[i].id);
                    for(int j=0;j<penguinNumber;j++)
                    {
                        printf("%d %d\n", players[i].penguins[j].pengPositionY, players[i].penguins[j].pengPositionX);
                    }
                    printf("Player %s choose a tile with your penguin (format x,y)\n",players[i].id);
                    scanf("%d %d",&chosenY,&chosenX);
                    for(int j=0;j<penguinNumber;j++)
                    {
                        if(players[i].penguins[j].pengPositionX==chosenX && players[i].penguins[j].pengPositionY==chosenY)
                        {
                            if(checkPeng(dimx,dimy,map,players[i].penguins[j]))
                            {
                                isPenguin=1;
                                penguinID=j; 
                            }
                        }
                    }
                    if(!isPenguin)
                    {
                        printf("Player %s has no penguin at chosen coordinates or chosen penguin cannot move\n",players[i].id);
                    }
                } while (!isPenguin);
                
                do
                {
                    printf("Choose target tile (format x,y)\n");
                    scanf("%d %d",&targetY, &targetX);
                    if(!checkMoveLegal(dimx,dimy,map,chosenX,chosenY,targetX,targetY))
                    {
                        printf("Illegal move,try again\n");
                    }
                } while (!checkMoveLegal(dimx,dimy,map,chosenX,chosenY,targetX,targetY));
                MovePenguin(dimx,dimy,map,playerNumber,players,penguinID,i,chosenX,chosenY,targetX,targetY);
                saveGame(gameState, dimx, dimy, map, playerNumber);

            }
            else
            {
                printf("Player %s has no moves left",players[i].id);
            }
            
        }
//        printf("(>•ᴗ•<)\n");
//        printf("(>•ᴗ•)> End Turn\n");
//        printf("(>•ᴗ•<) End Turn\n");
//        printf("<(•ᴗ•<) End turn\n");
//        printf("(>•ᴗ•<)\n");
    } while (checkGameEnd(dimx,dimy,penguinNumber,playerNumber,map,players));
    int maxPoints=0;
    int winner=0;
    for(int i=0;i<playerNumber;i++)
    {
        if(players[i].nPoints>maxPoints)
        {
            maxPoints=players[i].nPoints;
            winner=i;
        }
    }
    printf("\n(>•ᴗ•)> E N D  G A M E <(•ᴗ•<)\n");
    printf("%s\n",toupper(players[winner].id));
    printf("(>•ᴗ•)> Y O U  A R E  W I N N E R <(•ᴗ•<)\n");
    printf("You had %d points!\n G O O D  J O B\n", players[winner].nPoints);
}