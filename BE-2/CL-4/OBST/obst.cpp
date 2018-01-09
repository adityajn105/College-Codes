/*
	By - Aditya Jain
	Date - 8 January 2018
*/

#include <iostream>
#include <vector>
#define INF 999999;

using namespace std;

class OBST{
	private: float* p;
	private: float* q;
	private: float** e;
	private: float** w; 
	private: int** r;
	private: int n;

	public: OBST(float* p,float* q,int n){
		w = new float*[n+1];
		e = new float*[n+1];
		this->p=new float[n];
		this->q=new float[n];
		r = new int*[n];
		this->n = n;

		for(int i=0;i<n;i++){
			this->p[i]=p[i];
			this->q[i]=q[i];
		}

		for(int i=0;i<n+1;i++){
			e[i] = new float[n];
			w[i] = new float[n];
		}
		for(int i=0;i<n;i++){
			r[i] = new int[i];
		}

		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				this->e[i][j] = NULL;
				this->w[i][j] = NULL;
			}
		}
	}

	private: float _w(int i, int j){
		if( w[i][j]!=NULL ) return w[i][j];

		float sum = 0;
		int k=i;
		while(k<=j){
			sum += p[k];
			k++;
		}
		k=i-1;
		while(k<=j){
			sum += q[k];
			k++;
		}
		w[i][j] = sum;
		return w[i][j];
	}

	private: float _e(int i,int j){
		if( e[i][j]!=NULL ) return e[i][j];
		
		if(j==i-1){
			e[i][j] = q[i-1];
		}
		else{
			float min = INF;
			int r=i;
			while(r<=j){
				float c = _e(i,r-1)+_e(r+1,j);
				if(min<=c) min=c;
			}
			e[i][j] = min+_w(i,j);
		}
		return e[i][j];
	}

	public: void solve(){
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
				_e(i,j);	
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
				cout<<_e(i,j)<<endl;	
			}
			cout<<endl;
		}

	}
};


int main(){
	int nodes;
	cout<<"Enter no of Nodes";cin>>nodes;
	float* p= new float[nodes+1];
	float* q= new float[nodes+1];
	cout<<"S/N 	value 	freq"<<endl;
	for(int i=0;i<nodes+1;i++){
		cout<<i<<'\t';
		cin>>p[i]>>q[i];
	}
	OBST obst(p,q,nodes+1);
	obst.solve();
	return 0;
}