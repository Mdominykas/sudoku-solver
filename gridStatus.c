#include <stdbool.h>
#include <stdlib.h>
#include "gridStatus.h"
#include "cell.h"


struct gridStatus initializeGrid(int n)
{
	struct gridStatus naujas;
	naujas.dimension = n;
	naujas.size = n*n;
	naujas.langeliai = (cell**) malloc(sizeof(cell*)*naujas.size);
	for(int i=0; i<naujas.size; i++)
		naujas.langeliai[i] = (cell*) malloc(sizeof(cell)*naujas.size);

	for(int i=0; i<naujas.size; i++)
	{
		for(int j=0; j<naujas.size; j++)
			naujas.langeliai[i][j] = initializeCell(n, i, j);
	}

	naujas.finalGrid = (int**) malloc(sizeof(int*)*naujas.size);

	for(int i=0; i<naujas.size; i++)
	{
		naujas.finalGrid[i] = (int*) malloc(sizeof(int)*naujas.size);
	}
	for(int i=0; i<naujas.size; i++)
	{
		for(int j=0; j<naujas.size; j++)
			naujas.finalGrid[i][j] = 0;
	}

	naujas.subgrid = (int***) malloc(sizeof(int**)*naujas.dimension);

	for(int i=0; i<naujas.dimension; i++)
	{
		naujas.subgrid[i] = (int**) malloc(sizeof(int*)*naujas.dimension);
		for(int j=0; j<naujas.dimension; j++)
			naujas.subgrid[i][j] = (int*) malloc(sizeof(int)*(naujas.size + 1));
		for(int j=0; j<naujas.dimension; j++)
		{
			for(int k=0; k<=naujas.size; k++)
			{
				naujas.subgrid[i][j][k] = naujas.size;
			}
		}
	}

	return naujas;
}


void loadGrid(int n, int source[n*n][n*n], struct gridStatus *lentele)
{
	for(int i=0; i<n*n; i++)
	{
		for(int j=0; j<n*n; j++)
		{
			if(source[i][j] != 0)
				setCell(lentele, i, j, source[i][j]);
		}
	}
}

bool setCell(struct gridStatus *lentele, int row, int column, int value)
{
	if(lentele->langeliai[row][column].possible[value] == false)
		return false;
	for(int i=0; i<lentele->size; i++)
	{
		fixCellPossible(lentele, row, i, value);
		fixCellPossible(lentele, i, column, value);
	}

	int firstRow = row - (row%lentele->dimension), lastRow = firstRow + lentele->dimension - 1;
	int firstColumn = column - (column%lentele->dimension), lastColumn = firstColumn + lentele->dimension - 1;
	for(int i=firstRow; i<=lastRow; i++)
	{
		for(int j=firstColumn; j<=lastColumn; j++)
		{
			fixCellPossible(lentele, i, j, value);
		}
	}

	for(int i=1; i<=lentele->size; i++)
		lentele->langeliai[row][column].possible[i] = false;
	lentele->finalGrid[row][column] = value;
	return true;
}

void fixCellPossible(struct gridStatus *lentele, int row, int column, int value)
{
	if(lentele->langeliai[row][column].possible[value])
	{
		lentele->langeliai[row][column].possible[value] = false;
		lentele->langeliai[row][column].laisvu--;
		int currentSubgridRow = lentele->langeliai[row][column].subgridRow;
		int currentSubgridColumn = lentele->langeliai[row][column].subgridColumn;
		lentele->subgrid[currentSubgridRow][currentSubgridColumn][value]--;
	}
}
