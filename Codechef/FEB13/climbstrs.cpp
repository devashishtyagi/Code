#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> matrix;
const ll MOD = 1000000007;
const int K = 2;

vector<ll> F(K);
matrix T(K*K);
matrix Tn(K*K);

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K*K);
    for(int i=0; i<K; i++){
		for(int j=0; j<K; j++){
			for(int k=0; k<K; k++){
				C[i*K + j] += A[i*K + k] * B[k*K + j];
				if (C[i*K + j] >= MOD)
					C[i*K + j] %= MOD;
			}
		}
	}
    return C;
}

// computes A ^ p
matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int popcount(unsigned int x)
{
	int c = 0;
	for (; x > 0; x &= x -1) c++;
	return c;
}

int main(){
	int t;
	T[0] = 1; T[1] = 1;
	T[2] = 1; T[3] = 0;
	F[0] = 1; F[1] = 1;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if (n > 1){
			Tn = pow(T, n-1);
			int m = 0;
			for(int i=0; i<K; i++)
				m = ((ll)m + (ll)Tn[i]*F[i]%MOD)%MOD;
			if (popcount(m) == k)
				cout<<"CORRECT"<<endl;
			else
				cout<<"INCORRECT"<<endl;
		}
		else{
			if (1 == k)
				cout<<"CORRECT"<<endl;
			else
				cout<<"INCORRECT"<<endl;			
		}
	}
	return 0;
}