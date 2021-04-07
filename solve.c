#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "gridStatus.h"
#include "solve.h"

clock_t start, currentTime, end;

void startSolving()
{
	start = clock();
}

void stopSolving()
{
	printf("time");
}

int solve(gridStatus *currentGrid)
{
	currentTime = clock();

	double elapsedTime = ((double) (currentTime - start)) / CLOCKS_PER_SEC;
	if(elapsedTime > TIME_TO_SOLVE)
		return -1;

	if(CHECK_ALL_CASES)
		printf("veikia\n");
	return 0;
}