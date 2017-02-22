#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;
#define threads 4

int search(vector<int>,int,int,int);
int main() {
    vector<int> array={2,4,6,7,8,9,11,15,17,21,23,29,34,36,39,42,47,48,51,57,61,64,66,68,69,72,75,76,78,79};
    int query;
    double stime;
   /*
    for(int i=0;i<N;i++){
        int temp;cin>>temp;
        array.push_back(temp);
    }
    */
    cout<<"Size of Array : "<<array.size()<<endl;
    cout<<"Please enter element to be searched :";cin>>query;
    stime = omp_get_wtime();
    int pos=search(array,0,array.size()-1,query);
    if(pos!=-1) {
        cout << "Element found at position : " <<pos+1<<endl;
    }else{
        cout<<"Element was not found"<<endl;
    }
    cout << " Execution time = " << omp_get_wtime() - stime<<endl;
    return 0;
}

int search(vector<int> array,int low,int high,int query){
    int res = -1;
    if(high-low<=threads) {
        int partsize = (high - low / threads) + 1;
        #pragma omp parallel for
        for (int i = 0; i < threads; i++) {
            int nhigh = ((i + 1) * partsize) - 1 > high ? high : ((i + 1) * partsize) - 1;
            if (query >= array[i * partsize] && query <= array[nhigh]) {
                res = search(array, i * partsize, nhigh, query);
            }
        }
    }
    else {
        #pragma omp parallel for
        for (int i = low; i <= high; i++) {
            if (array[i] == query) {
            res = i;
            }
        }
    }
    return res;
}