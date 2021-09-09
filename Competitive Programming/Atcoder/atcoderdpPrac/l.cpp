#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long int> ar(n, 0);
  long long int sum = 0;
  for(int i = 0 ; i < n ; i++){
    cin >> ar[i];
    sum += ar[i];
  }
  vector< vector<long long int> > dp(n, vector<long long int> (n, 0));
  for(int i = n-1 ; i >= 0 ; i--){
    dp[i][i] = ar[i];
    if(i < n - 1)
      dp[i][i+1] = max(ar[i], ar[i+1]);
    for(int j = i+2 ; j < n ; j++)
      dp[i][j] = max(ar[i]+min(dp[i+1][j-1], dp[i+2][j]),
                     ar[j]+min(dp[i+1][j-1], dp[i][j-2]));
  }
  cout << (long long int)2*dp[0][n-1] - sum << endl; 
	return 0;
}
