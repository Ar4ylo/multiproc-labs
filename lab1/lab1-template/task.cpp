
#include "stdafx.h"
<<<<<<< HEAD
#include "stdio.h"
#include "iostream"
#include "clocale"
#include "omp.h"
using namespace std;

int performArrayTask(long size)
{
	setlocale(LC_ALL, "Rus");
	long S;
	S=0;
	long *arr = new long[size];

	for(long i=0; i<size; i++)
		{
			arr[i] = i;		
		}

	double start_time=omp_get_wtime();
	
	#pragma omp parallel num_threads(4)
	{
		long local_sum = 0;
		#pragma omp for
		for(long i=0; i<size; i++)
		{
			local_sum+=arr[i];
		}
		S+=local_sum;
	}
	delete []arr;
	double end_time=omp_get_wtime();

cout<<"Сумма элементов массива: "<<(unsigned long)S;
printf("\n замер времени %lf\n", end_time-start_time);

return 0;
	
}

=======
#include <stdio.h>
#include "iostream"
#include <omp.h>

using namespace std;
int performArrayTask(int size)
{    
	setlocale(LC_ALL);
	long s;
	s = 0;
	long *arr = new long[size];

	for(long i=0; i<size; i++)
    #pragma omp for
	{
		arr[i] = i;
		s=s+arr[i];
	}
	delete []arr;
	double end_time=omp_get_wtime;
	return 0;
}
>>>>>>> origin/master
