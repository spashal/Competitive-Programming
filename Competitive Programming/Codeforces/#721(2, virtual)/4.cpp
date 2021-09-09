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
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		map< ll, pair< vector< ll >, vector< ll > > > storage;
		map< ll, bool > included;
		vector< int > nos;
		ari;
		for(int i = 0 ; i < n ; i++){
			if(included[a[i]]){
				storage[a[i]].first.pb(storage[a[i]].first[storage[a[i]].first.size()-1] + i + 1);
				storage[a[i]].second.pb(n-i);
			}
			else{
				included[a[i]] = true;
				nos.pb(a[i]);
				storage[a[i]].first.pb(i+1);
				storage[a[i]].second.pb(n-i);
			}
		}
		ll ans = 0;
		for(int i = 0 ; i < nos.size() ; i++){
			int size = storage[nos[i]].first.size();
			for(int j = 0 ; j < size - 1 ; j++)
				ans += storage[nos[i]].first[j] * storage[nos[i]].second[j+1];
		}
		cout << ans << endl;
	}
	return(0);
}