#include "NizForSort.h"
#include <malloc.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

NizForSort::NizForSort(int n)
{
	this->n = n;
	Niz = (short*)malloc(n * sizeof(short));
	this->sortiranje = nullptr;
}

NizForSort::~NizForSort()
{
	if (Niz != nullptr)
	{
		free(Niz);
	}
}



void NizForSort::Sort()
{
	if (sortiranje != nullptr)
		sortiranje(Niz, n);
}

void NizForSort::Printf()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << Niz[i] << " ";
	}
	cout << "END!" << endl;
}

void NizForSort::SetSort(void (*sortiranje)(short*, int))
{
	this->sortiranje = sortiranje;
}

void NizForSort::SetArray(short b[])
{
	Niz = b;
}

void NizForSort::LoadArray(string path)
{
	ifstream ulaz;
	ulaz.open(path);
	ulaz >> n;
	free(Niz);
	Niz = (short*)malloc(n * sizeof(short));
	for (int i = 0; i < n; i++)
	{
		ulaz >> Niz[i];
	}
	ulaz.close();
}

void NizForSort::generate(int low, int high, int n)
{

	srand(10);

	this->n = n;

	if (this->Niz != nullptr)
	{
		free(Niz);
	}

	Niz = (short*)malloc(sizeof(short) * n);

	for (int i = 0; i < n; i++)
	{
		Niz[i] = rand() % 1000;
	}

}
