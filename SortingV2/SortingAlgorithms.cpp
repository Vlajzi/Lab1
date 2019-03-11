#include "SortingAlgorithms.h"
#include <stdlib.h>
#include <vector>
#include <algorithm> 
#include "SortedList.h"


using namespace std;

namespace Algoritmi
{

	void swap(short* a, short* b)
	{
		short tmp = *a;
		*a = *b;
		*b = tmp;
	}


	


	void InsercionSort(short* a, short n)
	{
		int i = 1;

		while (i < n)
		{
			int j = i;

			while (j > 0 && a[j - 1] < a[j])
			{
				swap((a + j), (a + j - 1));

				j--;
			}

			i++;
		}
	}

	

	void heapify(short* a, int n, int i)
	{
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && a[left] < a[largest])
		{
			largest = left;
		}

		if (right < n && a[right] < a[largest])
		{
			largest = right;
		}

		if (largest != i)
		{
			swap((a + i), (a + largest));

			heapify(a, n, largest);
		}
	}


	void HeapSort(short* a, int n)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(a, n, i);
		}

		for (int i = n - 1; i >= 0; i--)
		{

			swap(a, (a + i));

			n--;

			heapify(a, n, 0);
		}
	}

	int MaxElement(short* a, int n)
	{
		short min = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] > min)
			{
				min = a[i];
			}
		}
		return min;
	}

	void Copy(short* a, short* b, int n)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = b[i];
		}
	}


	void CountingSort(short* a, int n)
	{
		int max = MaxElement(a, n);

		short* c = (short*)calloc(max + 1, sizeof(short));

		short* b = (short*)calloc(n, sizeof(short));

		for (int i = 0; i < n; i++)
		{
			c[a[i]]++;
		}

		for (int i = 1; i < max + 1; i++)
		{
			c[i] += c[i - 1];
		}

		for (int i = n - 1; i >= 0; i--)
		{
			b[c[a[i]] - 1] = a[i];
			c[a[i]]--;
		}

		Copy(a, b, n);

		free(b);
		free(c);
	}

	void BucketSort(short* a, int n)
	{
		int k = 100;

		int div = 1000 / 10;//n / k;

		short** b = (short**)calloc(k, sizeof(short*));

		for (int i = 0; i < k; i++)
		{
			b[i] = (short*)calloc(n, sizeof(short));
		}

		int* poz = (int*)calloc(k, sizeof(int));

		for (int i = 0; i < n; i++)
		{
			b[a[i] / div][poz[a[i] / div]++] = a[i];
		}

		for (int i = 0; i < k; i++)
		{
			//InsercionSort(b[i],poz[i]);
			HeapSort(b[i], poz[i]);

		}

		int index = 0;
		for (int i = k-1; i >= 0; i--)
			for (int j = 0; j < poz[i]; j++)
				a[index++] = b[i][j];



	}


	void BucketSortLS(short* a, int n)
	{
		int k = 100;

		int div = 1000 / 10;//n / k;

		SortedList* b = (SortedList*)calloc(k, sizeof(SortedList));

		//SortedList b[100];

		for (int i = 0; i < k; i++)
		{
			b[i] = SortedList();
		}

		int* poz = (int*)calloc(k, sizeof(int));

		for (int i = 0; i < n; i++)
		{
			b[a[i] / div].AddElem(a[i]);
			poz[a[i] / div]++;
		}

		/*for (int i = 0; i < k; i++)
		{
			//InsercionSort(b[i],poz[i]);
			HeapSort(b[i], poz[i]);

		}*/

		int index = 0;
		for (int i = k; i >= 0; i--)
			for (int j = 0; j < poz[i]; j++)
				a[index++] = b[i].Get();
	}

}

