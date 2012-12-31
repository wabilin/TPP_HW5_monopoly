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
std::string GetLine(const int max_length = 256, FILE* fptr = stdin);

#endif  // BASE_CONTROLL_H_
