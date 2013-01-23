#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

// size of the field
int S;
// Assuming the elevation can fit in 32 bit integers
vector< vector<int> > field;
vector<int> basin;
vector<int> basinsize;

// find the basin of the i,j th cell
int findBasin(int i, int j){
	if (basin[i*S+j] != -1)
		return basin[i*S+j];
	int minElevation = field[i][j];
	int minx = i, miny = j;
	
	// Check the neighbour with least elevation
	if (i+1 < S){
		int value = field[i+1][j];
		if (value < minElevation){
			minElevation = value;
			minx = i+1; miny = j;
		}
	}
	if (i-1 >= 0){
		int value = field[i-1][j];
		if (value < minElevation){
			minElevation = value;
			minx = i-1; miny = j;
		}
	}
	if (j+1 < S){
		int value = field[i][j+1];
		if (value < minElevation){
			minElevation = value;
			minx = i; miny = j+1;
		}
	}
	if (j-1 >= 0){
		int value = field[i][j-1];
		if (value < minElevation){
			minElevation = value;
			minx = i; miny = j-1;
		}
	}
	
	// Check if sink
	if (minx == i && miny == j){
		basin[i*S+j] = i*S+j;
	}
	else{
		basin[i*S+j] = findBasin(minx, miny);
	}
	return basin[i*S+j];
}

int main()
{
	cin>>S;
	
	// Resize the field and lowest to size S
	field.resize(S);
	basin.resize(S*S, -1);
	
	// Take the input
	for(int i=0; i<S; i++){
		for(int j=0; j<S; j++){
			int temp;
			cin>>temp;
			field[i].push_back(temp);
		}
	}
	
	// Calculate the basin of each field
	for(int i=0; i<S; i++){
		for(int j=0; j<S; j++){
			if (basin[i*S+j] == -1){
				basin[i*S+j] = findBasin(i,j);
			}
		}
	}
	
	// Find size of each basin
	sort(basin.begin(), basin.end());
	int size = 1;
	for(int current = 1; current<basin.size(); current++){
		if (basin[current] == basin[current-1]){
			size++;
		}
		else{
			basinsize.push_back(size);
			size = 1;
		}
	}
	basinsize.push_back(size);
	
	// Print the basin sizes
	sort(basinsize.rbegin(), basinsize.rend());
	for(int i=0; i<basinsize.size(); i++)
		cout<<basinsize[i]<<" ";
	cout<<endl;
	
	return 0;
}
