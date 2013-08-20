#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define FOR(i,n) for(int i = 0; i<n; i++)
#define PB push_back

using namespace std;

int main() {
	int n;
	cin>>n;
	for(int c = 1; c<=n; c++)
	{
		int p;
		cin>>p; //pancakes

		vector<int> v(p);
		FOR(i,p)
			cin>>v[i];
		vector<int> ans;
		FOR(i,p)
		{
			if(i == p-1)
			{
				if(v[0] < 0)
					ans.PB(1);
				break;
			}
			int val = p-i;
			int j = 0;
			for(;;j++)
				if(val == abs(v[j]))
					break;
			if(j != 0)
			{
				ans.PB(j+1);
				reverse(v.begin(),v.begin()+j+1);

			FOR(k,j+1)
				v[k] = -v[k];
			}
			if(v[0] > 0)
				ans.PB(1);
			ans.PB(p-i);
			reverse(v.begin(),v.begin()+p-i);
			FOR(k,p-i+1)
				v[k] = -v[k];
		}
		cout<<c<<" "<<ans.size();
		FOR(i,ans.size())
			cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}