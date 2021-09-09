#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector< int > a(n, 0);
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  vector< long long int > dp(k+1, 0);
  dp[0] = 1;
  long long int mod = 1e9+7;
    vector< long long int > cumSum(k+1, 0);
  for(int i = 0 ; i < n ; i++){
    cumSum[0] = 1;
    for(int j = 1 ; j <= k ; j++)
      cumSum[j] = (dp[j] + cumSum[j-1])%mod;
    for(int j = 0 ; j <= k ; j++)
      if(a[i] >= j)
        dp[j] = cumSum[j];
      else
        dp[j] = ((cumSum[j]-cumSum[j-a[i]-1])%mod+mod)%mod;
  }
  cout << dp[k] << endl;   
  return 0;
}