#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int topfour(){
	int n;
	cin>>n;
	vector<int> elem(4);
	for(int i=0; i<4; i++){
		cin>>elem[i];
	}
	sort(elem.rbegin(), elem.rend());
	for(int i=4; i<n; i++){
		int a;
		cin>>a;
		for(int j=0; j<4; j++){
			if (elem[j] <= a){
				int temp = elem[j];
				elem[j] = a;
				for(int k=j+1; k<4; k++){
					swap(elem[k], temp);
				}
				break;
			}
		}
	}
	for(int i=0; i<4; i++)
		cout<<elem[i]<<endl;
	return 0;
}
