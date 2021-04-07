#ifndef GRID_COMMUNICATION_H_INCLUDED
#define GRID_COMMUNICATION_H_INCLUDED

#include "gridStatus.h"
#include "cell.h"

void readGridFromFile(int n, int result[n*n][n*n], char fileName[]);

void writeGridToFile(struct gridStatus *lentele, char fileName[]);

bool testAnswer(struct gridStatus *ans, char answerFileName[]);


#endif