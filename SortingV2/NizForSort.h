#pragma once

#include<string>

using namespace std;

class NizForSort
{
public:
	NizForSort(int n);
	~NizForSort();

	void Sort();
	void Printf();
	void SetSort(void (*sortiranje)(short*, int));
	void SetArray(short b[]);
	void LoadArray(string path);
	void generate(int low, int high, int n);
private:
	short* Niz;
	short n;
	void (*sortiranje)(short*, int);
};
