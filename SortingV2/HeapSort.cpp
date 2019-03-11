#include "HeapSort.h"
#include <stdlib.h>

HeapSort::HeapSort(int min, int max, int n)
{
	this->count = n;
	srand(0);
	for (int i = 0; i < n; i++)
	{
		this->array[i] = rand()%max + min;
	}
}

HeapSort::~HeapSort()
{

}
