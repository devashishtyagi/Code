#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int multiply(){
	int n;
	cin>>n;
	vector<long long> prod(n);
	long long product = 1;
	int zerocount = 0;
	for(int i=0; i<n; i++){
		cin>>prod[i];
		if (i != 0){
			if (prod[i] != 0)
				product *= prod[i];
			else
				zerocount++;
		}
	}
	if ((zerocount - (prod[0] == 0?1:0)) > 0)
		cout<<0<<endl;
	else
		cout<<product<<endl;
	for(int i=1; i<n; i++){
		bool flag = false;
		if (prod[i] != 0){
			product = product/prod[i];
			if (zerocount > 0)
				flag = true;
		}
		else{
			if (zerocount > 1)
				flag = true;
		}
		if (prod[i-1] != 0)
			product = product*prod[i-1];
		if (flag)
			cout<<0<<endl;
		else
			cout<<product<<endl;
	}
	return 0;
}
