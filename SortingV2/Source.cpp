#include "NizForSort.h"
#include "SortingAlgorithms.h"
#include <iostream>
#include <chrono>
#include <windows.h>
#include <psapi.h>



using namespace std;
using namespace std::chrono;
using namespace Algoritmi;

void Racun(void (*sortiranje)(short*, int), int count);


/*template<typename TimeT = std::chrono::milliseconds>
struct measure
{
	template<typename F, typename ...Args>
	static typename TimeT::rep execution(F&& func, Args&& ... args)
	{
		auto start = std::chrono::steady_clock::now();
		std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
		auto duration = std::chrono::duration_cast<TimeT>
			(std::chrono::steady_clock::now() - start);
		return duration.count();
	}
};*/


int main(int argc, char* argv[])
{


	
	/*int numb = 100;
	for (int i = 0; i < 5; i++)
	{
		
		cout << "HeapSort" << endl;
		Racun(HeapSort, numb);
		cout << "BucketSortLS" << endl;	
		Racun(BucketSort, numb);
		cout << "End point " << i << endl << endl;
		numb *= 10;

	}*/
	cout << "BucketSortLS" << endl;
	Racun(BucketSort, 100000000);


	cin.ignore();
	return 0;
}



void Racun(void (*sortiranje)(short*, int), int count)
{
	NizForSort* n1;

	n1 = new NizForSort(10);
	n1->SetSort(sortiranje);
	//n1->LoadArray("C:\\Users\\Intel\\Desktop\\Test.txt");
	n1->generate(0, 1000, count);

 
	//n1->Printf();
	//time
	//steady_clock::time_point t1 = steady_clock::now();
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	system_clock::time_point begin = system_clock::now();

	

	
	//cout << "Time: " << measure<>::execution(n1->Sort()) << endl;
	n1->Sort();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	system_clock::time_point end = system_clock::now();

	//double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	//PULONG64 vreme = new ULONG64();
	//QueryProcessCycleTime(GetCurrentProcess(), vreme);
	//steady_clock::time_point t2 = steady_clock::now();

	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PPROCESS_MEMORY_COUNTERS)& pmc, sizeof(pmc));
	SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
	cout << "Total virtual memory used: " << virtualMemUsedByMe/1000 << "KB" << endl;
	PPROCESS_MEMORY_COUNTERS proMem = new PROCESS_MEMORY_COUNTERS();
	int test = GetProcessMemoryInfo(GetCurrentProcess(), proMem,	sizeof(PROCESS_MEMORY_COUNTERS));
	cout << "Peak Mem Usage: " << proMem->PeakWorkingSetSize/1000 << "KB" << endl;
	//time
	//n1->Printf();
	//cout << vreme << endl;
	auto duration = duration_cast<chrono::microseconds>(t2 - t1).count();
	//std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	std::chrono::duration<double> elapsed_seconds = end - begin;
	cout << elapsed_seconds.count() << endl;
	cout << duration  << endl << "--KRAJ--" << endl;
}




