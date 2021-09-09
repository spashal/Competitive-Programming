#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  ll n;
  cin >> n;
	vector< ll > dp(n+1, 0), heights(n+1, 0);
  for(int i = 0 ; i < n ; i++)
    cin >> heights[i];
  dp[n] = INT_MAX;
	for(int i = n - 2 ; i >= 0 ; i--)
    dp[i] = min(dp[i+1] + abs(heights[i]-heights[i+1]),
                dp[i+2] + abs(heights[i]-heights[i+2]));
  cout << dp[0] << endl;
	return 0;
}
