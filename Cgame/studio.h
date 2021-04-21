#ifndef __STUDIO_H__
#define __STUDIO_H__

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "GuessNum.h"
#include "Threechess.h"
#include "Clearmine.h"


#define User "bai"
#define Pwd  "123"
#define Delay_time 3000
 
#pragma warning(disable:4996)



void Login();
void menu();
void CountDown(int fail_cnt);

#endif
