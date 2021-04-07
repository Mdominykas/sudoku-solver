#include <stdbool.h>
#include <stdlib.h>

#include "cell.h"

cell initializeCell(int n, int rowNum, int columnNum)
{
	cell naujas;
	naujas.dimensija = n;
	naujas.dydis = n*n;
	naujas.row = rowNum;
	naujas.column = columnNum;
	naujas.laisvu = n*n;
	naujas.possible = (bool*) malloc(sizeof(bool)*(naujas.dydis+1));
	naujas.subgridRow = rowNum / n;
	naujas.subgridColumn =  columnNum / n;
	for(int i=0; i<=naujas.dydis; i++)
		naujas.possible[i] = true ;
	naujas.possible[0] = true;
	return naujas;
}