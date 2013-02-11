#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;


int getCoff(int i){
	return ((i == 0)?-1:1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
		int n;
		double a,b,c;
		cin>>n>>a>>b>>c;
		vector<double> y(n);
		vector<int> l(n,0);
		double sum = 0.0;
		for(int i=0; i<n; i++){
			cin>>y[i];
			sum += y[i];
		}
		
		int config = -1;
		double diff = 0.0;
		for(int i=0; i<8; i++){
			bitset<3> bit(i);
			double value = a*getCoff(bit[0]) + b*getCoff(bit[1]) + c*getCoff(bit[2]);
			if (abs(y[0] - value) < diff || config == -1){
				config = i;
				diff = abs(y[0] - value);
			}
		}
		bitset<3> bit(config);
		l[0] = getCoff(bit[0]); l[n-1] = getCoff(bit[1]); l[n-2] = getCoff(bit[2]);
		for(int i=1; i<n-2; i++){
			double value1 = a + b*l[i-1] + c*l[((i>1)?(i-2):(n-1))], value2 = -a + b*l[i-1] + c*l[((i>1)?(i-2):(n-1))]; 
			if (abs(y[i] - value1) > abs(y[i] - value2))
				l[i] = -1;
			else
				l[i] = 1;
		}
		
		for(int i=0; i<n; i++)
			cout<<l[i]<<" ";
		cout<<endl;
    }
    return 0;
}
