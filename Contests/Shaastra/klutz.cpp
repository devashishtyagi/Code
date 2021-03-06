#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

long long memo[1000001];

long long cycle(long long n){
  if (n < 1000001){
    if (memo[n] != -1)
      return memo[n];
    else{
      if (n&1)
	memo[n] = cycle((3*n+1)>>1)+1;
      else
	memo[n] = cycle(n>>1)+1;
      return memo[n];
    }
  }
  else{
      if (n&1)
	return cycle((3*n+1)>>1)+1;
      else
	return cycle(n>>1)+1;
  }    
}


int main(){
  memset(memo, -1, sizeof memo);
  memo[1] = 0;
  int t;
  scanf("%d",&t);
  while(t--){
    long long p,q,m,x,l;
    scanf("%lld %lld %lld %lld %lld",&p,&q,&m,&x,&l);
    long long ans = cycle(x);
    long long num = x;
    for(int i=1; i<l; i++){
      num = ((p*num+q)%m)+1;
      ans += cycle(num);
    }
    cout<<ans<<endl;
  }
  return 0;
}
