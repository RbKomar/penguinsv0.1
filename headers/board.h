#ifndef PENGUINS_V0_1_BOARD_H
#define PENGUINS_V0_1_BOARD_H


void createBoard(int dimx, int dimy, IceFloe map[dimx][dimy]);
void displayBoard(int dimx, int dimy, int nPlayers, IceFloe map[dimx][dimy], Player players[nPlayers]); //prints number of fish on each floe


#endif //PENGUINS_V0_1_BOARD_H
