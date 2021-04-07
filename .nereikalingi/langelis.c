///daugmaz visas esantis kodas yra geras ir be komentaru, bet jei uzkomentuota
///tai reiskia, kad jau perkelta i kitus filus


///kartu tik deterministiskai skaiciuoja viska

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// struct grid initializeGrid(int n);

// void addInstruction(struct grid *lentele, int row, int column);

// void completeInstruction(struct grid *lentele);

// void fixCellPossible(struct grid *lentele, int row, int column, int value);

// bool setCell(struct grid *lentele, int row, int column, int value);

// void loadGrid(int n, int source[n*n][n*n], struct grid *lentele);

// void readGridFromFile(int n, int result[n*n][n*n], char fileName[]);

// void writeGridToFile(struct grid *lentele, char fileName[]);

// struct instruction
// {
// 	int row, column, value;
// };

struct instruction instructionSequence[100];
int numberOfInstructions = 0;
int currentInstruction = 0;

// struct cell
// {
// 	int subgridRow;
// 	int subgridColumn;
// 	int laisvu;
// 	int dimensija;
// 	int dydis;
// 	bool *possible; 
// 	int row, column;
// };

// struct cell initializeCell(int n, int rowNum, int columnNum)
// {
// 	struct cell naujas;
// 	naujas.dimensija = n;
// 	naujas.dydis = n*n;
// 	naujas.row = rowNum;
// 	naujas.column = columnNum;
// 	naujas.laisvu = n*n;
// 	naujas.possible = (bool*) malloc(sizeof(bool)*(naujas.dydis+1));
// 	naujas.subgridRow = rowNum / n;
// 	naujas.subgridColumn =  columnNum / n;
// 	for(int i=0; i<=naujas.dydis; i++)
// 		naujas.possible[i] = true ;
// 	naujas.possible[0] = true;
// 	return naujas;
// }

// struct grid
// {
// 	int dimensija;
// 	int dydis; ///dimensija kvadratu arba kvadrato dydis
// 	struct cell **langeliai;
// 	int ***subgrid;
// 	int **finalGrid;
// };

// struct grid initializeGrid(int n)
// {
// 	struct grid naujas;
// 	naujas.dimensija = n;
// 	naujas.dydis = n*n;
// 	naujas.langeliai = (struct cell**) malloc(sizeof(struct cell*)*naujas.dydis);
// 	for(int i=0; i<naujas.dydis; i++)
// 		naujas.langeliai[i] = (struct cell*) malloc(sizeof(struct cell)*naujas.dydis);

// 	for(int i=0; i<naujas.dydis; i++)
// 	{
// 		for(int j=0; j<naujas.dydis; j++)
// 			naujas.langeliai[i][j] = initializeCell(n, i, j);
// 	}

// 	naujas.finalGrid = (int**) malloc(sizeof(int*)*naujas.dydis);

// 	for(int i=0; i<naujas.dydis; i++)
// 	{
// 		naujas.finalGrid[i] = (int*) malloc(sizeof(int)*naujas.dydis);
// 	}
// 	for(int i=0; i<naujas.dydis; i++)
// 	{
// 		for(int j=0; j<naujas.dydis; j++)
// 			naujas.finalGrid[i][j] = 0;
// 	}

// 	naujas.subgrid = (int***) malloc(sizeof(int**)*naujas.dimensija);

// 	for(int i=0; i<naujas.dimensija; i++)
// 	{
// 		naujas.subgrid[i] = (int**) malloc(sizeof(int*)*naujas.dimensija);
// 		for(int j=0; j<naujas.dimensija; j++)
// 			naujas.subgrid[i][j] = (int*) malloc(sizeof(int)*(naujas.dydis + 1));
// 		for(int j=0; j<naujas.dimensija; j++)
// 		{
// 			for(int k=0; k<=naujas.dydis; k++)
// 			{
// 				naujas.subgrid[i][j][k] = naujas.dydis;
// 			}
// 		}
// 	}


// 	return naujas;
// }

// void addInstruction(struct grid *lentele, int row, int column)
// {
// 	int val = 0;
// 	for(int i=1; i<=lentele->dydis; ++i)
// 	{
// 		if(lentele->langeliai[row][column].possible[i])
// 			val = i;
// 	}
// 	instructionSequence[numberOfInstructions] = (struct instruction){.row = row, .column = column, .value = val};
// 	numberOfInstructions++;
// }

// void addInstructionWithValue(struct grid *lentele, int row, int column, int value)
// {
// 	instructionSequence[numberOfInstructions] = (struct instruction){.row = row, .column = column, .value = value};
// 	numberOfInstructions++;
// }

// void completeInstruction(struct grid *lentele)
// {
// 	printf("%d %d %d\n", instructionSequence[currentInstruction].row, instructionSequence[currentInstruction].column, \
// 				instructionSequence[currentInstruction].value);

