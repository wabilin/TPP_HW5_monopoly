// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef BASE_CONTROLL_H_
#define BASE_CONTROLL_H_

// wait for any key
void Pause();

void ClearScreen();

// get [Y/N] from user input
//  - 1=default => Yes
//  - 2         => No
bool GetYesOrNo();

#endif  // BASE_CONTROLL_H_
