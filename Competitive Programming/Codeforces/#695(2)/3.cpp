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
		cin >> n1 >> n2 >> n3;
		for(int i = 0 ; i < n1 ; i++){
			ll ak;
			cin >> ak;
			a1.insert(ak);
		}
		for(int i = 0 ; i < n2 ; i++){
			ll ak;
			cin >> ak;
			a2.insert(ak);
		}
		for(int i = 0 ; i < n3 ; i++){
			ll ak;
			cin >> ak;
			a3.insert(ak);
		}
		while( a1.size() + a2.size() + a3.size() > 1 ){
			if( *a1.crbegin() - min(*a2.cbegin(), *a3.cbegin()) > max(*a2.crbegin(), *a3.crbegin()) - *a1.cbegin() ){
				a
			}
		}
	}
	return(0);
}