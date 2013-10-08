#include <iostream>
#include <vector>
#include <set>

using namespace std;

int LIS(vector<int> A)
{
    int N = A.size(),i;
    set<int> s;
    set<int>::iterator k;
    for (i=0;i<N;i++)
    {
        if (s.insert(A[i]).second)
        {
           k = s.find(A[i]);
           k++;
           if (k!=s.end())
              s.erase(k);
        }
    }
    return s.size();
}

int main() {
  int n;
  cin>>n;
  vector<int> A(n);
  for(int i = 0; i < n; i++)
    cin>>A[i];
  cout<<LIS(A)<<endl;

  return 0;
}