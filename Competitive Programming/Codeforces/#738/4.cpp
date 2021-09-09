#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m1, m2, t, a[100005];
vector< ll > adj1[100005];
vector< ll > adj2[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp1 for( int i = 0 ; i < m1 ; i++ ){ int u, v; cin >> u >> v; adj1[u].push_back(v); adj1[v].push_back(u);}
#define ginp2 for( int i = 0 ; i < m2 ; i++ ){ int u, v; cin >> u >> v; adj2[u].push_back(v); adj2[v].push_back(u);}
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

void comp(int node, int parent, int count, vector<vector<ll>> &edges, vector<ll> &marks, int pra, vector<ll> &parents){
	parents[node] = pra;
	marks[node] = count;
	for(int i = 0 ; i < edges[node].size() ; i++)
		if(edges[node][i] != parent)
			comp(adj[node][i], node, count, edges, marks, pra);
}

int dfs(int node, ...){
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		int par1 = i, par2 = node;
		while(parent1[par1] != par1)
			par1 = parent1[par1];
		while(parent1[par2] != par2)
			par2 = parent1[par2];
		if(par1 != par2){
			int pr1 = i, pr2 = node;
			while(parent2[pr1] != pr1)
				pr1 = parent2[pr1];
			while(parent2[pr2] != pr2)
				pr2 = parent2[pr2];
			if(pr1 != pr2){
				parent1[par1] = par2;
				parent2[pr1] = pr2;
				ans = max(dfs())
			}
		}
	}
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m1 >> m2;
		ginp1;
		ginp2;

		// component formation and numbering
		vector<ll> mark1(n+1, 0), mark2(n+1, 0), parent1(n+1, 0), parent2(n+1, 0);
		for(int i = 1 ; i <= n ; i++)
			parent1[i] = parent2[i] = i;
		int count = 0;
		for(int i = 1 ; i <= n ; i++)
			if(!mark1[i])
				comp(i, 0, ++count, adj1, mark1, i, parent1);
		count = 0;
		for(int i = 1 ; i <= n ; i++)
			if(!mark2[i])
				comp(i, 0, ++count, adj2, mark2, i, parent2);	

		// recursive function to calculate max added edges and answer array as well


	}
	return(0);
}