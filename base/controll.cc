// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "base/controll.h"
  #ifdef __unix__
    #include <termios.h>
    #include <unistd.h>
  #endif
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using std::string;

#ifdef __unix__
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
    printf("Press any key to continue...");
    unix_getch();
  #else
    #ifdef _WIN32
    system("pause");
    #else
    printf("Press Enter key to continue...");
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

bool GetYesOrNo() {
    static const size_t kMaxMsgLength = 128;
    char msg[kMaxMsgLength] = {'\0'};
    fgets(msg, kMaxMsgLength, stdin);

    return msg[0] != '2';
}

string GetLine(FILE* fptr, const int max_length) {
    char line[max_length], *s_ptr;
    s_ptr = fgets(line, max_length, fptr);
    if (!s_ptr) {
        return string("");
    }

    // replace '\n' at the end of string
    line[strlen(line) - 1] = '\0';

    return string(line);
}

void Die(const char* reason) {
    fprintf(stderr, "Error : %s\n", reason);
    exit(EXIT_FAILURE);
}
