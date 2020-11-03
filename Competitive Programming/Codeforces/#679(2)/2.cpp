#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< vector< pair< ll, ll> > > inpp;
vector< vector< ll > > inp;
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
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		vector< pair<ll, ll> > ar;
		vector< ll > ans(n, 0);
		inpp.resize(m, vector< pair<ll, ll> > (n, mp(0, 0)));
		inp.resize(n, vector< ll> (m, 0));
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> inp[i][j];
			}
			ar.pb(mp(inp[i][0], i));
		}
		ll index = 0;
		sort(ar.begin(), ar.end());
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				cin >> inpp[i][j].ff;
				inpp[i][j].ss = j;
			}
			sort(inpp[i].begin(), inpp[i].end());
			bool flag = false;
			for(int j = 0 ; j < n ; j++){
				if( inpp[i][j].ff != ar[j].ff )
					flag = true;
				else
					ans[inpp[i][j].ss] = ar[j].ss; 
			}
			if( !flag )
				index = i;
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++)
				cout << inp[ans[i]][j] << " ";
			cout << endl;
		}
		inp.clear();
		inpp.clear();
	}
	return(0);
}