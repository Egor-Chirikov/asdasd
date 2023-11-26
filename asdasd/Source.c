#define _CRT_SECURE_NO_WARNINGS


#include <stdlib.h>
#include <stdio.h>

struct Cell
{
	int vol;
	struct Cell* next;
};
typedef struct Cell Cell;

Cell* addStart(Cell* head, int newVol) {
	Cell* newCell = NULL;  

	if ((newCell = (Cell*)(malloc(sizeof(Cell)))) == NULL) {
		return NULL;
	}

	newCell->vol = newVol;
	newCell->next = NULL;

	if (head == NULL) {
		return newCell;
	}

	newCell->next = head;
	return newCell;
}

int main() {
	Cell* pFrstCell = NULL;
	Cell* begynok = NULL;
	Cell* rememberMe = NULL;
	int newVol;

	while (scanf("%d", &newVol))
	{
		pFrstCell = addStart(pFrstCell, newVol);
	}

	if (pFrstCell == NULL) {
		printf("NULL");
		return 0;
	}

	begynok = pFrstCell;
	while (begynok != NULL)
	{
		printf("%d ", begynok->vol);
		begynok = begynok->next;
	}

	begynok = pFrstCell;
	while (begynok != NULL)
	{
		rememberMe = begynok->next;
		free(begynok);
		begynok = rememberMe;
	}

	return 0;
}