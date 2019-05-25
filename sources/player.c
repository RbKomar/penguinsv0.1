#include "../headers/player.h"


int snPointsForEachPlayer(int nPlayers,Player players[])
{
    for(int i=0; i<nPlayers; i++){
        players[i].nPoints = 0;
    }
}

int nOfPenguinsForEachPlayer(int nPlayers, int penguinsNumber, Player players[])
{
    for(int i=0; i<nPlayers; i++){
        players[i].penguins = (Penguin *) malloc(sizeof(Penguin) * penguinsNumber);
    }
}


void printingPlayerName(Player players[], int playersNumber){
    for(int i=0;i<playersNumber;i++)
    {
        printf("%s \n", players[i].id);
    }
}


void assignPlayerName(Player players[], int playersNumber){
    char tempname[300];
    for (int i=0;i<playersNumber;i++)
    {
        printf("Input player %d name: ",i+1);
        scanf("%s",&tempname);
        players[i].id = malloc((strlen(tempname) + 1) * sizeof(char));
        strcpy(players[i].id, tempname);
        players[i].number=i+1;
        printf("%s\n",players[i].id);
    } //Name input
}

void createEmptyPlayers(Player players[], int nPlayers ){
    char tempname[50]= " xd";
    for (int i=0;i<nPlayers;i++)
    {
        players[i].id = malloc((strlen(tempname) + 1) * sizeof(char));
        strcpy(players[i].id, tempname);
        players[i].nPoints=0;
        players[i].number=0;
        players[i].penguins = NULL;
    }

}


