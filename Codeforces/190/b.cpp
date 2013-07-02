/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <functional>
#include <numeric>
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

#define INF 1000000000
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

vector<int> attack, defense;
vector<int> ciel;

int singleAttack () {	
	int i = 0, j = 0;

	int count = 0;

	while(i < attack.size() && j < ciel.size()) {
		while(j < ciel.size() && attack[i] > ciel[j])
			j++;
		if (j < ciel.size())
			count++;
		i++;
		j++;
	}

	int sum_ciel = 0, sum_jor = 0;
	int max_earn = 0;
	for(int i = 0; i < count; i++) {
		sum_ciel += ciel[ciel.size()-1-i];
		sum_jor += attack[i];
		max_earn = max(max_earn, sum_ciel - sum_jor);
	}

	return max_earn;
}

int wholeKilled() {
	vector<bool> killed(ciel.size(), false);

	int i = 0, j = 0;

	while(i < defense.size() && j < ciel.size()) {
		while(j < ciel.size() && defense[i] >= ciel[j])
			j++;
		if (j < ciel.size())
			killed[j] = true;
		i++;
		j++;
	}

	if (count(killed.begin(), killed.end(), true) == defense.size()) {
		vector<int> alive;
		for(int i = 0; i < ciel.size(); i++)
			if (!killed[i])
				alive.push_back(ciel[i]);

		int i = 0, j = 0;
		int count = 0;
		while(i < attack.size() && j < alive.size()) {	
			while(j < alive.size() && attack[i] > alive[j])
				j++;
			if (j < alive.size())
				count++;
			i++;
			j++;
		}
		if (count == attack.size()) {
			int sum_alive = accumulate(alive.begin(), alive.end(), 0);
			int sum_dead = accumulate(attack.begin(), attack.end(), 0);
			return sum_alive-sum_dead;
		}
		else {
			return -1;
		}

	}
	else {
		return -1;
	}
}

int main()
{
	int n, m;
	cin>>n>>m;

	for(int i = 0; i < n; i++) {
		string type;
		int power;
		cin>>type>>power;
		if (type[0] == 'A') {
			attack.push_back(power);
		}
		else {
			defense.push_back(power);
		}
	}

	for(int i = 0; i < m; i++) {
		int power;
		cin>>power;
		ciel.push_back(power);
	}

	sort(attack.begin(), attack.end());
	sort(ciel.begin(), ciel.end());
	sort(defense.begin(), defense.end());

	int single = singleAttack();

	int wasted = wholeKilled();

	int ans = single;

	if (wasted != -1)
		ans = max(single, wasted);

	cout<<ans<<endl;

	return 0;
}
