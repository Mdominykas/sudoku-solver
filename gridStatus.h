#ifndef GRID_STATUS_H_INCLUDED
#define GRID_STATUS_H_INCLUDED

#include "cell.h"

typedef struct gridStatus
{
	int dimension;
	int size;
	int **finalGrid;
	struct cell **langeliai;
	int ***subgrid;

} gridStatus;

struct gridStatus initializeGrid(int n);

void loadGrid(int n, int source[n*n][n*n], struct gridStatus *lentele);

bool setCell(struct gridStatus *lentele, int row, int column, int value);

void fixCellPossible(struct gridStatus *lentele, int row, int column, int value);



#endif