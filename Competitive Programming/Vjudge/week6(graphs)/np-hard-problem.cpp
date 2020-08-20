#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t;
vector< ll > adj[100005], a[2];
bool clr[100005], inc[100005];
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	bool flag = false;
	ginp;
	for(int i = 1 ; i <= n ; i++){
		if( inc[i] or adj[i].empty() ) continue;
		inc[i] = true;
		clr[i] = false;
        a[0].pb(i);
		queue< pair< ll, ll> > q;
		for(int k = 0 ; k < adj[i].size() ; k++){
			q.push(mp(adj[i][k], 1));
			inc[adj[i][k]] = true;
			clr[adj[i][k]] = true;
            a[1].pb(adj[i][k]);
		}
		while( !q.empty() ){
			int node = q.front().ff;
			int parclr = q.front().ss;
			q.pop();
			for(int j = 0 ; j < adj[node].size() ; j++){
				if( !inc[adj[node][j]] ){
					inc[adj[node][j]] = true;
					clr[adj[node][j]] = 1 - parclr;
					q.push(mp(adj[node][j], 1 - parclr));
                    a[1 - parclr].pb(adj[node][j]);
				}
				else if( clr[adj[node][j]] == clr[node] )
					flag = true;
			}
		}
	}
	if( flag )
		cout << "-1" << endl;
	else{
        cout << (int)a[0].size() << endl;
        for(int i = 0 ; i < a[0].size() ; i++)
            cout << a[0][i] << " ";
        cout << endl << (int)a[1].size()  << endl;
        for(int i = 0 ; i < a[1].size() ; i++)
            cout << a[1][i] << " ";
        cout << endl;
    }
	return(0);
}