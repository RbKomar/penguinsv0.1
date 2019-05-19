#include"../headers/menu.h"



bool menu(int dimx, int dimy, int playerNumber, int penguinsNumber, IceFloe map[dimx][dimy], Player players[]){
    int userinput=0, countername=0, counterboard=0;
    do{
        if(countername && !counterboard) printf("Choose one of the options: \n[1]Print players nicknames \n[2]Create the board \n[3]Begin Game \n[0]Exit Game\n");
        else if(!countername && counterboard)printf("Choose one of the options: \n[1]Assign players nicknames \n[2]Display the board \n[3]Begin Game \n[0]Exit Game\n");
        else if(counterboard && countername)printf("Choose one of the options: \n[1]Print players nicknames \n[2]Display the board \n[3]Begin Game \n[0]Exit Game\n");
        else printf("Choose one of the options: \n[1]Assign players nicknames \n[2]Create the board \n[3]Begin Game \n[0]Exit Game\n");
        scanf("%d",&userinput);
        switch(userinput){
            case 1:
                if(countername>0){
                    printingPlayerName(players, playerNumber);
                }else
                {assignPlayerName(players, playerNumber);
                    countername++;}
                break;

            case 2:
                if(counterboard){
                    displayBoard(dimx, dimy, playerNumber, map, players);
                }
                else{
                    createBoard(dimx, dimy, map);
                    counterboard++;
                }
                break;

            case 3:
                if(countername && counterboard)
                {
                    return 0;
                }
                else
                {
                    printf("Please create board and assign player names before beginning the game\n");
                    userinput=69;
                }

            case 69:
            {
                printf("Quick start\n");
                createBoard(dimx,dimy,map);
                players[0].id = malloc(8 * sizeof(char));
                strcpy(players[0].id, "Chudzik");
                players[0].number=1;
                players[1].id = malloc(7 * sizeof(char));
                strcpy(players[1].id, "Robert");
                players[1].number=2;
                players[2].id = malloc(7 * sizeof(char));
                strcpy(players[2].id, "Lukasz");
                players[2].number=3;
                snPointsForEachPlayer(playerNumber, players);
                nOfPenguinsForEachPlayer(playerNumber, penguinsNumber, players);
                return 0;
            } //For faster testing

            case 0:
                return 1;
            default:
                printf("Please choose one of options. \n");

        }
    }while(userinput!=0 && userinput!=3);
};