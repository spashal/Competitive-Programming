#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< int > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u); edgeDeleted[make_pair(min(u,v), max(u,v))] = false}
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

map< pair<int, int>, bool> edgeDeleted;
int leavesCtr = 0;
vector< pair<int, int> > leaves;
vector< bool > vis;
vector< pair< pair< int, int>, pair< int, int > > > ans; 

int makeBamboos(int node, int parent){
	int degree = adj[node].size();
	bool childFound1 = false;
	bool childFound2 = false;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if(parent != adj[node][i]){
			int childDegree = makeBamboos(adj[node][i], node);
			if(childDegree == 3){
				edgeDeleted[mp(min(node, adj[node][i]), max(node, adj[node][i]))] = true;
				ans.pb(mp(mp(node, adj[node][i]), mp(-1, -1)));
				degree--;
			}
			else if(childDegree <= 2 and !childFound1){
				childFound1 = true;
			}
			else if(childDegree <= 2 and !childFound2)
				childFound2 = true;
			else if((degree > 3 and node != 1) or (node == 1 and degree > 2)){
				edgeDeleted[mp(min(node, adj[node][i]), max(node, adj[node][i]))] = true;
				ans.pb(mp(mp(node, adj[node][i]), mp(-1, -1)));
				degree--;	
			}
		}
	}
	return degree;
}

void markLeaves(int node, int parent){
	int degree = 0;
	vis[node] = true;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if(!edgeDeleted[mp(min(adj[node][i], node), max(adj[node][i], node))]){
			degree++;
			if(parent != adj[node][i])
				markLeaves(adj[node][i], node);
		}
	}
	if(degree == 1){
		leavesCtr++;
		if(leavesCtr % 2)
	 		leaves.pb(mp(node, -1));
	 	else
	 		leaves[leaves.size() - 1].ss = node;	
	}
	if(degree == 0)
		leaves.pb(mp(node, node));
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		leavesCtr = 0;
		cin >> n;
		vis.resize(n + 1, false);
		m = n - 1;
		for(int i = 0 ; i < m ; i++){
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
			edgeDeleted[mp(min(u,v), max(u,v))] = false;
		}
		makeBamboos(1, 0);
		for(int i = 1 ; i <= n ; i++)
			if(!vis[i])
				markLeaves(i, 0);
		cout << ans.size() << endl;
		for(int i = 0 ; i < ans.size() ; i++){
			if(i == 0){
				ans[0].sf = leaves[0].ss;
				ans[0].sss = leaves[1].ff;
			}
			else{
				ans[i].sf = leaves[i].ss;
				ans[i].sss = leaves[i+1].ff;
			}
		}
		for(int i = 0 ; i < ans.size() ; i++)
			cout << ans[i].fff << " " << ans[i].fs << " " << ans[i].sf << " " << ans[i].sss << endl;
		for(int i = 1 ; i <= n ; i++)
			adj[i].clear();
		edgeDeleted.clear();
		ans.clear();
		vis.clear();
		leaves.clear();
	}
	return(0);
}