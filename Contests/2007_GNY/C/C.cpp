#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i = 1; i<= n; i++)
	{
		int r;
		cin>>r;
		string a;
		cin>>a;
		a.erase(a.begin() + r-1);
		cout<<i<< " " << a <<endl;
	}
}