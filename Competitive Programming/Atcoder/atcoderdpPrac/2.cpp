#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  ll n, k;
  cin >> n >> k;
	vector< ll > dp(n+k, INT_MAX), heights(n+k, 0);
  for(int i = 0 ; i < n ; i++)
    cin >> heights[i];
  dp[n-1] = 0;
	for(int i = n - 2 ; i >= 0 ; i--)
    for(int j = i + 1 ; j <= i + k ; j++)
      dp[i] = min(dp[i], dp[j] + abs(heights[i]-heights[j]));
  cout << dp[0] << endl;
	return 0;
}
