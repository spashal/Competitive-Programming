#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, aa[100005];
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
		ll a, b, c;
		cin >> a >> b >> c;
		ll n1 = 1, n2 = 1;
		for(int i = 0 ; i < a - 1 ; i++){
			n1 *= 10;
		}
		for(int i = 0 ; i < c - 1 ; i++){
			n2 *= 10;
		}
		for(int i = c ; i < b ; i++){
			n2 *= 11;
		}
		cout << n1 << " " << n2 << endl;

	}
	return(0);
}