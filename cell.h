#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <stdbool.h>

typedef struct cell
{
	int subgridRow;
	int subgridColumn;
	int laisvu;
	int dimensija;
	int dydis;
	bool *possible; 
	int row, column;
} cell;

cell initializeCell(int n, int rowNum, int columnNum);


#endif