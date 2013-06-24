/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
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

int main()
{
    int n;
    cin>>n;

    int limit = (int)sqrt(n);

    int count[30];
    bool marked[limit+1];
    init0(count);
    init0(marked);

    int total_count = 1;
    count[1] = 1;
    marked[1] = true;

    for(int i = 2; i <= limit; i++) {
        if (!marked[i]) {
            int x = 1;
            int element = i;
            marked[element] = true;

            while((element*1LL*i) <= n ) {
                x++;
                element *= i;
                if (element <= limit)
                    marked[element] = true;
            }

            count[x]++;
            total_count += x;
        }
    }


    count[1] += (n - total_count);

    int xor_sum = 0;

    for(int i = 1; i <= 29; i++) { 
        if (count[i]%2 == 1)
            xor_sum ^= i;
    }

    if (xor_sum ==  0) {
        cout<<"Petya"<<endl;
    }
    else {
        cout<<"Vasya"<<endl;
    }

    return 0;
}
