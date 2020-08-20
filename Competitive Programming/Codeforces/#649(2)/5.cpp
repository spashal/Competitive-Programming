#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005], nom = 0, size = 0, one = 0, logi[100005], k, cycle = 100005, start, parent[100005];
bool on[100005], vis[100005];
vector< ll > adj[100005], v;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u); if( !color[u] ) color[u] = 1; color[v] = 3 - color[u];}

void prep(){ for(int i = 1 ; i <= n ; i++) vis[i] = 0;}

void cycle_dfs(int node, int log){
	vis[node] = true;
	on[node] = true;
	logi[node] = log;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if( parent[node] != adj[node][i] and on[adj[node][i]] ){
			parent[adj[node][i]] = node;
			if(cycle > logi[node] - logi[adj[node][i]] + 1){
				start = node;
				cycle = logi[node] - logi[adj[node][i]] + 1;
			}
		}
		else if( !vis[adj[node][i]] ){
			parent[adj[node][i]] = node;
			cycle_dfs(adj[node][i], log + 1);
		}
	}
	on[node] = false;
}

// int component_dfs(int node, int number){
// 	num[node] = number;
// 	siz[node] = 0;
// 	size++;
// 	for(int i = 0 ; i < adjr[node].size() ; i++)
// 		if( !vis[adjr[node][i]] )
// 			component_dfs(adjr[node][i], number);
// 	siz[node] = size;	
// }
// ll maxsize = 100005;

// void print_dfs(int node){
// 	cout << node << " ";
// 	vis[node] = true;
// 	for(int i = 0 ; i < adjr[node].size() ; i++)
// 		if( !vis[adjr[node][i]] and size < maxsize ){
// 			size++;
// 			print_dfs(adjr[node][i]);
// 		}
// }

int main(){
	cin >> n >> m >> k;
	ginp;
	for(int i = 1 ; i <= n ; i++)
		if( !vis[i] )
			cycle_dfs(i, 0);
	prep();
	for(int i = 1 ; i <= n ; i++)
		if( !vis[node] ){
			size = 0;
			component_dfs(i, ++nom);
			if( maxsize < size ){
				maxsize = size;
				one = i;
			}
		}
	if( maxsize >= ceil(k / 2) ){
		cout << ceil(k / 2) << endl;
		size = 0;
		prep();
		print_dfs(one);
		cout << endl;
	}
	else{
		cout << "2" << endl;
		cout << cycle << endl;
		for(int i = 0 ; i < cycle ; i++){
			cout << start << " ";
			start = parent[start];
		}
		cout << endl;
	}
	return(0);
}