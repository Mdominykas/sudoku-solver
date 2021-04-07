#include <stdio.h>
#include <stdbool.h>
#include "gridCommunication.h"
#include "gridStatus.h"
#include "cell.h"

void readGridFromFile(int n, int result[n*n][n*n], char fileName[])
{
	FILE *fptr = fopen(fileName, "r");
	if(fptr==NULL)
	{
		printf("could not open input file : %s\n", fileName);
		return;
	}

	for(int i=0; i<n*n; i++)
	{
		for(int j=0; j<n*n; j++)
			fscanf(fptr, "%d", &result[i][j]);
	}
	fclose(fptr);
}


void writeGridToFile(struct gridStatus *lentele, char fileName[])
{
	FILE *fptr = fopen(fileName, "w");


	for(int i=0; i<(*lentele).size; i++)
	{
		for(int j=0; j<(*lentele).size; j++)
			fprintf(fptr, "%d ", lentele->finalGrid[i][j]);
		fprintf(fptr, "\n");
	}
	fclose(fptr);
}

bool testAnswer(struct gridStatus *ans, char answerFileName[])
{
	int answerGrid[(*ans).size][(*ans).size];
	readGridFromFile((*ans).dimension, answerGrid, answerFileName);

	for(int i=0; i<(*ans).size; i++)
	{
		for(int j=0; j<(*ans).size; j++)
		{
			if((*ans).finalGrid[i][j] != answerGrid[i][j])
				return false;
		}
	}

	return true;
}