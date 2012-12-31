// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef BASE_CONTROLL_H_
#define BASE_CONTROLL_H_

#include <cstdio>
#include <string>

// wait for any key
void Pause();

void ClearScreen();

// get [Y/N] from user input
//  - 1=default => Yes
//  - 2         => No
bool GetYesOrNo();

// use C stdio getline safely
// return string("") when read EOF or error
std::string GetLine(FILE* fptr = stdin, const int max_length = 256);

#endif  // BASE_CONTROLL_H_
