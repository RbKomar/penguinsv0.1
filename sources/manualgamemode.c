#include "../headers/manualgamemode.h"

void manual_play(int dimx, int dimy, int playerNumber, int penguinNumber, IceFloe map[dimx][dimy], Player players[playerNumber])
{
    for (int i = 0; i < penguinNumber; i++)
    {
        printf("\nPenguin number %d\n", i + 1);
        for (int j = 0; j < playerNumber; j++)
        {
            system("cls");
            displayBoard(dimx, dimy, playerNumber, map, players);
            printf("\nCurrent player: %s | Number of points: %d | Penguins able to move: x\n", players[j].id, players[j].nPoints);
            placePenguin(dimx, dimy, map, players[j], players[j].penguins[i]);

        }
    }

    system("cls");
    displayBoard(dimx, dimy, playerNumber, map, players);
    printf("All penguins were placed <{*}! Now its time to play! \nShort reminder: \n-To save your game write down 420\n");



}
