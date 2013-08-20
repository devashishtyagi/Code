#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#define FOR(i,n) for(int i = 0; i<n; i++)
using namespace std;

int main() {
	string s;
	getline(cin,s);
	stringstream ss(s);
	int a;
	ss >> a;
	FOR(k,a)
	{
		getline(cin,s);
		int h = 0;
		int temp = 0;
		FOR(i,s.size())
		{
			if(s[i] == '[')
				temp++;
			else
				temp--;
			h = max(temp,h);
		}
		int ans = 1;
		FOR(i,h)
			ans *= 2;
		cout<<k+1<<" "<<ans<<endl;
	}
}