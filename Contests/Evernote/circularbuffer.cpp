#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

list<string> Q;
int maxsize = 0, size = 0;

void remove(){
	if (size > 0){
		Q.pop_front();
		size--;
	}
}

void insert(string elem){
	while (size >= maxsize)
		remove();
	Q.push_back(elem);
	size++;
}

void listelements(){
	for (list<string>::iterator it = Q.begin(); it != Q.end(); ++it){
		cout<<*it<<endl;
	}
}

int circularbuffer(){
	cin>>maxsize;
	string cmd;
	while(true){
		cin>>cmd;
		if (cmd == "Q")
			break;
		if (cmd == "A"){
			int p;
			cin>>p;
			for(int i=0; i<p; i++){
				string elem;
				cin>>elem;
				insert(elem);
			}
		}
		else if (cmd == "R"){
			int p;
			cin>>p;
			for(int i=0; i<p; i++)
				remove();
		}
		else{
			listelements();
		}
	}
	return 0;
}
