/*
        By - Aditya Jain
        Date - 8 January 2018
*/

#include <iostream>
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
                r = new int*[n+1];
                this->n = n;
                for(int i=0;i<n;i++){
                        this->p[i]=p[i];
                        this->q[i]=q[i];
                }
                for(int i=0;i<n+1;i++){
                        e[i] = new float[n];
                        w[i] = new float[n];
                }
                for(int i=0;i<n+1;i++){
                        r[i] = new int[i];
                }
                for(int i=0;i<n+1;i++){
                        for(int j=0;j<n+1;j++){
                                this->e[i][j] = -1;
                                this->w[i][j] = -1;
                        }
                }
        }

        private: float _w(int i, int j){
                if( w[i][j]!=-1 ) return w[i][j];

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
                if( e[i][j]!=-1 ) return e[i][j];

                if(j==i-1){
                        e[i][j] = q[i-1];
			w[i][j]	= _w(i,j);
                }
                else{
                        float min = INF;
                        int ri=i;
			int myr=i;
                        while(ri<=j){
                                float c = _e(i,ri-1)+_e(ri+1,j);
                                if(min>c){
					min=c;
					myr=ri;
				}
                                ri++;
                        }
                        e[i][j] = min+_w(i,j); 
			r[i][j] = myr;
                }
                return e[i][j];
        }

        public: void solve(){
                cout<<"------e-------"<<endl;
                for(int i=1;i<=n;i++){
                        for(int j=0;j<n;j++){
                                float k = _e(i,j);
                                if(k!=INF){
                                        cout<<k<<'\t';
                                }else{
                                        cout<<"  "<<'\t';
                                }
                        }
			cout<<endl;
                }
                cout<<"-------w-------"<<endl;
                for(int i=1;i<=n;i++){
                        for(int j=0;j<n;j++){
                                float k = w[i][j];
                                if(k!=0){
                                        cout<<k<<'\t';
                                }else{
                                        cout<<"  "<<'\t';
                                }
                        }
			cout<<endl;
                }
		cout<<"-------r-------"<<endl;
                for(int i=1;i<n;i++){
                        for(int j=1;j<n;j++){
				if(i<=j){
                                	cout<<r[i][j]<<'\t';
				}else{
					cout<<" "<<'\t';				
				}
                        }
			cout<<endl;
                }
        }
};


int main(){
        int nodes;
        cout<<"Enter no of Nodes : ";cin>>nodes;
        float* p= new float[nodes+1];
        float* q= new float[nodes+1];
        cout<<"S/N 	Value 	Frequency"<<endl;
        for(int i=0;i<nodes+1;i++){
                cout<<i<<'\t';
                cin>>p[i]>>q[i];
        }
        OBST obst(p,q,nodes+1);
        obst.solve();
        cout<<"Done";
        return 0;
}
