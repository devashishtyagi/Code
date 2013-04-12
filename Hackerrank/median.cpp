#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

vector<int> store;

void median() {
   int n = store.size();

   if (n % 2 == 0) {
      long long sum = 0;
      sum += store[n/2];
      sum += store[n/2-1];
      double ans = (double) sum / 2.0;
      double y;
      float x = modf(ans, &y);
      if (x == 0.0f)
         printf("%d\n", (int)y);
      else
         printf("%.1f\n", ans);
   }
   else {
      cout<<store[n/2]<<"\n";
   }
}

void addOp(int num) {
   if (store.size() == 0)
      store.push_back(num);
   else {
      store.insert(lower_bound(store.begin(), store.end(), num), num);
   }
   if (store.size() == 0)
         cout<<"Wrong!\n";
   else
      median();
}

void removeOp(int num) {
   vector<int>::iterator it = lower_bound(store.begin(), store.end(), num);
   if (store.size() == 0 || it == store.end() || *it != num)
      cout<<"Wrong!\n";
   else {
      store.erase(it);
      if (store.size() == 0)
         cout<<"Wrong!\n";
      else
         median();
   }
}

int main(){
   int N;
   cin >> N;
   
   string s[N];   
   int x[N];
   
   for(int i = 0; i < N; i++){
      cin >> s[i] >> x[i];
      if (s[i] == "a")
         addOp(x[i]);
      else
         removeOp(x[i]);
   }
   
   return 0;
}