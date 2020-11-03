#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
bool vis[5003];
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
		cin >> n;
		ari;
		vector< pair< ll, ll> > edge;
		for(int i = 0 ; i < n ; i++)
			vis[i] = false;
		for(int i = 0 ; i < n ; i++){
			if( !vis[i] ){
				int index = n;
				vis[i] = true;
				for(int j = 0 ; j < n ; j++){
					if( a[j] != a[i] ){
						index = j;
						vis[j] = true;
						break;
					}
				}
				if( index != n )
					edge.pb(mp(i, index));
			}
		}
		if( edge.size() < n - 1 )
			cout << "No\n";
		else{
			cout << "Yes\n";			
			for(int i = 0 ; i < n - 1 ; i++)
				cout << edge[i].ff + 1 << " " << edge[i].ss + 1 << "\n";
		}
	}
	return(0);
}