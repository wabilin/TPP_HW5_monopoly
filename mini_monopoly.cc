// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#include <cstdio>
#include <cstring>
#include "game/game.h"

// get filepath from command, or use default
FILE* GetFile(int argc, char** argv) {
    const char* filepath = "map.dat"; // default
    for (int i = 0 ; i < argc - 1 ; ++i) {
        if(strcmp(argv[i], "-f") == 0) {
            filepath = argv[i+1];
        }
    }

    FILE* fptr = fopen(filepath, "r");
    if (!fptr) {
        fprintf(stderr, "Error at MapFile: can not open file: %s\n", filepath);
        exit(EXIT_FAILURE);
    }
    return fptr;
}

int main(int argc, char** argv) {
    FILE* map_file = GetFile(argc, argv);

    Game monopoly;
    monopoly.InitGame(map_file);
    monopoly.MainLoop();

    return EXIT_SUCCESS;
}

