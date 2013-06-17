/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1E18
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

vector<LL> sides;

vector<int> find(int index, int l, int k) {
	vector<int> perm;

	forn(i, 0, l-k)
		perm.push_back(0);
	forn(i, l-k, l)
		perm.push_back(1);

	LL m = INF;
	LL threshold = sides[index+l];
	vector<int> minperm = perm;

	do {
		LL sum = 0;
		forn(i, 0, l)
			if(perm[i] == 1)
				sum += sides[index+i];
		if (sum <= m && sum > threshold) {
			minperm = perm;
			m = sum;
		}
	}while(next_permutation(perm.begin(), perm.end()));

	return minperm;
}

int main()
{
	int n, k;
	cin>>n>>k;

	sides.resize(n);

	forn(i, 0, n)
		cin>>sides[i];

	int index[n];

	set< pair<int,int> > sideSet;
	forn(i, 0, n)
		sideSet.insert(make_pair(sides[i], i+1));

	int z = 0;
	foreach(sideSet, it) {
		sides[z] = it->first;
		index[z] = it->second;
		z++;
	}


	LL sum = 0;
	forn(i, 0, k-1) {
		sum += sides[i];
	}

	bool foundfirst = false;
	bool foundsecond = false;
	vector<int> firstTaken;
	vector<int> secondTaken;

	forn(i, k-1, n) {
		if (sum > sides[i]) {
			vector<int> perm = find(max(i-2*k, 0), min(2*k, i), k-1);
			foundfirst = true;
			forn(j, 0, perm.size()){
				if (perm[j] == 1)
					firstTaken.push_back(max(i-2*k, 0)+j);
			}
			firstTaken.push_back(i);
			break;
		}
		sum -= sides[i-k+1];
		sum += sides[i];
	}

	if (foundfirst) {
		vector<bool> taken(n, false);

		forn(i, 0, firstTaken.size()){
			taken[firstTaken[i]] = true;
		}

		vector< pair<int,int> > newsides;
		forn(i, 0, n) {
			if (!taken[i])
				newsides.push_back(make_pair(sides[i], i));
		}

		sum = 0;
		forn(i, 0, k-1)
			sum += newsides[i].first;

		forn(i, k-1, n) {
			if (sum > newsides[i].first) {
				foundsecond = true;
				forn(j, i-k+1, i+1) {
					secondTaken.push_back(newsides[j].second);
				}
				break;
			}
			sum -= newsides[i-k+1].first;
			sum += newsides[i].first;
		}
	}

	if (foundfirst && foundsecond) {
		cout<<"Yes"<<endl;;
		forn(i, 0, firstTaken.size())
			cout<<index[firstTaken[i]]<<" ";
		forn(i, 0, secondTaken.size())
			cout<<index[secondTaken[i]]<<" ";
		cout<<endl; 
	}
	else {
		cout<<"No"<<endl;;
	}

	return 0;
}
