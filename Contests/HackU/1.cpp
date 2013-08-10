#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    int cycle = 0;
    int num = -1;

    for(int i = 2; i < 10000; i++) {
        int rem = 10;
        vector<int> found(i, -1);
        
        int steps = 0;
        while(found[rem%i] == -1) {
            found[rem%i] = steps++;
            rem = rem%i;
            rem = rem*10;
        }

        if (cycle < steps - found[rem%i]) {
            cycle = steps - found[rem%i];
            num = i;
        }
    }
    
    cout<<num<<endl;

    return 0;
}
