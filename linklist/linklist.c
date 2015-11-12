#include <stdio.h>
#include "linklist.h"

int isEmpty(List L)
{
	return L->Next == NULL;
}

int isLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(int X, List L)
{
	Position P;
	P = L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;
	return P;

}

Position FindPrevious(int X, List L)
{
	Position P;
	P = L;
	while(P ->Next !=NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}

void Delete(int X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X,L);
	if(!isLast(P,L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}