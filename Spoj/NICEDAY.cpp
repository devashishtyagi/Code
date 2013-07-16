#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);

		vector< pair<int, int> > Z(n);
		vector< pair<int, int> > p(n);

		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", &Z[i].first, &p[i].first, &p[i].second);
			Z[i].second = i;
		}

		sort(Z.begin(), Z.end());

		set< pair<int,int> > S;
		S.insert(p[Z[0].second]);

		int ans = 1;

		for(int i = 1; i < n; i++) {
			pair<int, int> d = p[Z[i].second];
			set< pair<int, int> >::iterator it = S.lower_bound(d);
		
			if (it == S.begin() || (--it)->second > d.second) {
				ans++;
				S.insert(d);

				it = S.upper_bound(d);
				set< pair<int,int> >::iterator start = it;

				while(it != S.end()) {
					if (it->second > d.second)
						it++;
					else
						break;
				}

				S.erase(start, it);
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
