
#define PENGUINS_V0_1_STRUCTURES_H

#define NELEMS(x)  (sizeof (x) / sizeof ((x)[0]))


typedef struct IceFloe{
    int nFish;
    int hasPenguin;
} IceFloe;

typedef struct Penguin{
    int pengPositionX;
    int pengPositionY;
}Penguin;

typedef struct Player{
    int nPoints;
    char *id;
    Penguin *penguins;
    int number;
}Player;

typedef struct GameState{
    Player *players;
    IceFloe **map;
    bool endGame;
    int phase;
}GameState;



//#endif //PENGUINS_V0_1_STRUCTURES_H
