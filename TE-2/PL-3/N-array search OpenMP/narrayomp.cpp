#include <iostream>
#include <string.h>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	int num[20],sep[20],search,count,n,l,h,pos = 0,flag = 0;
	double stime;

	cout << "enter the no. of items (less than 20)" << endl;
	cin >> count;
 
	for (int i = 0; i < count; i++)
	{
		cout << "enter the items in the array in increasing order" << endl;
		cin >> num[i];
	}

	cout << "enter the item to be searched" << endl;
	cin >> search;
	cout << "enter the value of n (less than 20)" << endl;
	cin >> n;
	stime = omp_get_wtime();
	l = 0;
	h = count;
	int thid;
	while ( true )
	{
		#pragma omp parallel for
		for (int i = 0; i < n + 1; i++)
		{
			thid = omp_get_thread_num();
			cout << i << " is handled with thread " << thid << endl;
			sep[i] = l + ((i * (h - l)) / n);
		}
		
		#pragma omp parallel for
		
		for (int i = 0; i < n; i++)
		{
			if ( search < num[sep[i+1]] && search >= num[sep[i]] )
			{
				if (search == num[sep[i]])
				{
					pos = sep[i];
					flag = 1;
				}
				l = sep[i];
				h = sep[i + 1];
			}
		}
		
		if (flag == 1)
			break;
	}
	if (flag == 1)
		cout << "the no. to be searched is at position " << pos + 1 << endl;
	else
		cout << "the no. to be searched not found" << endl;
  	cout << "\n Execution time = " << omp_get_wtime() - stime;
	return 0;
}
