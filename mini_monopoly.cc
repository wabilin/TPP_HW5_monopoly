// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

// ==== ==== <TPP HW5> Mini Monopoly ==== ====
// author : N.S.Lin
// Email  : 499470256@ntnu.edu.tw
//
// ==== ==== # NOTE # ==== ====
// Compiler:
//  GCC 4.6 or later versions in Linux (suggested)
//  MinGW 4.6 or later versions in Windows
//  @see : README.md
//
// Project:
//  to build project in Windows:
//   Code::Blocks will miss the project setting (bug?)
//   in Code::Blocks click Project->Build options->Search dir..
//   add the folder where "mini_monopoly.cbp" is

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "game/game.h"
#include "base/controll.h"

// get filepath from command, or use default
FILE* GetFile(int argc, char** argv) {
    const char* filepath = "map.dat";  // default
    for (int i = 0 ; i < argc - 1 ; ++i) {
        if (strcmp(argv[i], "-f") == 0) {
            filepath = argv[i+1];
        }
    }

    FILE* fptr = fopen(filepath, "r");
    if (!fptr) {
        Die("Can not open map file. (::MapFile)");
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