// 	setCell(lentele, instructionSequence[currentInstruction].row, instructionSequence[currentInstruction].column, \
// 				instructionSequence[currentInstruction].value);
// 	currentInstruction++;
// }

// void fixCellPossible(struct grid *lentele, int row, int column, int value)
// {
// 	if(lentele->langeliai[row][column].possible[value])
// 	{
// 		lentele->langeliai[row][column].possible[value] = false;
// 		lentele->langeliai[row][column].laisvu--;
// 		if(lentele->langeliai[row][column].laisvu == 1)
// 			addInstruction(lentele, row, column);
// 		int currentSubgridRow = lentele->langeliai[row][column].subgridRow;
// 		int currentSubgridColumn = lentele->langeliai[row][column].subgridColumn;
// 		lentele->subgrid[currentSubgridRow][currentSubgridColumn][value]--;
// 		if(lentele->subgrid[currentSubgridRow][currentSubgridColumn][value] == 1)
// 		{
// 			addInstructionOfValueInSubgrid(lentele, currentSubgridRow, currentSubgridColumn, value);
// 		}
// 	}
// }

// bool setCell(struct grid *lentele, int row, int column, int value)
// {
// 	if(lentele->langeliai[row][column].possible[value] == false)
// 		return false;
// 	for(int i=0; i<lentele->dydis; i++)
// 	{
// 		fixCellPossible(lentele, row, i, value);
// 		fixCellPossible(lentele, i, column, value);
// 	}

// 	int firstRow = row - (row%lentele->dimensija), lastRow = firstRow + lentele->dimensija - 1;
// 	int firstColumn = column - (column%lentele->dimensija), lastColumn = firstColumn + lentele->dimensija - 1;
// 	for(int i=firstRow; i<=lastRow; i++)
// 	{
// 		for(int j=firstColumn; j<=lastColumn; j++)
// 		{
// 			fixCellPossible(lentele, i, j, value);
// 		}
// 	}

// 	for(int i=1; i<=lentele->dydis; i++)
// 		lentele->langeliai[row][column].possible[i] = false;
// 	lentele->finalGrid[row][column] = value;
// 	return true;
// }

// void addInstructionOfValueInSubgrid(struct grid *lentele, int row, int column, int value)
// {
// 	int firstRow = row * lentele->dimensija;
// 	int lastRow = firstRow + lentele->dimensija - 1;
// 	int firstColumn = column * lentele->dimensija;
// 	int lastColumn = firstColumn + lentele->dimensija - 1;
// 	for(int i=firstRow; i<=lastRow; i++)
// 	{
// 		for(int j=firstColumn; j<=lastColumn; j++)
// 		{
// 			if(lentele->langeliai[i][j].possible[value])
// 			{
// 				addInstructionWithValue(lentele, i, j, value);
// 				return;
// 			}
// 		}
// 	}
// }

// void loadGrid(int n, int source[n*n][n*n], struct grid *lentele)
// {
// 	for(int i=0; i<n*n; i++)
// 	{
// 		for(int j=0; j<n*n; j++)
// 		{
// 			if(source[i][j] != 0)
// 				setCell(lentele, i, j, source[i][j]);
// 		}
// 	}
// }

// void readGridFromFile(int n, int result[n*n][n*n], char fileName[])
// {
// 	FILE *fptr = fopen(fileName, "r");
// 	if(fptr==NULL)
// 	{
// 		printf("could not open input file : %s\n", fileName);
// 		return;
// 	}

// 	for(int i=0; i<n*n; i++)
// 	{
// 		for(int j=0; j<n*n; j++)
// 			fscanf(fptr, "%d", &result[i][j]);
// 	}
// 	fclose(fptr);
// }


// void writeGridToFile(struct grid *lentele, char fileName[])
// {
// 	FILE *fptr = fopen(fileName, "w");


// 	for(int i=0; i<(*lentele).dydis; i++)
// 	{
// 		for(int j=0; j<(*lentele).dydis; j++)
// 			fprintf(fptr, "%d ", lentele->finalGrid[i][j]);
// 		fprintf(fptr, "\n");
// 	}
// 	fclose(fptr);
// }

int main()
{
	int n = 3;
	struct grid lentele;
	lentele = initializeGrid(n);

	int startingGrid[n*n][n*n];
	char inputFileName[] = "valinsko2.txt";
	readGridFromFile(n, startingGrid, inputFileName);


	for(int i=0; i<n*n; i++)
	{
		for(int j=0; j<n*n; j++)
			printf("%d ", startingGrid[i][j]);
		printf("\n");
	}

	loadGrid(n, startingGrid, &lentele);

	while(currentInstruction<numberOfInstructions)
	{
		printf("vykdau kazka\n");
		completeInstruction(&lentele);
	}


	char outputFileName[] = "valinsko2_output.txt";
	writeGridToFile(&lentele, outputFileName);

	printf("%d\n", lentele.finalGrid[8][2]);
	for(int i=0; i<=9; i++)
		printf("%d ", lentele.langeliai[8][2].possible[i]);
	return 0;
}