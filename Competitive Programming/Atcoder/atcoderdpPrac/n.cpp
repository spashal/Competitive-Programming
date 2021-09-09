#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector< long long int > sizes(n, 0);
	for(int i = 0 ; i < n ; i++)
		cin >> sizes[i];
	vector< long long int > cost(n+1, 0);
	for(int i = 0 ; i < n ; i++)
		cost[i+1] = cost[i]+sizes[i];
	vector< vector< long long int > > dp(n, vector< long long int > (n, (long long int)INT_MAX*INT_MAX));
	for(int i = n-1 ; i >= 0 ; i--){
		dp[i][i] = 0;
		for(int j = i+1 ; j < n ; j++){
			long long int curCost = cost[j+1]-cost[i];
			for(int k = i ; k < j ; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + curCost);
		}
	}
	cout << dp[0][n-1] << endl;
	return 0;
}