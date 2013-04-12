typedef long long ll;
typedef vector<ll> matrix;
const ll MOD = 1000000007;
const int K = 2;

vector<ll> F1(K);
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