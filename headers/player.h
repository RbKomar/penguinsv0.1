#ifndef PENGUINS_V0_1_PLAYER_H
#define PENGUINS_V0_1_PLAYER_H

void printingPlayerName(Player players[], int playersNumber);
void assignPlayerName(Player players[], int playersNumber);
int snPointsForEachPlayer(int nPlayers, Player players[]); //make sure the points for each player at game start is 0
int nOfPenguinsForEachPlayer(int nPlayers, int penguinsNumber, Player players[]);
void createEmptyPlayers(Player players[], int nPlayers );


#endif //PENGUINS_V0_1_PLAYER_H
