/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <fstream>

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define PB push_back
#define MP make_pair
#define sz(a) (int)(a).size()

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932384626433832795028841971693

using namespace std;
typedef long long ll;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int convertString(string s)
{
    int num;
    stringstream sstr(s); // create a stringstream
    sstr>>num; // push the stream into the num
    return num;
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

int main()
{
  int n;
  cin>>n;
  vector<int> num(n);
  FOR(i,0,n)
    cin>>num[i];
  
  if (n == 1){
    cout<<"+"<<endl;
  }
  else{
    vector<int> sign(2*n-1);
    sign[2*n-2] = 1;
    sign[2*n-3] = 1;
    sign[2*n-4] = 0;
    int index = n-3;
    int value = num[n-1] - num[n-2];
    while(index >= 0){
      if (value >= num[index]){
	sign[2*index] = 0;
	sign[2*index+1] = 1;
	value -= num[index];
      }
      else{
	sign[2*index] = 1;
	sign[2*index+1] = 0;
	value = num[index] - value;
      }
      index--;
    }
    string ans;
    int reverse = 0;
    FOR(i,0,n){
      if (reverse^sign[2*i])
	ans.push_back('+');
      else
	ans.push_back('-');
      if (i < n-1){
	reverse  = !(reverse ^ sign[2*i+1]);
      }
    }
    cout<<ans<<endl;
  }
}