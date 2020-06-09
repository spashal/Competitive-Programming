#include <bits/stdc++.h>
using namespace std;
int n, m, indegree[100005], dp[100005];
vector< int > adj[100005];
 
int dfs( int node){
	if( dp[node] )
		return dp[node];
	int temp = 0;
	for( int i = 0 ; i < adj[node].size() ; i++ )
		temp = max( temp, dfs( adj[node][i]) + 1);
	dp[node] = temp;
	return temp;
}

int main(){
	cin >> n >> m;
	for( int i = 0 ; i < m ; i++ ){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	int ans = 0;
	for( int i = 1 ; i <= n ; i++ )
		if( !indegree[i] )
			ans = max( ans, dfs(i));
	cout << ans << endl;
	return(0);
}