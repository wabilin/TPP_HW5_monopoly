// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#include <cstdio>
#include "game/game.h"

int main(int argc, char** argv) {
    FILE* fptr = fopen("map.dat", "r");

    Game g;
    g.InitGame(fptr);
    g.MainLoop();

    return 0;
}
