// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "base/controll.h"
#include <cstdio>
#include <cstdlib>

#ifdef __unix__
  #include <termios.h>
  #include <unistd.h>
int unix_getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

void Pause() {
#ifdef __unix__
    printf("Press Enter key to continue...");
    unix_getch();
  #else
    #ifdef _WIN32
    system("pause");
    #else
    printf("Press \"Enter\" to continue...");
    scanf("%*c");
    #endif
#endif
}

void ClearScreen() {
#ifdef __unix__
    system("clear");
  #else
    #ifdef _WIN32
    system("cls");
    #else
    static const int kHeight = 24;
    for (int i = 0 ; i < kHeight ; ++i) {
        putchar('\n');
    }
    #endif
#endif
}
