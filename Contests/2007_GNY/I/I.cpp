#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define FOR(i,n) for(int i = 0; i<n; i++)
#define PB push_back
using namespace std;

bool eq(int x, char a)
{
	if(a == '0' + x)
		return true;
	if(a == '2' && ('0' + x) =='4' )
		return true;
	if(a == '4' && ('0' + x) =='2' )
		return true;
	return false; 
}
int main() {
	int b1[] = {1,1,3,2,1,1,6,6};
	int offb1[] = {1,2,2,2,0,3,2,1};
	int b2[] = {3,4,4,4,2,5,4,5};
	int offb2[] = {0,0,1,1,0,0,2,2};
	int b3[] = {2,3,6,6,5,4,5,2};
	int offb3[] = {3,3,3,0,3,3,1,1};
	int c;
	cin>>c;
	FOR(k,c)
	{
		vector<char> ans;
		string inp;
		cin>>inp;
		int count = 0;
		FOR(i,5)
		{
			string a;
			cin>>a;
			bool done = false;
			FOR(off,3)
			{
				FOR(ca, 8)
				{
					char a1 = inp[(b1[ca]-1)*2];
					char a2 = inp[(b2[ca]-1)*2];
					char a3 = inp[(b3[ca]-1)*2];
					int ia1 = inp[(b1[ca]-1)*2 + 1] -'0' - offb1[ca];
					int ia2 = inp[(b2[ca]-1)*2 + 1] -'0' - offb2[ca];
					int ia3 = inp[(b3[ca]-1)*2 + 1] -'0' - offb3[ca];
					if(ia1 <= 0)ia1 += 4;
					if(ia2 <= 0)ia2 += 4;
					if(ia3 <= 0)ia3 += 4;
					if(a1 == a[((0+off)%3)*2] && a2 == a[((1+off)%3)*2] && a3 == a[((2+off)%3)*2])
					{
						if(eq(ia1, a[((0+off)%3)*2 + 1]) && eq(ia2, a[((1+off)%3)*2 + 1]) && eq(ia3, a[((2+off)%3)*2 + 1]))
							done = true;
					}

					if(done)break;
				}
				if(done) break;
			}
			if(done)
			{
				count++;
				ans.PB('Y');
			}
			else
				ans.PB('N');
		}
		cout<<k+1<<" "<<count;
		FOR(i,ans.size())
			cout<<" "<<ans[i];
		cout<<endl;
	}
}