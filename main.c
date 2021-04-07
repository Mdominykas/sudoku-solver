#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "gridCommunication.h"
#include "gridStatus.h"
#include "solve.h"

const int MAX_FILE_NAME_LENGTH = 20;
const int DIMENSION = 3;


int main()
{
	FILE *testStream = fopen("testList.txt", "r");

	char *inputFile = (char *) malloc(sizeof(char) * MAX_FILE_NAME_LENGTH);
	while(fgets(inputFile, MAX_FILE_NAME_LENGTH, testStream))
	{
		int len = strlen(inputFile);
		if(inputFile[len-1] == '\n')
			inputFile[len-1] = '\0';
		printf("%s\n", inputFile);

		int input[DIMENSION*DIMENSION][DIMENSION*DIMENSION];
		readGridFromFile(DIMENSION, input, inputFile);

		gridStatus currentGrid = initializeGrid(DIMENSION);
		loadGrid(DIMENSION, input, &currentGrid);
		startSolving();
		solve(&currentGrid);
		stopSolving();
	}

	return 0;
}