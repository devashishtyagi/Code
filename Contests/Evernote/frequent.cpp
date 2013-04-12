#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int N,k;
	map<string,int> mymap;
	vector< pair<int,string> > arr;
	cin>>N;
	for(int i=0; i<N; i++){
		string temp;
		cin>>temp;
		if (mymap.find(temp) != mymap.end())
			mymap[temp]++;
		else
			mymap[temp] = 1;
	}
	cin>>k;
	for (map<string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		arr.push_back(make_pair(-it->second,it->first));
	sort(arr.begin(),arr.end());
	for(int i=0; i<k; i++)
		cout<<arr[i].second<<endl;
	return 0;
}
