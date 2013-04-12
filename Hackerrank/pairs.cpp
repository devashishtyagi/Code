#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	vector<int> num(n);
	for(int i = 0; i < n; i++)
		cin>>num[i];
	sort(num.begin(), num.end());
	int pairs = 0;
	int left = 0, right = 1;
	while (left < n) {
		if (num[right] - num[left] == k){
			pairs++;
			if (right < n-1)
				right++;
			else
				left++;
		}
		else if (num[right] - num[left] < k && right < n-1)
			right++;
		else
			left++;
	}
	cout<<pairs<<endl;

	return 0;
}