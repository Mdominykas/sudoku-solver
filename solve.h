#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED

#include<stdbool.h>

#include "gridStatus.h"

extern const bool CHECK_ALL_CASES;
extern const double TIME_TO_SOLVE;

void startSolving();

int solve(gridStatus *currentGrid);

void stopSolving();

#endif