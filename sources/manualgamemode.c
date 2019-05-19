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
            printf("Input coordinates of target tile in following way  'y x' \n");
            do {
                scanf("%d %d",&targetX,&targetY);
                areProperValuesUsed = placePenguin(dimx, dimy, targetX, targetY, map, players, j, i);
            }while(areProperValuesUsed);
            saveGame(gameState, dimx, dimy, map, playerNumber);
        }
    }

    system("cls"); //Commented out cause Linux xD, conio.h mi nie chcialo dzialac, znajdzmy cos na linuxa tez
    displayBoard(dimx, dimy, playerNumber, map, players);
   // const char penguinEmoji[5] = {0xF0,0x9F,0x90,0xA7,'\0'}; Look I tried something here and it didnt work xd - M
    printf("All penguins were placed <(•ᴗ•<)! Now its time to play! \nShort reminder: \n-After every move your game is saved\n");

    do
    {
        for(int i=0;i<playerNumber;i++)
        {
            if(checkPlayerMoves(dimx,dimy,penguinNumber,map,players[i]))
            {
                displayBoard(dimx, dimy, playerNumber, map, players);
                printf("\nCurrent player: %s | Number of points: %d | Penguins able to move: x\n", players[i].id, players[i].nPoints);
                printf("Moving phase: \n");
                do
                {
                    printf("Player %s choose a tile with your penguin (format y x)\n",players[i].id);
                    scanf("%d %d",&chosenX, &chosenY);

                    for(int j=0;j<penguinNumber;j++)
                    {
                        if(players[i].penguins[j].pengPositionX==chosenX && players[i].penguins[j].pengPositionY==chosenY && checkPeng(dimx,dimy,map,players[i].penguins[j])){

                                isPenguin=1;
                                penguinID=j; 

                        }
                    }
                    if(!isPenguin)
                    {
                        printf("Player %s has no penguin at chosen coordinates or chosen penguin cannot move\n",players[i].id);
                    }
                } while (!isPenguin);
                
                do
                {
                    printf("Choose target tile (format y x)\n");
                    scanf("%d %d",&targetX, &targetY);
                    if(!checkMoveLegal(dimx,dimy,map,chosenX,chosenY,targetX,targetY))
                    {
                        printf("Illegal move,try again\n");
                    }

                } while (!checkMoveLegal(dimx,dimy,map,chosenX,chosenY,targetX,targetY));
                MovePenguin(dimx, dimy, map, playerNumber, players, penguinID, i, chosenX, chosenY, targetX, targetY);
            }else
            {
                printf("Player %s has no moves left",players[i].id);
            }
        }
    }while (checkGameEnd(dimx,dimy,penguinNumber,playerNumber,map,players));
    printf("hura EndGame hura\n");
    

}