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

using namespace std;
typedef long long LL;

vector< pair<LL, LL> > s;
int ptr = 0;

double intersection(pair<LL, LL> p1, pair<LL, LL> p2) {
	double x = (p1.second - p2.second);
	x = x/(double)(p2.first - p1.first);
	return x;
}

void add(pair<LL, LL> p) {
	if (s.size() < 2) {
		s.push_back(p);
	}
	else {
		pair<LL, LL> p1 = s[s.size()-1];
		pair<LL, LL> p2 = s[s.size()-2];
		if (intersection(p1, p) <= intersection(p2, p)) {
			s.pop_back();
			ptr = min(ptr, (int)s.size()-1);
			add(p);
		}
		else {
			s.push_back(p);
		}
	}
}

LL find(LL x) {
	while(ptr+1 < s.size() && (s[ptr].first*x + s[ptr].second >= s[ptr+1].first*x + s[ptr+1].second))
		ptr++;
	return s[ptr].first*x + s[ptr].second;
}
