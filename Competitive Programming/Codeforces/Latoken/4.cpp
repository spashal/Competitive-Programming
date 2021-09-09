#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
vector< bool > vis;

void dfs(int node){
	cout << "? " << node << "\n";
	cout.flush();
	vis[node] = true;
	vector< int > temp(n+1, 0);
	int ctr = 0, tempNode = 0;
	for(int i = 1 ; i <= n ;i++){
		cin >> temp[i];
		if(temp[i] == 1){
			vis[i] = true;
			adj[node].pb(i);
			adj[i].pb(node);
			ctr++;
			tempNode = i;
		}
	}
	if(ctr==1){
		for(int i = 1 ; i <=n ; i++){
			if(temp[i] == 2){
				vis[i] = true;
				adj[tempNode].pb(i);
				adj[i].pb(tempNode);
			}
			
		}
		for(int i = 1 ; i <= n ; i++)
			if(temp[i] == 3 and !vis[i])
				dfs(i);
		return;
	}
	for(int i = 1 ; i <= n ; i++){
		if(temp[i] == 2 and !vis[i]){
			dfs(i);
		}
	}

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vis.resize(n+1, false);
    dfs(1);
    cout << "!" << "\n";
   	vis.clear();
    vis.resize(n+1, false);
    for(int i = 1 ; i <= n ; i++)
    	if(!vis[i]){
    		vis[i] = true;
    		for(int j = 0 ; j < adj[i].size() ; j++){
    			vis[adj[i][j]] = true;
    			cout << i << " " << adj[i][j] << "\n"; 
    		}
    	}
    cout.flush();
	return(0);
}