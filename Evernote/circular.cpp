#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
public:
	char* data;
	struct Node* next;
	Node(char* a){
		data = a;
		next = NULL;
	}
};

struct Node* head = NULL;
struct Node* tail = NULL;
int size = 0, maxsize;

void list(){
	struct Node* pointer = head;
	while (pointer != NULL){
		cout<<pointer->data<<endl;
		pointer = pointer->next;
	}
}

void remove(){
	if (head != NULL){
		if (size == 1){
			delete[] head;
			head = NULL;
			tail = NULL;
		}
		else{
			struct Node* temp = head->next;
			delete[] head;
			head = temp;
		}
		size--;
	}
}

void insert(char* a){
	while (size >= maxsize){
		remove();
	}
	if (size == 0){
		head = new Node(a);
		tail = head;
	}
	else{
		tail->next = new Node(a);
		tail = tail->next;
	}
	size++;
}

int main(){
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
			list();
		}
	}
}
