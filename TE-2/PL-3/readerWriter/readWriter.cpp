#include <iostream>
#include <omp.h>
using namespace std;
int main(){
	int numberOfReaderThreads,numberOfWriterThreads;
	omp_lock_t writelock;
	omp_init_lock(&writelock);

	cout<<"Enter no of Reader Threads(<10) : ";cin>>numberOfReaderThreads;
	cout<<"Enter no of Writer Threads(<10) : ";cin>>numberOfWriterThreads;

	int var=0;
	#pragma omp parallel num_threads(numberOfReaderThreads+numberOfWriterThreads) shared(var)
	{
		#pragma omp for nowait
		for(int i = 0; i < numberOfReaderThreads; ++i){
		//	cout<<"Reader with id "<<i<<" started";
			omp_set_lock(&writelock);
			cout<<"Reading Value of variable : "<<var<<endl;
			omp_unset_lock(&writelock);
		}

		#pragma omp for nowait
		for (int i = 0; i < numberOfWriterThreads; ++i){
		//	cout<<"Writer with id "<<i<<" started";
			omp_set_lock(&writelock);
			var+=100;
			cout<<"Writing into variable : "<<var<<endl;
			omp_unset_lock(&writelock);
		}
	}
	omp_destroy_lock(&writelock);
	return 0;
}